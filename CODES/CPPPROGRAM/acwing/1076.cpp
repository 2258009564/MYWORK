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
    int n;
    cin >> n;
    vector v(n, vector<int>(n));
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cin >> v[i][j];
        }
    }

    vector pre(n, vector<pair<int, int>>(n, {-1, -1}));

    vector<pair<int, int>> d = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};

    auto bfs = [&](int i, int j)
    {
        pre[i][j] = {0, 0};
        queue<pair<int, int>> q;
        q.push({i, j});

        while (q.size())
        {
            auto [curx, cury] = q.front();
            q.pop();

            for (auto &&[x, y] : d)
            {
                auto dx = x + curx, dy = y + cury;
                if (dx < 0 or dx == n or dy < 0 or dy == n or v[dx][dy] == 1 or pre[dx][dy].first != -1 or pre[dx][dy].second != -1)
                {
                    continue;
                }

                pre[dx][dy] = {curx, cury}; // 可以从{dx, dy} 到 pr
                q.push({dx, dy});
            }
        }
    };

    bfs(n - 1, n - 1);

    // 倒序遍历 正序输出

    pair<int, int> start = {0, 0};
    while (1)
    {
        cout << start.first << ' ' << start.second << endl;
        if (start.first == n - 1 and start.second == n - 1)
        {
            break;
        }
        start = pre[start.first][start.second];
    }
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