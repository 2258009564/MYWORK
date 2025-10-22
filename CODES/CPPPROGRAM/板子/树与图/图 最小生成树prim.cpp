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
    int v, e;
    cin >> v >> e;
    int vsz = v + 1;

    vector<vector<pair<int, int>>> adj(vsz + 1);
    int v1, v2, val;
    while (e--)
    {
        cin >> v1 >> v2 >> val;
        adj[v1].emplace_back(v2, val);
        adj[v2].emplace_back(v1, val);
    }

    // prim begin
    vector<int> visited(vsz, 0), minDist(vsz, INFLL);
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<>> pq;

    minDist[1] = 0;
    pq.push({0, 1});

    int totalweight = 0, nodeInMST = 0;

    while (pq.size())
    {
        auto [w, cur] = pq.top();
        pq.pop();

        if (visited[cur])
        {
            continue;
        }

        visited[cur] = 1;
        totalweight += w;
        nodeInMST++;

        for (auto &&[next, nextw] : adj[cur])
        {
            if (visited[next])
            {
                continue;
            }

            if (nextw < minDist[next])
            {
                minDist[next] = nextw;
                pq.push({minDist[next], next});
            }
        }
    }
    if (nodeInMST != v)
    {
        cout << -1;
        return;
    }
    cout << totalweight;
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