#include <bits/stdc++.h>
using namespace std;

#define int long long // 使用 long long 类型防止溢出
#define endl '\n'

signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    int r;
    while (cin >> r)
    {
        if (r == 0)
        {
            break; // 读到0时退出
        }

        int total = 0;

        // 遍历每个x值
        for (int x = 0; x <= r; ++x)
        {
            // 计算 y 的最大值，使得 x^2 + y^2 <= r^2
            int max_y = sqrt(r * r - x * x); // y最大值

            // 遍历每个可能的y值
            for (int y = 0; y <= max_y; ++y)
            {
                if (x == 0 || y == 0)
                {
                    total += 1; // 坐标轴上的点只计算一次
                }
                else
                {
                    total += 4; // 其他点的四个象限都计算
                }
            }
        }

        cout << total << endl;
    }
    return 0;
}
