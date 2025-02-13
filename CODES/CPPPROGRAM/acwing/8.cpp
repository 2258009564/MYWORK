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
    int n, v, m; // 有 N 件物品和一个容量是 V 的背包，背包能承受的最大重量是 M
    cin >> n >> v >> m;

    vector<int> vol(n + 1, 0), wei = vol, val = vol;

    for (int i = 1; i <= n; i++)
    {
        cin >> vol[i] >> wei[i] >> val[i];
    }

    vector dp(v + 1, vector<int>(m + 1, 0));
    // dp[i][j] 容量i 承重j 能放物品的最大价值
    for (int i = 1; i <= n; i++) // 枚举物品
    {
        for (int j = v; j >= vol[i]; j--)
        {
            for (int k = m; k >= wei[i]; k--)
            {
                dp[j][k] = max(dp[j][k], dp[j - vol[i]][k - wei[i]] + val[i]);
            }
        }
    }

    cout << dp[v][m];
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