import math
import random


def triangle_area(a_side, b_side, c_side):
    p = (a_side + b_side + c_side) / 2
    return math.sqrt(p * (p - a_side) * (p - b_side) * (p - c_side))  # 海伦公式


for i in range(1, 26):
    a, b, c = random.randint(1, 9), random.randint(1, 9), random.randint(1, 9)
    if a + b > c and a + c > b and b + c > a:
        print(f'第{i}组：a={a}, b={b}, c={c}，面积为：{triangle_area(a, b, c)}')
    else:
        print(f'第{i}组：a={a}, b={b}, c={c}，不能构成三角形')
