# 朴素

# 堆优化
```cpp
void solve()
{
    int n, m;
    cin >> n >> m;
    vector<int> v(n + 1);
    // 要建立有向边
    vector adj(n + 1, vector<pair<int, int>>());
    for (int i = 1; i <= m; i++)
    {
        int u, v, w;
        cin >> u >> v >> w;
        adj[u].emplace_back(w, v);
    }

    // 1 和 n 分别做源点 跑dij

    vector minDist(n + 1, vector<int>(n + 1, LLONG_MAX));
    for (int i = 1; i <= n; i++)
    {
        minDist[i][i] = 0;
    }

    auto dij = [&](int u, int fa) -> void
    {
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
        // 按照 {边，中继点} 存储 遍历到这个点的时候 查找它的儿子 
        // 进行松弛操作

        for (auto [w, v] : adj[u])
        {
            pq.push({w, v});
            minDist[u][v] = w; // 初始化
        }

        while (pq.size())
        {
            auto [curw, curv] = pq.top();
            pq.pop();

            // 我需要跑堆优化的dij
            for (auto [w, v] : adj[curv])
            {
                if (curw + w < minDist[u][v])
                {
                    minDist[u][v] = curw + w;
                    pq.push({minDist[u][v], v});
                }
            }
        }
    };

    dij(1, 0);
    dij(n, 0);

    for (int i = 1; i <= n; i++)
    {
        cout << minDist[1][i] << ' ' << minDist[n][i] << endl;
    }
}
```

