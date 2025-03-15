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
    // 给定体积 要求价值最大化 （最多装m
    int n, m; // n 个物品 背包最大容量是m
    cin >> n >> m;

     vector<int> dp(m + 1, 0);
    for (int i = 1; i <= n; i++) // 枚举物品
    {
        int v1, w1; // 第i个物品的体积，价值
        cin >> v1 >> w1;
        for (int j = m; j >= v1; j--)
        {
            dp[j] = max(dp[j], dp[j - v1] + w1); // 当前的最大价值跟上一个和左上角的有关
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