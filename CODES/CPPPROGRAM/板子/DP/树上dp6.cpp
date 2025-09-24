/*
监控二叉树
给定一个二叉树，我们在树的节点上安装摄像头
节点上的每个摄影头都可以监视其父对象、自身及其直接子对象
计算监控树的所有节点所需的最小摄像头数量
*/

// #pragma GCC optimize(2)
#include <bits/stdc++.h>
using namespace std;
#define int long long
#define endl '\n'
#define all(x) (x).begin(), (x).end()

constexpr int MOD = 1e9 + 7;
// -9.2e18 ~ 9.2e18

// ...existing code...
void solve()
{
    int n;
    cin >> n;
    vector<vector<int>> adj(n + 1);
    vector<int> indeg(n + 1);
    for (int i = 1; i < n; i++)
    {
        int v1, v2;
        cin >> v1 >> v2;
        adj[v1].emplace_back(v2);
        indeg[v2]++;
    }
    int root = 1;
    for (int i = 1; i <= n; i++)
    {
        if (indeg[i] == 0)
        {
            root = i;
            break;
        }
    }

    vector<array<int, 3>> dp(n + 1, {0, 0, 0});

    function<void(int)> dfs = [&](int u)
    {
        if (adj[u].empty())
        {
            dp[u][0] = 1;         // 叶子放摄像头
            dp[u][1] = LLONG_MAX; // 叶子不能被子覆盖（没有子）
            dp[u][2] = 0;         // 由父覆盖
            return;
        }

        int put = 1;               // dp[u][0]
        int sum01 = 0;             // 用于 dp[u][1] 和 dp[u][2] 的 Σ min(dp[v][0], dp[v][1])
        int bestDelta = LLONG_MAX; // 至少选一个子放摄像头的增量

        for (int v : adj[u])
        {
            dfs(v);
            put += min({dp[v][0], dp[v][1], dp[v][2]});

            int m01 = min(dp[v][0], dp[v][1]);
            sum01 += m01;
            bestDelta = min(bestDelta, dp[v][0] - m01);
        }

        dp[u][0] = put;
        dp[u][2] = sum01;
        dp[u][1] = (bestDelta == LLONG_MAX ? LLONG_MAX : sum01 + bestDelta); // 需要至少一个子放摄像头
    };

    dfs(root);
    cout << min(dp[root][0], dp[root][1]);
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
        // cout << endl;
    }
}