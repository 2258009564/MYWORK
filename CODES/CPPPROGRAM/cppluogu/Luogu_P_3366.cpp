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
    int n, m; // n为顶点数，m为边数
    cin >> n >> m;
    // prim
    set<int> nodes; // 存储已访问的节点

    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<>> pq; // 小顶堆，存储边{权重,目标顶点}

    int MSTweight = 0; // 最小生成树的总权重

    int v1, v2, val; // v1,v2为边的两个顶点，val为边的权重

    vector<vector<pair<int, int>>> adj(n + 1); // 邻接表存储图，adj[u]存储u的所有邻边{顶点,权重}
    while (m--)
    {
        cin >> v1 >> v2 >> val;
        // 无向图需要添加两条边
        adj[v1].emplace_back(v2, val);
        adj[v2].emplace_back(v1, val);
    }

    pq.push({0, 1}); // 从顶点1开始，初始权重为0

    while (pq.size())
    {
        auto [curw, cur] = pq.top(); // curw为当前边的权重，cur为当前顶点
        pq.pop();

        if (nodes.count(cur)) // 如果当前顶点已访问，跳过
        {
            continue;
        }

        nodes.insert(cur); // 将当前顶点标记为已访问
        MSTweight += curw; // 将当前边的权重加入最小生成树的总权重

        // 遍历当前顶点的所有邻边
        for (auto &&[next, nextw] : adj[cur]) // next为邻接顶点，nextw为边权重
        {
            if (!nodes.count(next)) // 如果邻接顶点未访问
            {
                pq.push({nextw, next}); // 将边加入优先队列
            }
        }
    }
    if (nodes.size() != n) // 如果访问的顶点数不等于总顶点数，说明图不连通
    {
        cout << "orz"; // 输出无解
    }
    else
    {
        cout << MSTweight; // 输出最小生成树的总权重
    }
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