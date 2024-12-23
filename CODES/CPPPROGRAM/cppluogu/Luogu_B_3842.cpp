// #pragma GCC optimize(2)
#include <bits/stdc++.h>
using namespace std;
#define int long long
#define endl '\n'

signed main()
{
    // 关闭同步，提高输入输出效率
    ios::sync_with_stdio(false);
    // 解除cin与cout的绑定，提高输入输出效率
    cin.tie(0);
    cout.tie(0);
    int n, m;
    // 输入n和m
    cin >> n >> m;
    int come[n] = {};
    // 初始化come数组，用于记录每个数字出现的次数
    bool foundmeilaide = 0;
    // 循环m次，输入每个数字
    while (m--)
    {
        int num;
        cin >> num;
        come[num]++;
    }
    // 遍历come数组，查找没有出现的数字
    for (int i = 0; i < n; i++)
    {
        if (!come[i])
        {
            // 输出没有出现的数字
            cout << i << ' ';
            foundmeilaide = 1;
        }
    }
    // 如果没有找到没有出现的数字，输出n
    if (!foundmeilaide)
    {
        cout << n;
    }
}