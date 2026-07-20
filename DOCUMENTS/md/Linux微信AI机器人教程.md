# Linux 无头微信 AI 机器人搭建教程

> 目标：在 Linux 服务器上运行微信 AI 机器人，不需要图形界面，24 小时在线
> 适用：完全新手，Windows 电脑 + 租一台便宜 VPS

---

## 📌 先说结论

你的需求 = **Linux 服务器 + 无图形界面 + 24小时在线 + AI 自动回复**

最佳方案：

```
你的 Windows 电脑（FinalShell）
        │
        │ SSH 远程管理
        ▼
┌─────────────────────────────────────────┐
│  香港 VPS 服务器（Linux）                │
│                                         │
│  ┌─────────────┐   ┌────────────────┐  │
│  │ Gewechat    │──▶│ AI 后端         │  │
│  │ (微信连接)  │   │ (云端API/本地)  │  │
│  └─────────────┘   └────────────────┘  │
│       ▲                                 │
│       │ iPad 协议登录                    │
│       │ (扫二维码，之后全自动)            │
│  ─────┼──────────────────────────────── │
│       │                                 │
│  微信服务器 ◀──── 腾讯云端 ◀───────     │
└─────────────────────────────────────────┘
```

---

## 目录

1. [方案对比](#1-方案对比选哪个)
2. [准备工作：租 VPS](#2-准备工作租一台-vps)
3. [安装 FinalShell](#3-安装-finalshell)
4. [方案 A：Gewechat + 云端 AI（推荐）](#4-方案-agewechat--云端-ai推荐)
5. [方案 B：WeClaw 官方协议（最安全）](#5-方案-bweclaw-官方协议最安全)
6. [养号指南](#6-养号指南非常重要)
7. [AI 性格定制](#7-ai-性格定制)
8. [常见问题](#8-常见问题)

---

## 1. 方案对比（选哪个）

| | 方案 A：Gewechat | 方案 B：WeClaw (iLink) |
|---|---|---|
| **原理** | iPad 协议登录微信 | 腾讯官方 iLink 协议 |
| **需要微信窗口？** | ❌ 不需要 | ❌ 不需要 |
| **封号风险** | ⚠️ 中低 | ✅ 几乎为零（官方） |
| **支持群聊** | ✅ 支持 | ❌ 仅 1v1 私聊 |
| **完全免费** | ✅ 是 | ✅ 是 |
| **成熟度** | ⭐⭐⭐⭐⭐ 最成熟 | ⭐⭐⭐ 较新（2026.3 发布） |
| **适合新手** | ⭐⭐⭐⭐ | ⭐⭐⭐⭐⭐ 最简单 |
| **维护状态** | ⚠️ 社区维护中 | ✅ 官方活跃开发 |
| **推荐度** | 功能最全 | 最安全最简单 |

> **新手推荐：先试方案 B（WeClaw）**，因为最安全、最简单。
> 如果你需要群聊等更多功能，再换方案 A（Gewechat）。

---

## 2. 准备工作：租一台 VPS

### 为什么需要 VPS？

因为你要 24 小时在线（养号），你的笔记本不可能一直开着。VPS = 云上的一台电脑，永远不关机。

### 选什么 VPS？

**推荐：香港节点**（不需要备案，延迟低）

| VPS 厂商 | 配置 | 价格 | 推荐理由 |
|----------|------|------|---------|
| **腾讯云轻量（香港）** | 2核4G | ¥50-100/年（新用户） | 腾讯自家，微信兼容最好 |
| **阿里云（香港）** | 2核2G | ¥68/年（新用户） | 稳定 |
| **RackNerd** | 2核4G | $10-20/年 | 便宜但延迟稍高 |

> ⚠️ **不要选美国/日本/新加坡节点**，延迟太高，微信可能异常。
> **香港节点**是最佳选择：延迟 30-60ms，不需要备案。

### 系统选择

安装 **Ubuntu 22.04 LTS**（最通用，教程最多）

### 购买流程（以腾讯云为例）

1. 打开 https://cloud.tencent.com/
2. 注册账号（微信扫码即可）
3. 产品 → 轻量应用服务器 → 地域选"香港"
4. 配置选 2核4G 就够
5. 系统选 Ubuntu 22.04
6. 付款，等待开通（通常 1-3 分钟）
7. 拿到：**服务器 IP + 密码**

---

## 3. 安装 FinalShell

FinalShell 是你管理 VPS 的工具（SSH 客户端）。

### 3.1 下载安装

1. 打开 https://www.hostbuf.com/t/988.html
2. 下载 Windows 版
3. 安装（一路 Next）

### 3.2 连接服务器

1. 打开 FinalShell
2. 点击左上角 **"+"** 新建连接
3. 填写：
   ```
   名称：     我的微信机器人
   主机：     你的VPS公网IP（如 43.xxx.xxx.xxx）
   端口：     22
   用户名：   root
   密码：     你的VPS密码
   ```
4. 点击 **确定**
5. 双击连接 → 看到终端出现 `root@xxx:~#` 就说明连上了

> 🎉 从现在开始，所有操作都在 FinalShell 终端里完成。

---

## 4. 方案 A：Gewechat + 云端 AI（推荐）

### 4.1 安装 Docker

在 FinalShell 终端中依次执行：

```bash
# 更新系统
apt update && apt upgrade -y

# 安装 Docker
curl -fsSL https://get.docker.com | sh

# 设置开机自启
systemctl enable docker && systemctl start docker

# 验证安装
docker --version
```

看到版本号就说明 Docker 装好了。

### 4.2 部署 Gewechat

```bash
# 创建数据目录
mkdir -p /root/gewechat/data

# 启动 Gewechat 容器
docker run -itd \
  --name=gewe \
  --restart=always \
  -v /root/gewechat/data:/root/temp \
  -p 2531:2531 \
  -p 2532:2532 \
  --privileged=true \
  registry.cn-hangzhou.aliyuncs.com/gewe/gewe:latest \
  /usr/sbin/init

# 检查是否启动成功
docker ps
```

看到 `gewe` 容器状态为 `Up` 就 OK。

### 4.3 获取登录二维码

```bash
# 调用 API 获取二维码
curl -X POST http://127.0.0.1:2531/v2/api/login/new_get_qr \
  -H "Content-Type: application/json" \
  -d '{"proxy_ip":""}'
```

返回结果里会有一串 base64 图片数据或二维码链接：
- 如果返回了二维码图片链接，在浏览器打开
- 用你的 **微信小号** 扫码登录
- 登录成功后，Gewechat 就一直保持在线了

### 4.4 安装 Python 环境

```bash
# 安装 Python 3 和 pip
apt install -y python3 python3-pip

# 安装依赖
pip3 install gewechat-client openai
```

### 4.5 创建机器人脚本

```bash
# 创建项目目录
mkdir -p /root/wechat-bot && cd /root/wechat-bot
```

创建 `bot.py`：

```bash
cat > /root/wechat-bot/bot.py << 'PYTHON_SCRIPT'
"""
微信 AI 女友机器人 - Gewechat Linux 版
运行环境：VPS (Ubuntu) + Gewechat + 云端 AI API
"""

import time
import random
import json
import threading
import requests
from collections import defaultdict, deque
from openai import OpenAI

# ============ 配置区（根据你的情况修改） ============

# AI 性格设定
AI_PERSONALITY = """你是一个叫"小薇"的AI女友。你的性格特点：
- 温柔体贴，会主动关心对方
- 说话自然，像真人聊天
- 偶尔撒娇，但不过分
- 回复简短自然，1-3 句话
- 适当用 emoji
- 不要发长段落，真人微信不写小作文
"""

# ---- 选一种 AI 后端 ----

# 选项 1：DeepSeek API（推荐，便宜好用，约 ¥1/百万 token）
AI_BACKEND = "deepseek"
DEEPSEEK_API_KEY = "sk-你的deepseek密钥"  # 去 platform.deepseek.com 注册获取

# 选项 2：Kimi API
# AI_BACKEND = "kimi"
# KIMI_API_KEY = "sk-你的kimi密钥"

# 选项 3：本地 Ollama（需要在 VPS 上装 Ollama，4GB 显存以上的 VPS）
# AI_BACKEND = "ollama"

# ---- Gewechat 配置 ----
GEWE_API = "http://127.0.0.1:2531/v2/api"
GEWE_FILE_API = "http://127.0.0.1:2532/download"
APP_ID = "wx_bot_001"  # 随便取一个名字

# ---- 回复设置 ----
MIN_DELAY = 2   # 最短回复延迟（秒）
MAX_DELAY = 5   # 最长回复延迟（秒）
MEMORY_LENGTH = 30  # 对话记忆条数

# ============ 初始化 ============

# 根据 AI 后端选择配置
if AI_BACKEND == "deepseek":
    client = OpenAI(
        base_url="https://api.deepseek.com/v1",
        api_key=DEEPSEEK_API_KEY
    )
    model_name = "deepseek-chat"
elif AI_BACKEND == "kimi":
    client = OpenAI(
        base_url="https://api.moonshot.cn/v1",
        api_key=KIMI_API_KEY
    )
    model_name = "moonshot-v1-8k"
elif AI_BACKEND == "ollama":
    client = OpenAI(
        base_url="http://127.0.0.1:11434/v1",
        api_key="ollama"
    )
    model_name = "hermes3:8b"
else:
    raise ValueError(f"未知 AI 后端: {AI_BACKEND}")

# 对话记忆
conversations = defaultdict(lambda: deque(maxlen=MEMORY_LENGTH))


def get_ai_response(chat_id: str, user_message: str) -> str:
    """调用 AI 获取回复"""
    conversations[chat_id].append({
        "role": "user",
        "content": user_message
    })

    messages = [
        {"role": "system", "content": AI_PERSONALITY},
        *list(conversations[chat_id])
    ]

    try:
        response = client.chat.completions.create(
            model=model_name,
            messages=messages,
            temperature=0.8,
            max_tokens=200,
        )
        reply = response.choices[0].message.content.strip()
        conversations[chat_id].append({
            "role": "assistant",
            "content": reply
        })
        return reply
    except Exception as e:
        print(f"[错误] AI 调用失败: {e}")
        return None


def send_text(to_wxid: str, content: str):
    """通过 Gewechat 发送文字消息"""
    url = f"{GEWE_API}/send_text"
    payload = {
        "to_wxid": to_wxid,
        "content": content,
        "app_id": APP_ID
    }
    try:
        resp = requests.post(url, json=payload)
        result = resp.json()
        if result.get("ret") == 200:
            print(f"  ✓ 发送成功")
        else:
            print(f"  ✗ 发送失败: {result}")
    except Exception as e:
        print(f"  ✗ 发送异常: {e}")


def process_message(wxid: str, content: str, is_group: bool = False):
    """处理收到的消息"""
    if is_group:
        return  # 先不处理群消息，以后可以开放

    print(f"[收到] {wxid}: {content}")

    reply = get_ai_response(wxid, content)
    if not reply:
        return

    # 模拟真人打字延迟
    delay = random.uniform(MIN_DELAY, MAX_DELAY)
    time.sleep(delay)

    print(f"[回复] -> {wxid}: {reply}")
    send_text(wxid, reply)


def get_callback_msg():
    """从 Gewechat 获取消息（轮询方式）"""
    url = f"{GEWE_API}/get_callback_msg"
    try:
        resp = requests.post(url, json={"app_id": APP_ID})
        result = resp.json()
        return result.get("data", [])
    except Exception as e:
        print(f"[错误] 获取消息失败: {e}")
        return []


def main():
    print("=" * 50)
    print("  微信 AI 女友机器人 (Linux版)")
    print(f"  AI 后端: {AI_BACKEND} ({model_name})")
    print(f"  Gewechat API: {GEWE_API}")
    print("  按 Ctrl+C 停止")
    print("=" * 50)

    # 先检查 Gewechat 是否在运行
    try:
        resp = requests.post(f"{GEWE_API}/check_online", json={"app_id": APP_ID})
        print(f"  Gewechat 状态: {resp.json()}")
    except:
        print("  ⚠ Gewechat 未响应，请确认容器在运行")

    print("\n开始监听消息...\n")

    while True:
        try:
            messages = get_callback_msg()
            for msg in messages:
                if not msg:
                    continue

                msg_type = msg.get("type", "")
                content = msg.get("content", "")
                from_wxid = msg.get("from_wxid", "")
                from_group = msg.get("from_group", False)

                # 只处理文字消息
                if msg_type == "text" or msg_type == 1:
                    threading.Thread(
                        target=process_message,
                        args=(from_wxid, content, from_group)
                    ).start()

            time.sleep(1)  # 每秒检查一次

        except KeyboardInterrupt:
            print("\n机器人已停止")
            break
        except Exception as e:
            print(f"[错误] {e}")
            time.sleep(5)


if __name__ == "__main__":
    main()
PYTHON_SCRIPT
```

### 4.6 配置 AI 后端

**推荐用 DeepSeek API**（比本地模型便宜，回复质量更高）：

1. 打开 https://platform.deepseek.com/
2. 注册账号（手机号即可）
3. 充值 ¥10（够用很久）
4. 左侧菜单 → API Keys → 创建一个 Key
5. 复制 Key，替换脚本中的 `sk-你的deepseek密钥`

### 4.7 运行

```bash
cd /root/wechat-bot
python3 bot.py
```

看到 "开始监听消息..." 就说明在运行了。

### 4.8 设置开机自启

```bash
# 创建 systemd 服务
cat > /etc/systemd/system/wechat-bot.service << EOF
[Unit]
Description=WeChat AI Bot
After=network.target docker.service

[Service]
Type=simple
WorkingDirectory=/root/wechat-bot
ExecStart=/usr/bin/python3 /root/wechat-bot/bot.py
Restart=always
RestartSec=10

[Install]
WantedBy=multi-user.target
EOF

# 启用并启动
systemctl enable wechat-bot
systemctl start wechat-bot

# 查看状态
systemctl status wechat-bot

# 查看日志
journalctl -u wechat-bot -f
```

---

## 5. 方案 B：WeClaw 官方协议（最安全）

> 2026 年 3 月腾讯发布了 iLink 协议，WeClaw 是基于此的开源工具。

### 5.1 安装 WeClaw

```bash
# 一键安装
curl -sSL https://raw.githubusercontent.com/fastclaw-ai/weclaw/main/install.sh | sh

# 验证
weclaw --version
```

### 5.2 配置 AI 后端

WeClaw 支持 HTTP 模式连接任意 AI 后端。

```bash
# 创建配置文件
mkdir -p ~/.weclaw
cat > ~/.weclaw/config.json << EOF
{
  "default_agent": "deepseek",
  "agents": {
    "deepseek": {
      "type": "http",
      "url": "https://api.deepseek.com/v1/chat/completions",
      "headers": {
        "Authorization": "Bearer sk-你的deepseek密钥",
        "Content-Type": "application/json"
      },
      "body_template": {
        "model": "deepseek-chat",
        "messages": [
          {"role": "system", "content": "你是一个叫小薇的AI女友。温柔体贴，说话自然，回复简短。"},
          {"role": "user", "content": "{{input}}"}
        ],
        "temperature": 0.8,
        "max_tokens": 200
      }
    }
  }
}
EOF
```

### 5.3 启动

```bash
weclaw start
```

终端会显示二维码，用微信扫码登录。之后全自动。

### 5.4 设为系统服务

```bash
# 设置开机自启
weclaw service install
```

---


## 6. 养号指南（非常重要）

### ⚠️ 新号必读

微信对新设备登录非常敏感，以下规则必须遵守：

### 第一阶段：前 72 小时（最危险）

```
✅ 每天保持在线 ≥ 4 小时
✅ 只做人工操作，不要开机器人
✅ 和 3-5 个老号聊天（早中晚各一次）
✅ 发 1-3 条朋友圈
❌ 不要加陌生人
❌ 不要发广告/链接
❌ 不要频繁修改个人信息
```

### 第二阶段：第 4-7 天

```
✅ 每天加 3-5 个好友
✅ 加入 3-5 个活跃群
✅ 每天聊天互动
❌ 不要群发消息
❌ 不要用摇一摇/附近的人
```

### 第三阶段：第 8-30 天

```
✅ 可以开始低调使用机器人
✅ 回复延迟设置长一点（3-8 秒）
✅ 不要 24 小时秒回
✅ 晚上设个"睡觉时间"（11pm-8am 不自动回复）
```

### 第四阶段：30 天后

```
✅ 账号基本稳定
✅ 可以正常使用机器人
⚠️ 仍然不要做营销行为
```

### 八大禁忌

| 编号 | 禁忌 | 后果 |
|------|------|------|
| 1 | 用虚拟号段（170/171/165）注册 | 直接封号 |
| 2 | 异地登录（IP 和注册地不同省） | 触发安全验证 |
| 3 | 一台设备登录多个微信号 | 关联封号 |
| 4 | 频繁加人/被加 | 限制加人功能 |
| 5 | 群发广告/营销内容 | 封号 |
| 6 | 1 秒内自动回复 | 判定为机器人 |
| 7 | 24 小时不停歇发消息 | 异常行为检测 |
| 8 | 用新号直接开机器人 | 72 小时内封号 |

### VPS 选择对养号的影响

```
✅ 香港节点 → 延迟 30-60ms，风险低
⚠️ 国内节点 → 延迟 <30ms，但需要备案
❌ 海外节点 → 延迟 >100ms，高风险
❌ 频繁换 IP → 每次换 IP 等于重新登录
```

---

## 7. AI 性格定制

修改脚本中的 `AI_PERSONALITY` 变量。几个模板：

### 温柔女友型
```
你叫"小薇"，是一个温柔可爱的女生。
- 说话温柔，会关心对方的日常生活
- 偶尔撒娇，会吃醋
- 回复简短自然，1-3 句话
- 适当用 emoji，但不要每句都用
- 真人微信不会写小作文
```

### 知性女友型
```
你叫"知夏"，是一个知性优雅的女生。
- 说话得体有内涵
- 对工作和生活有独到见解
- 会引用诗词或有趣的知识
- 不过度黏人，有自己的空间感
- 回复简练，一语中的
```

### 傲娇女友型
```
你叫"阿璃"，是一个有点傲娇的女生。
- 表面不在乎，其实很关心对方
- 偶尔嘴硬说反话
- 关键时刻会突然很温柔
- 生气了会用"哼"、"不理你了"
- 回复一般很短，偶尔突然发一大段关心的话
```

---

## 8. 常见问题

### Q: VPS 上能跑 Ollama 本地模型吗？
A: 普通便宜 VPS 没有显卡，跑不了。要跑本地模型需要 GPU VPS（每月几百块）。
**推荐：用 DeepSeek API**（¥1/百万 token），比租 GPU 便宜 100 倍。

### Q: Gewechat 登录失败怎么办？
A: 
1. 确认 VPS 是香港或国内节点
2. 用手机微信先在 VPS IP 附近登录一次（养号）
3. 换一个老号（注册 > 6 个月）试试
4. 不要用虚拟号段注册的号

### Q: 机器人突然不回复了？
A:
```bash
# 检查 Gewechat 状态
docker ps

# 如果容器挂了，重启
docker restart gewe

# 检查机器人服务状态
systemctl status wechat-bot

# 查看日志
journalctl -u wechat-bot -n 50
```

### Q: 想同时在手机上用微信怎么办？
A: Gewechat 登录后，手机上微信仍然可以正常使用。
但注意：手机退出微信登录后，Gewechat 也会断开。

### Q: 一台 VPS 能跑多个微信号吗？
A: 可以，但**不推荐**。一台设备多个微信号会增加封号风险。
如果必须多号，用不同的 VPS。

### Q: FinalShell 连不上服务器？
A:
1. 检查 IP 和密码是否正确
2. VPS 控制台确认服务器在运行
3. 检查安全组/防火墙是否开放 22 端口
4. 有些 VPS 需要先在网页端重置密码

### Q: 一个月大概花多少钱？
A:
```
VPS 服务器：¥50-100/年（新用户优惠）
DeepSeek API：¥5-20/月（看聊天量）
域名（可选）：¥10-50/年
────────────────────
总计：约 ¥10-30/月
```

### Q: WeClaw 和 Gewechat 能同时用吗？
A: 不建议。一个微信号只能在一个平台登录。选一个用就行。

### Q: 以后想换成 ChatGPT 或 Claude？
A: 只需要改脚本里的 API 配置：
```python
# ChatGPT
client = OpenAI(
    base_url="https://api.openai.com/v1",
    api_key="sk-你的openai密钥"
)
model_name = "gpt-4o-mini"

# Claude
# 需要使用兼容 OpenAI 格式的代理
```

---

## 🚀 快速启动清单

```
第 1 步：租一台香港 VPS（Ubuntu 22.04）
         → 腾讯云/阿里云，2核4G 就够

第 2 步：安装 FinalShell
         → hostbuf.com 下载安装
         → 用 IP + 密码连接服务器

第 3 步：部署 Gewechat
         → 复制 docker run 命令
         → 获取二维码扫码登录

第 4 步：注册 DeepSeek API
         → platform.deepseek.com
         → 充值 ¥10，复制 API Key

第 5 步：创建机器人脚本
         → 复制 bot.py 代码
         → 填入 API Key

第 6 步：运行
         → python3 bot.py

第 7 步：测试
         → 用另一个微信号发消息
         → 看到自动回复 = 成功！🎉

第 8 步：养号
         → 前 72 小时不要开机器人
         → 慢慢来，别急
```

---

## 📚 重要链接

| 资源 | 地址 |
|------|------|
| Gewechat | https://github.com/Devo919/Gewechat |
| WeClaw (iLink) | https://github.com/fastclaw-ai/weclaw |
| FinalShell | https://www.hostbuf.com/t/988.html |
| DeepSeek API | https://platform.deepseek.com |
| Kimi API | https://platform.moonshot.cn |
| 腾讯云 | https://cloud.tencent.com |
| 阿里云 | https://www.aliyun.com |
