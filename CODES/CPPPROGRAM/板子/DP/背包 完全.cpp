// #pragma GCC optimize(2)
#include <bits/stdc++.h>
using namespace std;
#define int long long
#define endl '\n'
#define all(x) (x).begin(), (x).end()

const int INF = 1e9;     // 无穷大
const int INFLL = 1e18;  // 长整型无穷大
const int MOD = 1e9 + 7; // 模数
// -9.2e18 ~ 9.2e18

void solve()
{
    /*
    有N种物品和一个容量是V的背包，每种物品都有无限件可用。
    第i种物品的体积是V,价值是W.
    求解将哪些物品装入背包，可使这些物品的总体积不超过背包容量，且总价值最大。
    输出最大价值。
    */

    int n, m; // n 个物品 m是背包最大容量
    cin >> n >> m;
    vector<int> dp(m + 1, 0);
    for (int i = 1; i <= n; i++)
    {
        int v, w;
        cin >> v >> w;
        for (int j = v; j <= m; j++)
        {
            dp[j] = max(dp[j], dp[j - v] + w);
        }
    }
    cout << dp[m];
}

signed main()
{
    cin.tie(0)->ios::sync_with_stdio(0);
    cout << setiosflags(ios::fixed) << setprecision(2);
    int TT = 1;
    // cin >> TT;
    while (TT--)
    {
        solve();
        cout << endl;
    }
}