import math


# 检查数字是否能被某个奇数整除
def is_divisible_by(n, d):
    return n % d == 0


def solve():
    # 读取输入
    n, d = map(int, input().split())

    # 计算阶乘 n!
    factorial_n = math.factorial(n)

    # 生成由数字 d 重复 n! 次的数字
    repeated_number = int(str(d) * factorial_n)

    # 存储结果
    result = []

    # 检查能被 1, 3, 5, 7, 9 整除的数字
    for digit in [1, 3, 5, 7, 9]:
        if is_divisible_by(repeated_number, digit):
            result.append(digit)

    # 输出结果
    print(" ".join(map(str, result)))


# 处理多个测试用例
t = int(input())  # 测试用例数量
for _ in range(t):
    solve()
