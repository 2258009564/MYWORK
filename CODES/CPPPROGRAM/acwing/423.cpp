// #pragma GCC optimize(2)
#include <bits/stdc++.h>
using namespace std;
#define int long long
#define endl '\n'

const int INF = 1e9;     // 无穷大
const int INFLL = 1e18;  // 长整型无穷大
const int MOD = 1e9 + 7; // 模数
// -9.2e18 ~ 9.2e18

void solve()
{
    int n, m;
    cin >> n >> m;
    // n 总共容量 m 物品个数
    vector<int> cos(m + 1, 0), val(m + 1, 0), dp(n + 1, 0);
    for (int i = 0; i <= m; i++)
    {
        cin >> cos[i] >> val[i];
    }
    dp[0] = 0;
    for (int i = 1; i <= m; i++) // 枚举物品
    {
        for (int j = n; j >= cos[i]; j--) // 背包容量倒退
        {
            dp[j] = max(dp[j], dp[j - cos[i]] + val[i]);
        }
    }
    cout << dp[n];
}

signed main()
{
    cin.tie(nullptr)->ios::sync_with_stdio(false);
    cout << setiosflags(ios::fixed) << setprecision(2);
    int TT = 1;
    // cin >> TT;
    while (TT--)
    {
        solve();
        cout << endl;
    }
}