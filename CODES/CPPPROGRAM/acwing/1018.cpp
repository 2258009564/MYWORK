// #pragma GCC optimize(2)
#include <bits/stdc++.h>
using namespace std;
#define int long long
#define endl '\n'

const int INF = 1e9;     // 无穷大
const int INFLL = 1e18;  // 长整型无穷大
const int MOD = 1e9 + 7; // 模数

void solve()
{
    int n;
    cin >> n;
    vector v(n + 1, vector<int>(n + 1));

    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            cin >> v[i][j];
        }
    }

    vector<int> dp(n + 1, INF);
    // dp: dp[i] = min(dp[i - 1], dp[i]) + v[i][j]
    // 如果要求最小值 那么就得初始化成INF

    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            if (i == 1 and j == 1)
            {
                dp[j] = v[i][j];
            }
            else
            {
                dp[j] = min(dp[j - 1], dp[j]) + v[i][j];
            }
        }
    }

    cout << dp[n];
}

signed main()
{
    cin.tie(nullptr)->sync_with_stdio(false);
    int TT = 1;
    // cin >> TT;
    while (TT--)
    {
        solve();
        cout << endl;
    }
}