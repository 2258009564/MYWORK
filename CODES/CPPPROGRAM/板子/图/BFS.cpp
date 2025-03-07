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
    int n, m;
    cin >> n >> m;
    vector v(n, vector<int>(m, 0)), vis = v;

    // bfs

    vector<pair<int, int>> d = {{1, 0}, {0, 1}, {-1, 0}, {0, -1}};

    auto bfs = [&](int i, int j)
    {
        queue<pair<int, int>> q;
        q.push({i, j});
        vis[i][j] = 1;

        while (q.size())
        {
            auto [x, y] = q.front();
            q.pop();

            for (auto &&[dx, dy] : d)
            {
                auto xx = x + dx, yy = y + dy;

                if (xx < 0 or xx >= n or yy < 0 or yy >= m or v[xx][yy] == 1 or vis[xx][yy])
                {
                    continue;
                }

                vis[xx][yy] = 1;
                q.push({xx, yy});
            }
        }
    };
    // bfs end
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