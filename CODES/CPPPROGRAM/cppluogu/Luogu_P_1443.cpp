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
    int n, m, x, y;
    cin >> n >> m >> x >> y;
    x--, y--;
    vector v(n, vector<int>(m, -1)), vis(n, vector<int>(m, 0));
    vector<pair<int, int>> d = {{1, 2}, {-1, 2}, {-1, -2}, {1, -2}, {2, 1}, {-2, 1}, {-2, -1}, {2, -1}};
    v[x][y] = 0;


    auto bfs = [&]() -> void
    {
        queue<pair<int, int>> q;
        q.push({x, y});
        vis[x][y] = 1;

        while (q.size())
        {
            auto [x, y] = q.front();
            q.pop();

            for (auto &&[dx, dy] : d)
            {
                auto xx = x + dx, yy = y + dy;

                if (xx < 0 or xx >= n or yy < 0 or yy >= m or vis[xx][yy])
                {
                    continue;
                }

                v[xx][yy] = v[x][y] + 1;
                vis[xx][yy] = 1;
                q.push({xx, yy});
            }
        }
    };

    bfs();

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cout << v[i][j] << ' ';
        }
        cout << endl;
    }
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