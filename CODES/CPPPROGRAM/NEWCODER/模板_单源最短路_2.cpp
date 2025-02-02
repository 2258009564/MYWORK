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

    int n, m;
    cin >> n >> m;
    unordered_map<int, unordered_map<int, int>> adj;
    int v1, v2, val;
    while (m--)
    {
        cin >> v1 >> v2 >> val;
        adj[v1][v2] = val;
        adj[v2][v1] = val;
    }

    // dijkstra begin
    vector<int> visited(5001, 0), minDist(5001, INF);
    int Start = 1, End = n;
    minDist[Start] = 0;
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<>> pq;
    pq.push({minDist[Start], Start});
    while (pq.size())
    {
        auto [v, cur] = pq.top();
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

            if (minDist[next] > minDist[cur] + w)
            {
                minDist[next] = minDist[cur] + w;
                pq.push({minDist[next], next});
            }
        }
    }
    cout << (minDist[End] == INF ? -1 : minDist[End]);
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