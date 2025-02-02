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
    int n;
    cin >> n;
    vector<vector<int>> vis(n, vector<int>(n, 0));
    vector<int> row(n, 0), col(n, 0);

    int ans = 0;
    int res = 0;
    auto dfs = [&](auto &&self, int i, int j)
    {
        if (i < 0 or i == n or j < 0 or j == n or vis[i][j] or row[i] or col[j])
        {
            return;
        }

        if (res == n)
        {
            ans++;
            return;
        }

        res++;
        vis[i][j] = 1, row[i] = 1, col[j] = 1;
        for (auto &&x : {1, 0, -1})
        {
            for (auto &&y : {-1, 0, 1})
            {
                if (x == y and x == 0)
                {
                    continue;
                }

                auto curx = x + i, cury = y + j;
                self(self, curx, cury);
            }
        }
        vis[i][j] = 0, row[i] = 0, col[j] = 0;
        res--;
    };
    dfs(dfs, 0, 0);
    cout << ans;
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