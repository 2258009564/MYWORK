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
    int n, m;
    cin >> n >> m;
    vector<vector<pair<int, int>>> adj(n + 1); // 邻接表，pair<节点, 距离>
    int s, e, v;
    while (m--)
    {
        cin >> s >> e >> v;
        adj[s].push_back({e, v});
    }

    /*
    堆优化版Dijkstra算法:
    1. 使用优先队列维护当前所有可达但未访问的节点，按距离排序
    2. 每次取出队列中距离最小的节点，标记为已访问
    3. 更新该节点邻居的距离，并将新的可能路径加入队列
    */

    vector<int> minDist(n + 1, INT_MAX); // 每一个节点到源点的最小距离
    vector<bool> visited(n + 1, false);  // 记录节点是否已被访问

    int start = 1, en = n;
    minDist[start] = 0;

    // 优先队列，存储<距离, 节点编号>，按距离从小到大排序
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    pq.push({0, start});

    while (!pq.empty())
    {
        int dist = pq.top().first;
        int cur = pq.top().second;
        pq.pop();

        if (visited[cur])
            continue;        // 如果已经访问过，跳过
        visited[cur] = true; // 标记为已访问

        // 更新当前节点的所有邻居
        for (const auto &edge : adj[cur])
        {
            int next = edge.first;
            int weight = edge.second;

            if (!visited[next] && minDist[cur] + weight < minDist[next])
            {
                minDist[next] = minDist[cur] + weight;
                pq.push({minDist[next], next});
            }
        }
    }

    cout << (minDist[en] == INT_MAX ? -1 : minDist[en]);
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