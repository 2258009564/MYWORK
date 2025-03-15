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
    有N种物品和一个容量是V的背包。
    第i种物品最多有S,件，每件体积是v,价值是w.
    求解将哪些物品装入背包，可使物品体积总和不超过背包容量，且价值总和最大。
    输出最大价值。
    */

    int n, m;
    cin >> n >> m;
    vector<int> dp(m + 1, 0);
    for (int i = 1; i <= n; i++)
    {
        int k, v, w;
        cin >> v >> w >> k;
        for (int j = m; j >= v; j--)
        {
            for (int kk = 0; kk <= k and kk * v <= j; kk++)
            {
                dp[j] = max(dp[j - kk * v] + kk * w, dp[j]);
            }
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