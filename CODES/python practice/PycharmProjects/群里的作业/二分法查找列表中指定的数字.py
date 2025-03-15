import matplotlib.pyplot as plt
import numpy as np

plt.rcParams["font.sans-serif"] = ["SimHei"]  # 设置中文字体为黑体
plt.rcParams["axes.unicode_minus"] = False  # 解决负号显示问题

# 数据
data = {
    "x": [0, 5, 10, 20, 30, 40, 50, 60, 70, 80, 90, 100, 110, 120, 130, 140, 150, 160, 170, 180, 190, 200, 210],
    "B": [0.83, 1.11, 1.49, 2.67, 4.03, 4.96, 5.45, 5.69, 5.83, 5.93, 5.94, 5.96, 5.98, 5.98, 5.97, 5.93, 5.88, 5.79, 5.65, 5.3, 4.80, 3.70, 2.30]
}

# 创建图形
plt.figure(figsize=(10, 6))

# 绘制B-X曲线
plt.plot(data["x"], data["B"], marker='o', linestyle='-', color='b', label='B vs X')

# 设置标题和坐标轴标签
plt.title('B vs X Curve', fontsize=16)
plt.xlabel('移动距离 X (mm)', fontsize=12)
plt.ylabel('磁感应强度 B (×10⁻³ T)', fontsize=12)

# 添加网格线
plt.grid(True, linestyle='--', alpha=0.7)

# 显示图例
plt.legend()

# 显示图形
plt.show()
