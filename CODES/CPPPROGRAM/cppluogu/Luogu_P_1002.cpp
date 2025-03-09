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
    int n, m, bx, by;
    cin >> n >> m >> bx >> by;

    vector v(n + 1, vector<int>(m + 1, 0)), dp = v;

    vector<pair<int, int>> d = {{0, 0}, {1, 2}, {-1, 2}, {-1, -2}, {1, -2}, {2, 1}, {-2, 1}, {-2, -1}, {2, -1}};

    for (auto &&[dx, dy] : d)
    {
        auto x = dx + bx, y = by + dy;

        if (x < 0 or x > n or y < 0 or y > m)
        {
            continue;
        }

        v[x][y] = 1;
    }

    if (v[0][0] or v[n][m])
    {
        cout << 0;
        return;
    }

    dp[0][0] = 1;
    for (int i = 1; i <= n; i++)
    {
        if (v[i][0])
        {
            continue;
        }
        dp[i][0] = dp[i - 1][0];
    }

    for (int j = 1; j <= m; j++)
    {
        if (v[0][j])
        {
            continue;
        }

        dp[0][j] = dp[0][j - 1];
    }

    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
        {
            if (v[i][j])
            {
                continue;
            }

            dp[i][j] = dp[i - 1][j] + dp[i][j - 1];
        }
    }
    cout << dp[n][m];
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