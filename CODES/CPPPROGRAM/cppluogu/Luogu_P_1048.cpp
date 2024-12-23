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
    int t, m;
    cin >> t >> m;
    int times[m], values[m];
    for (int i = 0; i < m; i++)
    {
        cin >> times[i] >> values[i];
    }
    int dp[t + 1] = {};
    // dp[i]: 用时i能取得的最大价值
    for (int i = 0; i < m; i++)
    {
        for (int j = t; j >= times[i]; j--)
        {
            dp[j] = max(dp[j], dp[j - times[i]] + values[i]);
        }
    }
    cout << dp[t];
}