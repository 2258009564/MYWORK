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

    // dfs

    vector<pair<int, int>> d = {{1, 0}, {0, 1}, {-1, 0}, {0, -1}};

    function<void(int, int)> dfs = [&](int i, int j) {
        if (i < 0 or i >= n or j < 0 or j >= m or vis[i][j] or v[i][j] == 0)
        {
            return;
        }

        vis[i][j] = 1;
        
        for (auto &&[dx, dy] : d)
        {
            dfs(i + dx, j + dy);
        }
    };
    // dfs end
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