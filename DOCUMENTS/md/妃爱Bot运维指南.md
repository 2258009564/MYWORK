# 妃爱 Bot 运维指南

## 基本信息

| 项目 | 值 |
|------|-----|
| Azure VM IP | `20.2.141.105` |
| SSH 用户 | `azureuser` |
| SSH 密钥 | `~/.ssh/azure_vm_key` |
| Bot ID | `870e2bc9eceb@im.bot` |
| 代理端口 | `18012`（内网） |
| WeClaw API | `127.0.0.1:18011`（内网） |
| DeepSeek 模型 | `deepseek-v4-pro` |

---

## 1. SSH 连接

```bash
# 首次使用需确保密钥权限正确
chmod 600 ~/.ssh/azure_vm_key

# 连接 Azure VM
ssh -i ~/.ssh/azure_vm_key azureuser@20.2.141.105
```

---

## 2. 日常操作

### 2.1 检查服务状态

```bash
# 进入 VM
ssh -i ~/.ssh/azure_vm_key azureuser@20.2.141.105

# 查看代理是否运行
ps aux | grep deepseek_proxy | grep -v grep

# 查看 WeClaw 是否运行
ps aux | grep weclaw | grep -v grep
```

### 2.2 查看日志

```bash
# WeClaw 日志（消息收发记录）
tail -50 /tmp/weclaw.log

# 实时监控日志
tail -f /tmp/weclaw.log

# 代理日志
tail -30 /tmp/proxy.log

# 搜索特定内容
grep "agent replied" /tmp/weclaw.log | tail -10   # 查看 AI 回复
grep "received from" /tmp/weclaw.log | tail -10   # 查看收到的消息
grep "ERROR\|error\|failed" /tmp/weclaw.log       # 查看错误
```

### 2.3 重启服务

```bash
# 重启代理（修改代码后）
pkill -f deepseek_proxy.py
sleep 1
nohup python3 /home/azureuser/bin/deepseek_proxy.py > /tmp/proxy.log 2>&1 &

# 重启 WeClaw（修改配置后）
pkill weclaw
sleep 2
nohup /home/azureuser/bin/weclaw start -f > /tmp/weclaw.log 2>&1 &
```

---

## 3. 修改配置

### 3.1 修改人设 Prompt

```bash
# 编辑配置文件
nano /home/azureuser/.weclaw/config.json

# 找到 "system_prompt" 字段，修改内容后保存
# 然后重启 WeClaw
pkill weclaw; sleep 2; nohup /home/azureuser/bin/weclaw start -f > /tmp/weclaw.log 2>&1 &
```

### 3.2 修改代理代码

```bash
# 编辑代理
nano /home/azureuser/bin/deepseek_proxy.py

# 常见可调参数：
# TYPING_DELAY_MIN = 2.0   消息最小间隔（秒）
# TYPING_DELAY_MAX = 4.0   消息最大间隔（秒）
# MSG_DELIMITER = "\n\n"   消息分隔符
# TARGET_USER = "..."      目标用户 ID

# 保存后重启代理
pkill -f deepseek_proxy.py; sleep 1
nohup python3 /home/azureuser/bin/deepseek_proxy.py > /tmp/proxy.log 2>&1 &
```

### 3.3 从 WSL 上传修改后的文件

```bash
# 上传代理
scp -i ~/.ssh/azure_vm_key /home/alisa22580/bin/deepseek_proxy.py azureuser@20.2.141.105:/home/azureuser/bin/

# 上传配置
scp -i ~/.ssh/azure_vm_key config.json azureuser@20.2.141.105:/home/azureuser/.weclaw/
```

---

## 4. 调试

### 4.1 端到端测试（不经过微信）

```bash
ssh -i ~/.ssh/azure_vm_key azureuser@20.2.141.105

# 直接测试代理（模拟 AI 回复）
curl -s -X POST http://127.0.0.1:18012/v1/chat/completions \
  -H "Content-Type: application/json" \
  -d '{"model":"deepseek-v4-pro","messages":[{"role":"user","content":"哥哥今天好累"}]}' \
  | python3 -m json.tool

# 测试 api/send（直接发消息到微信）
curl -s -X POST http://127.0.0.1:18011/api/send \
  -H "Content-Type: application/json" \
  -d '{"to":"o9cq803aHyffQ8EfnZcW_G73-R1Q@im.wechat","text":"测试消息"}'
```

### 4.2 检查 DeepSeek API 是否正常

先通过环境变量提供 API Key，避免把密钥写入命令、文档或 Git 历史：

```bash
export DEEPSEEK_API_KEY="请在本机填写，不要提交到 Git"
```

```bash
curl -s https://api.deepseek.com/v1/chat/completions \
  -H "Content-Type: application/json" \
  -H "Authorization: Bearer ${DEEPSEEK_API_KEY}" \
  -d '{"model":"deepseek-v4-pro","messages":[{"role":"user","content":"hi"}],"max_tokens":10}' \
  | python3 -m json.tool
```

### 4.3 常见问题排查

| 现象 | 检查 |
|------|------|
| bot 不回复 | `tail -30 /tmp/weclaw.log` 看有没有 `All monitors stopped` |
| 回复是长文本不是短句 | AI 没用 `\n\n` 分隔 → 检查 prompt 里的 `[消息格式]` 部分 |
| 回复末尾有多余字符 | 代理返回空给 WeClaw → 检查 `deepseek_proxy.py` 最后返回的内容 |
| 消息间隔太短触发限流 | 增大代理的 `TYPING_DELAY_MIN/MAX` |
| `API error EOF` | 代理挂了 → `pkill -f deepseek_proxy.py && 重启` |
| 想清除对话历史 | `pkill weclaw && rm /home/azureuser/.weclaw/accounts/*.sync.json && 重启` |

### 4.4 查看 AI 实际输出的原始内容

```bash
# 日志里会显示 AI 回复的完整内容
grep "agent replied" /tmp/weclaw.log | tail -5

# 看是否有 \n\n 分隔符
grep "agent replied" /tmp/weclaw.log | tail -1 | grep -o '\\\\n\\\\n' | wc -l
```

---

## 5. 文件清单（Azure VM）

```
/home/azureuser/
├── bin/
│   ├── weclaw                # WeClaw v0.7.1 二进制
│   └── deepseek_proxy.py     # DeepSeek 代理（消息拆分）
└── .weclaw/
    ├── config.json            # 配置文件（prompt + endpoint）
    └── accounts/
        └── 870e2bc9eceb-im-bot.json  # 微信登录凭证

/tmp/
├── weclaw.log        # WeClaw 运行日志
└── proxy.log         # 代理运行日志
```

---

## 6. 网络架构

```
微信 ←→ iLink API ←→ WeClaw(:18011) ←→ 代理(:18012) ←→ DeepSeek API
                              ↕                  ↕
                         weclaw.log       /tmp/proxy.log
```

- WeClaw 主动出站连接 `ilinkai.weixin.qq.com` 和 `api.deepseek.com`
- Azure 网络安全组只需开放 **SSH (22)**
- 所有服务的监听地址都是 `127.0.0.1`，不暴露到公网
