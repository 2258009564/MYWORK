/*
路径总和III
给定一个二叉树的根节点root,和一个整数 num
求该二叉树里节点值之和等于 num 的路径的数目
路径不需要从根节点开始，也不需要在叶子节点结束
但是路径方向必须是向下的（只能从父节点到子节点）
*/
/*
fa -> x -> son

节点值是v[i]
我们最后要查询的信息是 \sum u 做根 的树 等于num 的路径数量
也就是 \sum dp[u][num]
所以我们要维护 dp[u][i] , i from [0, num]
转移方程
for (int k = 0; k <= num; k++) dp[u][k] += dp[nxt][k - v[i]]
*/

// #pragma GCC optimize(2)
#include <bits/stdc++.h>
using namespace std;
#define int long long
#define endl '\n'
#define all(x) (x).begin(), (x).end()

constexpr int MOD = 1e9 + 7;
// -9.2e18 ~ 9.2e18

void solve()
{
    int n;   // 节点数量
    int num; // target
    cin >> n >> num;
    int st; // 根/起点
    cin >> st;

    vector<int> v(n + 1);
    for (int i = 1; i <= n; i++)
    {
        cin >> v[i];
    }

    vector<vector<int>> adj(n + 1);
    for (int i = 1; i < n; i++)
    {
        int a, b;
        cin >> a >> b;
        adj[a].emplace_back(b); // 父 -> 子
    }

    int ans = 0;
    map<int, int> cnt; // 前缀和 -> 出现次数（在当前根到u路径上）
    cnt[0] = 1;        // 空前缀

    function<void(int, int)> dfs = [&](int u, int pre)
    {
        pre += v[u];
        ans += cnt[pre - num]; // 统计以 u 结尾、和为 num 的路径条数
        cnt[pre]++;

        for (auto nxt : adj[u])
        {
            dfs(nxt, pre);
        }

        cnt[pre]--;
    };

    dfs(st, 0);
    cout << ans;
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