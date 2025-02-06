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
    int n, m;
    cin >> n >> m;

    vector v(n + 1, vector<int>(m + 1, 0));
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
        {
            cin >> v[i][j];
        }
    }

    vector dp(n + 1, vector(m + 1, vector(n + 1, vector<int>(m + 1, 0))));

    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
        {

            for (int k = 1; k <= n; k++)
            {
                for (int l = 1; l <= m; l++)
                {
                    if (i + j == k + l)
                    {
                        dp[i][j][k][l] = max({dp[i - 1][j][k - 1][l], dp[i - 1][j][k][l - 1], dp[i][j - 1][k - 1][l], dp[i][j - 1][k][l - 1]}) + v[i][j] + (i != k ? v[k][l] : 0);
                    }
                }
            }
        }
    }

    cout << dp[n][m][n][m];
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