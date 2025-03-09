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
    int a1, a2, b1, b2;
    cin >> a1 >> a2 >> b1 >> b2;
    map<int, pair<int, int>> mp = {
        {1, {2, 0}},
        {2, {0, 2}},
        {3, {4, 2}},
        {4, {2, 4}},
        {5, {0, 6}},
        {6, {4, 6}},
        {7, {2, 8}}};
    vector v(5, vector<int>(9, 0));
    vector<pair<int, int>> d = {{2, 2}, {-2, 2}, {-2, -2}, {2, -2}};
    auto bfs = [&](pair<int, int> dd, pair<int, int> en) -> int
    {
        vector vis(5, vector<int>(9, -1));
        queue<pair<int, int>> q;
        q.push(dd);
        vis[dd.first][dd.second] = 0;

        while (q.size())
        {
            auto cur = q.front();
            auto [x, y] = cur;
            q.pop();

            if (cur == en)
            {
                return vis[x][y];
            }

            for (auto &&[dx, dy] : d)
            {
                auto xx = dx + x, yy = dy + y;
                if (xx < 0 or xx >= 5 or yy < 0 or yy >= 9 or vis[xx][yy] != -1)
                {
                    continue;
                }

                vis[xx][yy] = vis[x][y] + 1;
                q.push({xx, yy});
            }
        }
        return 0;
    };

    auto a1b1 = bfs(mp[a1], mp[b1]);
    auto a1b2 = bfs(mp[a1], mp[b2]);
    auto a2b1 = bfs(mp[a2], mp[b1]);
    auto a2b2 = bfs(mp[a2], mp[b2]);

    int ans = min(a1b1 + a2b2, a2b1 + a1b2);
    cout << ans;
}

signed main()
{
    cin.tie(0)->ios::sync_with_stdio(0);
    cout << setiosflags(ios::fixed) << setprecision(2);
    int TT = 1;
    cin >> TT;
    while (TT--)
    {
        solve();
        cout << endl;
    }
}