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
    map<char, char> mp = {{'?', '?'}, {'U', 'D'}, {'D', 'U'}, {'L', 'R'}, {'R', 'L'}};
    int n, m;
    cin >> n >> m;
    vector v(n, vector<char>(m));
    vector vis(n, vector<int>(m, 0));
    vector<pair<int, int>> wenhao;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cin >> v[i][j];
            v[i][j] = mp[v[i][j]];
            if (v[i][j] == '?')
            {
                wenhao.emplace_back(i, j);
            }
        }
    }
    queue<pair<int, int>> q;
    for (int i = 0; i < n; i++)
    {
        // cout << v[i][0] << ' ' << v[i][m - 1] << endl;
        if (v[i][0] == 'R')
        {
            q.push({i, 0});
            vis[i][0] = 1;
        }
        if (v[i][m - 1] == 'L')
        {
            q.push({i, m - 1});
            vis[i][m - 1] = 1;
        }
    }

    for (int j = 0; j < m; j++)
    {
        // cout << v[0][j] << ' ' << v[n - 1][j] << endl;
        if (v[0][j] == 'D')
        {
            q.push({0, j});
            vis[0][j] = 1;
        }
        if (v[n - 1][j] == 'U')
        {
            q.push({n - 1, j});
            vis[n - 1][j] = 1;
        }
    }

    while (q.size())
    {
        auto [x, y] = q.front();
        q.pop();

        if (v[x][y] == 'U')
        {
            x--;
        }
        if (v[x][y] == 'D')
        {
            x++;
        }
        if (v[x][y] == 'L')
        {
            y--;
        }
        if (v[x][y] == 'R')
        {
            y++;
        }

        if (x < 0 or x >= n or y < 0 or y >= m or v[x][y] == '?')
        {
            continue;
        }

        vis[x][y] = 1;
        q.push({x, y});
    }
    vector<pair<int, int>> d = {{1, 0}, {0, 1}, {-1, 0}, {0, -1}};
    for (auto &&[x, y] : wenhao)
    {
        int tot = 0;
        for (auto &&[dx, dy] : d)
        {
            auto curx = x + dx, cury = x + dy;
            if (curx < 0 or curx >= n or cury < 0 or cury >= m or vis[curx][cury] == 1)
            {
                tot++;
            }
        }
        if (tot == 4)
        {
            vis[x][y] = 1;
        }
    }
    int ans = m * n;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cout << vis[i][j] << ' ';
            ans -= vis[i][j];
        }
        cout << endl;
    }
    cout << ans;
}

signed main()
{
    cin.tie(nullptr)->ios::sync_with_stdio(false);
    cout << setiosflags(ios::fixed) << setprecision(2);
    int TT = 1;
    cin >> TT;
    while (TT--)
    {
        solve();
        cout << endl;
    }
}