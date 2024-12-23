#include <bits/stdc++.h>
using namespace std;
#define int long long
#define endl '\n'

signed main()
{
    // 定义变量k，total，total_day
    int k, total = 0, total_day = 0;
    // 输入k
    cin >> k;
    // 定义变量round，初始值为1
    int round = 1;
    // 无限循环
    while (1)
    {
        // 每轮增加的总天数
        total_day += round;
        // 每轮增加的总人数
        total += round * round;
        // 如果总天数大于等于k，输出总人数减去剩余天数乘以每轮人数，结束程序
        if (total_day >= k)
        {
            cout << total - (total_day - k) * round;
            return 0;
        }
        // 每轮人数加1
        round++;
    }
}