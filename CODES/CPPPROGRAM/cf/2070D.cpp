// #pragma GCC optimize(2)
#include <bits/stdc++.h>
using namespace std;
#define int long long
#define endl '\n'
#define all(x) (x).begin(), (x).end()

const int INF = 1e9;       // 无穷大
const int INFLL = 1e18;    // 长整型无穷大
const int MOD = 998244353; // 题目要求的模数

void solve()
{
    int n;
    cin >> n;

    vector<vector<int>> g(n + 1);
    vector<int> parent(n + 1, 0);

    for (int i = 2; i <= n; i++)
    {
        cin >> parent[i];
        g[parent[i]].push_back(i);
    }

    vector<int> depth(n + 1, 0);
    function<void(int, int)> dfs_depth = [&](int u, int d)
    {
        depth[u] = d;
        for (int v : g[u])
        {
            dfs_depth(v, d + 1);
        }
    };

    dfs_depth(1, 0);

    vector<vector<int>> level(n + 1);
    for (int i = 1; i <= n; i++)
    {
        level[depth[i]].push_back(i);
    }

    vector<int> dp(n + 1, 0);
    dp[1] = 1;

    int max_depth = *max_element(all(depth));

    for (int d = 0; d < max_depth; d++)
    {
        for (int u : level[d])
        {
            for (int v : level[d + 1])
            {
                if (u == 1 || parent[v] != u)
                {
                    dp[v] = (dp[v] + dp[u]) % MOD;
                }
            }
        }
    }

    int ans = 0;
    for (int i = 1; i <= n; i++)
    {
        ans = (ans + dp[i]) % MOD;
    }

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