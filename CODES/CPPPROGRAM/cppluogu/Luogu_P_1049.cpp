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
    int v, n;
    cin >> v >> n;
    int value[n];
    for (auto &&i : value)
    {
        cin >> i;
    }
    int dp[v + 1] = {};
    for (int i = 0; i < n; i++)
    {
        for (int j = v; j >= value[i]; j--)
        {
            dp[j] = max(dp[j], dp[j - value[i]] + value[i]);
        }
    }
    cout << v - dp[v];
}