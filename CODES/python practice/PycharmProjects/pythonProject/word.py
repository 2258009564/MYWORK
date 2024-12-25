import math


# 检查数字是否能被某个奇数整除
def is_divisible_by(n, d):
    return n % d == 0


def solve():
    # 读取输入
    n, d = map(int, input().split())

    # 计算阶乘 n!
    factorial_n = math.factorial(n)

    # 获取 n! 的最后一位
    last_digit_of_factorial = factorial_n % 10
    last_digit_of_factorial *= d

    # 存储结果
    result = []

    # 检查能否被 1, 3, 5, 7, 9 整除的奇数
    for digit in [1, 3, 5, 7, 9]:
        if is_divisible_by(factorial_n, digit):
            result.append(digit)

    # 输出结果
    print(" ".join(map(str, result)))


# 处理多个测试用例
t = int(input())  # 测试用例数量
for _ in range(t):
    solve()
