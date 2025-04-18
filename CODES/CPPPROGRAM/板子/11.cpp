// #pragma GCC optimize(2)
#include <bits/stdc++.h>
using namespace std;
#define int long long
#define endl '\n'
#define all(x) (x).begin(), (x).end()

constexpr int MOD = 1e9 + 7;
// -9.2e18 ~ 9.2e18

void solve()
{
    int n;
    cin >> n;
    vector<int> v(n);
    for (int i = 0; i < n; i++)
    {
        cin >> v[i];
    }

    vector vv(n, vector<int>(n, 0));
    // 把[i, j]区域合并之后得到一个魔法石 该魔法石的最小魔法值
    vector dp(n, vector<int>(n, 0));
    // 合并[i, j]区域消耗的最小代价
    for (int i = 0; i < n; i++)
    {
        vv[i][i] = v[i]; // 初始化 [i, i]区间的石头魔法值 就是自己
    }
    for (int len = 2; len <= n; len++)
    {
        for (int i = 0; i + len - 1 < n; i++)
        {
            int j = i + len - 1;
            vv[i][j] = INT_MAX;
            for (int k = i; k + 1 <= j; k++)
            {
                vv[i][j] = min(vv[i][j], ((vv[i][k] + 1) % MOD * (vv[k + 1][j] + 1) % MOD - 1 + MOD) % MOD); // 这就是给的那个公式 要注意减法取模
            }
        }
    }

    for (int i = 0; i < n; i++)
    {
        dp[i][i] = 0; // 初始化 合并[i, i]不需要代价
    }
    for (int len = 2; len <= n; len++)
    {
        for (int i = 0; i + len - 1 < n; i++)
        {
            int j = i + len - 1;
            dp[i][j] = INT_MAX;
            for (int k = i; k + 1 <= j; k++)
            {
                dp[i][j] = min(dp[i][j], dp[i][k] + dp[k + 1][j] + vv[i][k] + vv[k + 1][j]);
                // dp[i][k] + dp[k + 1][j] 是合并这两个的代价
                // vv[i][k] + vv[k + 1][j] 是 为了合并[i, k] 和 [k + 1, j] 已经付出的代价 也需要算上
            }
        }
    }
    cout << dp[0][n - 1] << ' ' << vv[0][n - 1];
}

signed main()
{
    cin.tie(0)->ios::sync_with_stdio(0);
    cout << setiosflags(ios::fixed) << setprecision(2);
    int TT = 1;
    cin >> TT;
    while (TT--)
    {
        solve();
        cout << endl;
    }
}