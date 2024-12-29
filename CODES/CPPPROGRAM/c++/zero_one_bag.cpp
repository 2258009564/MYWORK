#include <bits/stdc++.h>
using namespace std;

int main()
{
    // 01背包
    // dp的含义：dp[i][j]表示当前背包容量为j 从0~i中任取的最大价值
    /*
    状态转移方程：
    dp[i][j]=
    1 不拿i 那么就是dp[i-1][j]
    2 拿i 那么就要在背包里腾出i的位置
    记i的重量为weight[i],i的价值为value[i]
    那么有 此时的价值为 dp[i-1][j-weight[i]]+value[i]
    综合以上 状态转移：
    dp[i][j]=max(dp[i-1][j],dp[i-1][j-weight[i]]+value[i])
    */
    // 初始化
    int m, n;
    cin >> m >> n;
    vector<int> weight(m), value(m);
    for (auto &num : weight)
    {
        cin >> num;
    }
    for (auto &num : value)
    {
        cin >> num;
    }
    vector<vector<int>> dp(m, vector<int>(n + 1, 0));
    // m行n列
    for (int i = weight[0]; i <= n; i++)
    { // dp[0][i]表示的是价值 所以都是第一件的价值
        dp[0][i] = value[0];
    }

    for (int i = 1; i < m; i++)
    { // m是行 说的是行李箱的每一个物品
        for (int j = 0; j <= n; j++)
        { // n是列 说的是行李箱的容量
            if (
                // 装不下 就继承上一个的价值
                j < weight[i])
            {
                dp[i][j] = dp[i - 1][j];
                // 注意 上一个的价值是i-1
            }
            else
            {
                dp[i][j] = max(dp[i - 1][j], dp[i - 1][j - weight[i]] + value[i]);
            }
        }
    }
    cout << dp[m - 1][n];
}