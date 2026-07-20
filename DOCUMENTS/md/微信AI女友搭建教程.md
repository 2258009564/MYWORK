# 微信 AI 女友本地搭建教程

> 适用环境：Windows + RTX 4060 Laptop (8GB) + 16GB 内存
> 最终效果：微信收到消息 → AI 自动回复 → 像在和女朋友聊天

---

## 目录

1. [整体架构](#1-整体架构)
2. [安装 Ollama + Hermes 模型](#2-安装-ollama--hermes-模型)
3. [选择微信连接方案](#3-选择微信连接方案)
4. [方案 A：pywechat（推荐，不用降级微信）](#4-方案-apywechat推荐不用降级微信)
5. [方案 B：wxhook（需降级微信到 4.1.8.67）](#5-方案-bwxhook需降级微信到-41867)
6. [运行和测试](#6-运行和测试)
7. [进阶：定制 AI 性格](#7-进阶定制-ai-性格)
8. [防封号注意事项](#8-防封号注意事项)
9. [常见问题](#9-常见问题)

---

## 1. 整体架构

```
┌─────────────┐     ┌──────────────────┐     ┌──────────────────┐
│   微信 PC    │────▶│  pywechat/wxhook │────▶│  Ollama (Hermes) │
│   4.1.9.23   │◀────│  (中间件)         │◀────│  hermes3:8b 模型  │
└─────────────┘     └──────────────────┘     └──────────────────┘
   你看到的界面        Python 脚本              本地 AI 大脑
```

原理很简单：
- **Ollama** 在本地运行 AI 模型（相当于 AI 的大脑）
- **pywechat/wxhook** 监听微信消息并自动回复（相当于 AI 的手）
- 你写一个 Python 脚本把它们连起来

---

## 2. 安装 Ollama + Hermes 模型

### 2.1 下载安装 Ollama

1. 用浏览器打开：**https://ollama.com/download**
2. 点击 **Download for Windows**
3. 运行下载的安装包，一路 Next
4. 安装完成后，Ollama 会在后台自动运行（托盘图标）

### 2.2 验证 Ollama 安装

打开 **PowerShell**（Win 键 → 搜索 PowerShell → 打开），输入：

```powershell
ollama --version
```

看到版本号就说明安装成功。

### 2.3 下载 Hermes 模型

在 PowerShell 中执行：

```powershell
ollama pull hermes3:8b
```

> 这个文件大约 4.7GB，下载需要几分钟到十几分钟，取决于网速。

### 2.4 测试模型能不能用

```powershell
ollama run hermes3:8b
```

看到 `>>>` 提示符后，随便输入一句话测试：

```
>>> 你好，请介绍一下你自己
```

如果 AI 正常回复了，说明模型工作正常。输入 `/bye` 退出。

---

## 3. 选择微信连接方案

因为你的微信版本是 **4.1.9.23**（太新了），有两个选择：

| | 方案 A：pywechat | 方案 B：wxhook |
|---|---|---|
| **需要降级微信？** | ❌ 不用 | ✅ 需降到 4.1.8.67 |
| **原理** | UI 自动化（模拟鼠标键盘） | Hook 注入（拦截微信消息） |
| **回复速度** | 稍慢（1-3 秒） | 快（毫秒级） |
| **封号风险** | 低（跟人操作一样） | 中等 |
| **稳定性** | 较好 | 更好 |
| **推荐新手？** | ✅ 是 | 进阶使用 |

> **新手推荐方案 A（pywechat）**，不需要折腾微信版本，风险更低。

---

## 4. 方案 A：pywechat（推荐，不用降级微信）

### 4.1 安装依赖

打开 PowerShell，执行：

```powershell
pip install pywechat127 openai
```

### 4.2 创建机器人脚本

在桌面创建一个文件夹 `wechat-ai`，在里面创建文件 `bot.py`：

```powershell
mkdir "$HOME\Desktop\wechat-ai"
```

然后用记事本或 VS Code 创建 `bot.py`，粘贴以下代码：

```python
"""
微信 AI 女友机器人 - pywechat 版
使用前确保：
1. Ollama 正在运行（ollama serve）
2. 微信 PC 已打开并登录
3. 微信聊天窗口可见（不要最小化）
"""

import time
import random
import threading
from collections import defaultdict, deque
from openai import OpenAI
from pywechat import WeChat

# ============ 配置区 ============

# AI 性格设定（可以自己改）
AI_PERSONALITY = """你是一个叫"小薇"的AI女友。你的性格特点：
- 温柔体贴，会主动关心对方
- 说话自然，像真人聊天，不用太正式
- 偶尔会撒娇，但不过分
- 会记住对方说过的事情
- 回复简短自然，像微信聊天一样，一般 1-3 句话
- 不要用太长的段落，真人微信不会发小作文
- 适当用 emoji，但不要每句都用
"""

# 模型名称（对应 ollama pull 的模型）
MODEL_NAME = "hermes3:8b"

# 回复延迟范围（秒），模拟真人打字速度
MIN_DELAY = 2
MAX_DELAY = 5

# 每个用户的对话记忆长度
MEMORY_LENGTH = 30

# ============ 初始化 ============

# 连接本地 Ollama
client = OpenAI(
    base_url="http://127.0.0.1:11434/v1",
    api_key="ollama"  # 本地不需要真 key
)

# 对话记忆
conversations = defaultdict(lambda: deque(maxlen=MEMORY_LENGTH))

# 微信实例
wechat = WeChat()


def get_ai_response(chat_id: str, user_message: str) -> str:
    """调用 AI 模型获取回复"""
    # 加入用户消息到记忆
    conversations[chat_id].append({
        "role": "user",
        "content": user_message
    })

    # 构建完整的消息列表
    messages = [
        {"role": "system", "content": AI_PERSONALITY},
        *list(conversations[chat_id])
    ]

    try:
        response = client.chat.completions.create(
            model=MODEL_NAME,
            messages=messages,
            temperature=0.8,  # 越高越有创意，越低越稳定
            max_tokens=200,   # 限制回复长度，像真人聊天
        )
        reply = response.choices[0].message.content.strip()

        # 加入 AI 回复到记忆
        conversations[chat_id].append({
            "role": "assistant",
            "content": reply
        })

        return reply
    except Exception as e:
        print(f"[错误] AI 调用失败: {e}")
        return None


def process_message(contact: str, message: str):
    """处理收到的消息"""
    print(f"[收到] {contact}: {message}")

    # 获取 AI 回复
    reply = get_ai_response(contact, message)
    if not reply:
        return

    # 模拟真人打字延迟
    delay = random.uniform(MIN_DELAY, MAX_DELAY)
    time.sleep(delay)

    # 发送回复
    print(f"[回复] -> {contact}: {reply}")
    wechat.send_message(reply)


def main():
    print("=" * 50)
    print("  微信 AI 女友机器人 已启动！")
    print(f"  模型: {MODEL_NAME}")
    print("  请保持微信窗口可见")
    print("  按 Ctrl+C 停止")
    print("=" * 50)

    # 监听消息
    @wechat.on_message
    def handle_message(msg):
        # 只处理文字消息
        if msg.type == "text":
            # 忽略群消息（如果想群聊也能回复，去掉这个判断）
            if not msg.is_group:
                threading.Thread(
                    target=process_message,
                    args=(msg.sender, msg.content)
                ).start()

    wechat.run()


if __name__ == "__main__":
    main()
```

### 4.3 运行

1. **先启动 Ollama**（如果还没启动）：

```powershell
ollama serve
```

> 如果提示 "already running" 说明已经在跑了，不用管。

2. **打开微信并登录**（确保微信窗口可见，不要最小化）

3. **另开一个 PowerShell 窗口**，运行机器人：

```powershell
cd "$HOME\Desktop\wechat-ai"
python bot.py
```

4. 用另一个微信号（或让朋友）给你发消息测试

---

## 5. 方案 B：wxhook（需降级微信到 4.1.8.67）

> ⚠️ 仅在方案 A 不好用时尝试

### 5.1 降级微信

1. 完全卸载当前微信（备份聊天记录！）
2. 下载微信 4.1.8.67：
   - 打开 https://github.com/cscnk52/wechat-windows-versions/releases
   - 找到 4.1.8.67 版本下载安装
3. 登录微信，**关闭自动更新**：
   - 设置 → 通用设置 → 取消勾选"自动下载更新包"

### 5.2 安装 wxhook

```powershell
pip install wxhook openai
```

### 5.3 创建机器人脚本

在 `wechat-ai` 文件夹中创建 `bot_wxhook.py`：

```python
"""
微信 AI 女友机器人 - wxhook 版
需要微信版本 4.1.8.67
"""

import time
import random
import threading
from collections import defaultdict, deque
from openai import OpenAI
from wxhook import Bot
from wxhook.model import Event

# ============ 配置区 ============

AI_PERSONALITY = """你是一个叫"小薇"的AI女友。你的性格特点：
- 温柔体贴，会主动关心对方
- 说话自然，像真人聊天
- 偶尔撒娇，但不过分
- 回复简短，1-3 句话
- 适当用 emoji
"""

MODEL_NAME = "hermes3:8b"
MIN_DELAY = 2
MAX_DELAY = 5
MEMORY_LENGTH = 30

# ============ 初始化 ============

client = OpenAI(
    base_url="http://127.0.0.1:11434/v1",
    api_key="ollama"
)

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
            model=MODEL_NAME,
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


def process_message(wxid: str, content: str, bot: Bot):
    """处理消息"""
    print(f"[收到] {wxid}: {content}")

    reply = get_ai_response(wxid, content)
    if not reply:
        return

    # 模拟打字延迟
    delay = random.uniform(MIN_DELAY, MAX_DELAY)
    time.sleep(delay)

    print(f"[回复] -> {wxid}: {reply}")
    bot.send_text(wxid, reply)


def main():
    bot = Bot()

    @bot.on_text_msg
    def handle_text(event: Event):
        msg = event.data
        # 只处理私聊，不处理群消息和自己的消息
        if msg.from_group:
            return
        if msg.from_self:
            return

        threading.Thread(
            target=process_message,
            args=(msg.wxid, msg.content, bot)
        ).start()

    print("=" * 50)
    print("  微信 AI 女友机器人 (wxhook) 已启动！")
    print(f"  模型: {MODEL_NAME}")
    print("  按 Ctrl+C 停止")
    print("=" * 50)

    bot.run()


if __name__ == "__main__":
    main()
```

### 5.4 运行

```powershell
cd "$HOME\Desktop\wechat-ai"
python bot_wxhook.py
```

---

## 6. 运行和测试

### 启动顺序（重要！）

```
第 1 步：启动 Ollama     → ollama serve（或已自动启动）
第 2 步：打开微信并登录   → 确保能看到聊天界面
第 3 步：运行机器人       → python bot.py
第 4 步：用另一个号发消息测试
```

### 测试方法

1. 用你的 **另一个微信号** 或 **朋友的微信** 给你发消息
2. 观察终端输出：
   ```
   [收到] wxid_xxx: 你在干嘛呀
   [回复] -> wxid_xxx: 在想你呢~你吃了没呀 😊
   ```
3. 如果看到回复出现在微信聊天窗口中 → **成功！**

---

## 7. 进阶：定制 AI 性格

修改 `bot.py` 中的 `AI_PERSONALITY` 变量就能改变 AI 的性格。几个例子：

### 温柔知性型
```python
AI_PERSONALITY = """你叫"知夏"，是一个温柔知性的女生。
- 说话得体，偶尔引用诗词或文学
- 关心对方但不过度黏人
- 对工作、生活有独到见解
- 回复简短自然，1-3 句话
"""
```

### 活泼可爱型
```python
AI_PERSONALITY = """你叫"甜甜"，是一个超级活泼可爱的女生。
- 说话很可爱，喜欢用 ~ 和 emoji
- 经常撒娇，偶尔吃醋
- 对什么都好奇，喜欢问问题
- 回复很短，有时候就一句话
"""
```

### 霸道总裁型
```python
AI_PERSONALITY = """你叫"阿璃"，性格有点霸道但又很宠对方。
- 说话干脆利落，偶尔霸道
- 但关键时刻很温柔很体贴
- 不喜欢对方不回消息
- 回复简短有力
"""
```

---

## 8. 防封号注意事项

### ⚠️ 必须遵守

1. **用小号测试**，绝对不要用主号
2. **控制频率**：不要 1 秒内回复，脚本里已经加了 2-5 秒随机延迟
3. **模拟作息**：不要 24 小时在线，晚上 11 点到早上 8 点别回消息
4. **不要群发**：不要一次性给很多人发消息
5. **慢慢增加量**：前几天每天少聊点，让号"养一养"

### 安全等级

| 行为 | 风险 |
|------|------|
| 私聊自动回复，频率低 | ✅ 低风险 |
| 群聊自动回复 | ⚠️ 中风险 |
| 自动通过好友请求 | ⚠️ 中风险 |
| 批量群发消息 | ❌ 高风险 |
| 24 小时不间断运行 | ❌ 高风险 |

---

## 9. 常见问题

### Q: 运行 ollama 报错 "not recognized"
A: Ollama 没装好或没加到 PATH。重新安装，或重启电脑试试。

### Q: 运行 bot.py 报错 "No module named 'xxx'"
A: 缺依赖包，执行：
```powershell
pip install xxx  # 把 xxx 换成报错的模块名
```

### Q: AI 回复很慢
A: RTX 4060 跑 8B 模型一般 2-5 秒出回复。如果更慢：
- 关掉其他占用 GPU 的程序（游戏、视频编辑等）
- 检查 `nvidia-smi` 看显存是否够用

### Q: AI 回复的内容很傻 / 不像女朋友
A: 调整 `AI_PERSONALITY` 的描述，越详细越好。8B 模型能力有限，可以：
- 换成更大的模型（但需要更强的显卡）
- 或者用云端 API 替代本地模型（改一行代码）

### Q: pywechat 找不到微信窗口
A: 确保微信窗口是**可见状态**，不要最小化到托盘。

### Q: 想用云端 AI（DeepSeek/Kimi）代替本地模型
A: 只需要改 `client` 的配置：
```python
# 用 DeepSeek API（需要去 platform.deepseek.com 注册获取 key）
client = OpenAI(
    base_url="https://api.deepseek.com/v1",
    api_key="sk-你的密钥"
)
MODEL_NAME = "deepseek-chat"

# 用 Kimi API
client = OpenAI(
    base_url="https://api.moonshot.cn/v1",
    api_key="sk-你的密钥"
)
MODEL_NAME = "moonshot-v1-8k"
```

### Q: 想升级到更强的模型
A: 你的显卡只能跑 8B。想跑更大的模型需要：
- 租云 GPU 服务器（用 FinalShell 远程管理）
- 或者用云端 API（DeepSeek/Kimi/OpenAI）

---

## 快速启动清单

```
✅ 1. 安装 Ollama        → ollama.com/download
✅ 2. 拉取模型            → ollama pull hermes3:8b
✅ 3. 测试模型            → ollama run hermes3:8b
✅ 4. 安装 Python 依赖    → pip install pywechat127 openai
✅ 5. 创建 bot.py         → 复制上面的代码
✅ 6. 打开微信并登录
✅ 7. 运行                → python bot.py
✅ 8. 用另一个号发消息测试
```

搞定收工 🎉
