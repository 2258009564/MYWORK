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
    有个体积和价值分别为v,w的物品，现从这些物品中挑选出总体积恰好为m的物品，求所有方案中价值总和的最大值。
    */

    /*
    恰好装满：
    ·求最大值时，除了0为0，其他都初始化为无穷小
    -0x3f3f3f3f
    ·求最小值时，除了0为0，其他都初始化为无穷大
    0x3f3f3f3f
    不必恰好装满：
    全初始化为0
    */

    int n, m;
    cin >> n >> m;
    vector<int> dp(m + 1, -0x3f3f3f);
    dp[0] = 0;
    for (int i = 1; i <= n; i++)
    {
        int v, w;
        cin >> v >> w;

        for (int j = m; j >= v; j--)
        {
            dp[j] = max(dp[j], dp[j - v] + w);
        }
    }
    cout << max(-1ll, dp[m]);
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