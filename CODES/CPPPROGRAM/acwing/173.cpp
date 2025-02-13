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
    vector v(n, vector<char>(m));
    vector<pair<int, int>> dots;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cin >> v[i][j];
            if (v[i][j] == '1')
            {
                dots.emplace_back(i, j);
            }
        }
    }

    vector ans(n, vector<int>(m, INT_MAX));

    auto bfs = [&]()
    {
        vector<pair<int, int>> d = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};

        queue<pair<int, int>> q;
        for (auto &&[x, y] : dots)
        {
            q.push({x, y});
            ans[x][y] = 0;
        }

        while (q.size())
        {
            auto [curx, cury] = q.front();
            q.pop();

            for (auto &&[x, y] : d)
            {
                auto nextx = curx + x, nexty = cury + y;
                if (nextx < 0 or nextx >= n or nexty < 0 or nexty >= m or ans[nextx][nexty] == 0 or ans[nextx][nexty] != INT_MAX or ans[nextx][nexty] == 0)
                {
                    continue;
                }

                ans[nextx][nexty] = min(ans[curx][cury] + 1, ans[nextx][nexty]);
                q.push({nextx, nexty});
            }
        }
    };

    bfs();

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cout << ans[i][j] << ' ';
        }
        cout << endl;
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