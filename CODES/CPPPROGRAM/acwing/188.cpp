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
    int m, n;
    cin >> m >> n;
    vector v(n, vector<char>(m));
    vector dist(n, vector<int>(m, -1));
    pair<int, int> curpr;

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cin >> v[i][j];
            if (v[i][j] == 'K')
            {
                curpr = {i, j};
            }
        }
    }

    auto bfs = [&]() -> void
    {
        vector<pair<int, int>> d = {{1, 2}, {2, 1}, {-1, 2}, {2, -1}, {-1, -2}, {-2, -1}, {1, -2}, {-2, 1}};

        queue<pair<int, int>> q;

        auto [i, j] = curpr;
        dist[i][j] = 0;
        q.push(curpr);

        while (q.size())
        {
            auto [curx, cury] = q.front();
            q.pop();

            for (auto &&[x, y] : d)
            {
                auto nextx = x + curx, nexty = y + cury;
                if (nextx < 0 or nextx >= n or nexty < 0 or nexty >= m or dist[nextx][nexty] != -1 or v[nextx][nexty] == '*')
                {
                    continue;
                }

                if (v[nextx][nexty] == 'H')
                {
                    cout << dist[curx][cury] + 1;
                    return;
                }

                dist[nextx][nexty] = dist[curx][cury] + 1;
                q.push({nextx, nexty});
            }
        }
    };

    bfs();
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