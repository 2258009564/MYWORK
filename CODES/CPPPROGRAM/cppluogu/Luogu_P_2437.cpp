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
    int m, n;
    cin >> m >> n;
    int dp[n + 1] = {};
    // dp[i]: 爬到i的总共路径

    dp[m] = dp[m + 1] = 1;
    for (int i = m + 2; i <= n; i++)
    {
        dp[i] = dp[i - 1] + dp[i - 2];
    }
    cout << dp[n];
}