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
    int a, b, m, n;
    cin >> a >> b >> m >> n;
    int dp[n + 1] = {};
    int total = a + b;
    dp[1] = a, dp[2] = b;
    for (int i = 3; i <= n; i++)
    {
        dp[i] = dp[i - 1] + dp[i - 2];
        total += dp[i];
        if (dp[i] >= m)
        {
            cout << total;
            return 0;
        }
    }
    cout << total;
}