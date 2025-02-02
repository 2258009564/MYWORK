// #pragma GCC optimize(2)
#include <bits/stdc++.h>
using namespace std;
#define int long long
#define endl '\n'

const int INF = 1e9;     // 无穷大
const int INFLL = 1e18;  // 长整型无穷大
const int MOD = 1e9 + 7; // 模数
const int N = 5e3 + 1;
void solve()
{
    int n, m;
    cin >> n >> m;

    // 刚刚添加的
    if (n == 1)
    {
        cout << 0;
        return;
    }

    vector<vector<pair<int, int>>> adj(N);
    int v1, v2;
    while (m--)
    {
        cin >> v1 >> v2;
        adj[v1].push_back({v2, 1});
        adj[v2].push_back({v1, 1});
    }

    vector<int> minDist(N, INF);
    vector<bool> visited(N, 0);
    minDist[1] = 0;

    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;

    pq.push({0, 1});

    while (pq.size())
    {
        auto [_, cur] = pq.top();
        pq.pop();

        if (visited[cur])
        {
            continue;
        }

        visited[cur] = 1;

        for (auto &&[next, w] : adj[cur])
        {
            if (visited[next])
            {
                continue;
            }

            if (minDist[cur] + w < minDist[next])
            {
                minDist[next] = minDist[cur] + w;
                pq.push({minDist[next], next});
            }
        }
    }

    cout << (minDist[n] == INF ? -1 : minDist[n]);
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