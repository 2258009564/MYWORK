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
    int n, m;
    cin >> n >> m;
    vector v(n, vector<int>(m));
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cin >> v[i][j];
        }
    }
    vector<pair<int, int>> d = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};

    vector dist(n, vector<int>(m, -1));
    dist[0][0] = 0; // 对起点初始化

    auto bfs = [&]() -> void
    {
        queue<pair<int, int>> que;
        que.push({0, 0});

        while (que.size())
        {
            auto &[i, j] = que.front();
            que.pop();
            // 找当前的四个分支
            for (auto &&[x, y] : d)
            {
                auto dx = x + i, dy = y + j;
                // 写出分支 判断分支是否能到达
                if (dx < 0 or dx == n or dy < 0 or dy == m or v[dx][dy] == 1 or dist[dx][dy] != -1)
                {
                    continue; // 不满足条件就 continue
                }

                dist[dx][dy] = dist[i][j] + 1;
                que.push({dx, dy});
            }
        }
    };
    bfs();

    cout << dist[n - 1][m - 1];
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