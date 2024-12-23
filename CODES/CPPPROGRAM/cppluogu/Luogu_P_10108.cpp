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
    int n, m;
    cin >> n >> m;
    int paths[m];
    for (auto &&i : paths)
    {
        cin >> i;
    }
    sort(paths, paths + m);
    int prices[n];
    for (auto &&i : prices)
    {
        cin >> i;
    }
    int dp[n] = {};
    dp[0] = prices[0];
    for (int i = 0; i < m; i++)
    {
        dp[0 + paths[i]] = prices[0] + prices[0 + paths[i]];
    }
    for (int i = 1; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            int path = paths[j];
            if (i - path >= 0)
            {
                dp[i] = max(dp[i], dp[i - path] + prices[i]);
            }
        }
    }
    cout << dp[n - 1];
}