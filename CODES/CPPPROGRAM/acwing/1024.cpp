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
    int v, n; // v 容量 n 个数
    cin >> v >> n;
    vector<int> val(n + 1, 0);
    for (int i = 1; i <= n; i++)
    {
        cin >> val[i];
    }

    vector<int> dp(v + 1, 0);    // dp[i] 容量为i 能装大价值的物品
    for (int i = 1; i <= n; i++) // 枚举物品
    {
        for (int j = v; j >= val[i]; j--)
        {
            dp[j] = max(dp[j], dp[j - val[i]] + val[i]);
        }
    }
    cout << v - dp[v];
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