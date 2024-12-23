// #pragma GCC optimize(2)
#include <bits/stdc++.h>
using namespace std;
#define int long long
#define endl '\n'

signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int n;
    cin >> n;

    vector<vector<int>> arr(n, vector<int>(n, 0)); // 使用 vector 来存储不规则二维数组

    // 输入三角形数组
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j <= i; j++) // 每行读取 i+1 个元素
        {
            cin >> arr[i][j];
        }
    }

    // 动态规划表，用于存储最大路径和
    vector<vector<int>> dp(n, vector<int>(n, 0));
    dp[0][0] = arr[0][0]; // 起始点

    // 填充动态规划表
    for (int i = 1; i < n; i++)
    {
        dp[i][0] = arr[i][0] + dp[i - 1][0]; // 第一列只能从上方访问
        for (int j = 1; j <= i; j++)         // 其他位置，可以从上方或左上方访问
        {
            dp[i][j] = arr[i][j] + max(dp[i - 1][j], dp[i - 1][j - 1]);
        }
    }

    // 获取最后一行的最大路径和
    int maxnum = LLONG_MIN; // 使用 LLONG_MIN 来表示最小值
    for (int i = 0; i < n; i++)
    {
        maxnum = max(maxnum, dp[n - 1][i]);
    }

    cout << maxnum << endl; // 输出结果
}
