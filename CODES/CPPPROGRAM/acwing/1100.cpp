// #pragma GCC optimize(2)
#include <bits/stdc++.h>
using namespace std;
#define int long long
#define endl '\n'

const int INF = 1e9;     // 无穷大
const int INFLL = 1e18;  // 长整型无穷大
const int MOD = 1e9 + 7; // 模数
// -9.2e18 ~ 9.2e18

void solve()
{
    int n, k;
    cin >> n >> k;

    vector<int> dist(2e5 + 1, -1);

    auto bfs = [&]()
    {
        queue<int> q;

        dist[n] = 0;
        q.push(n);

        while (q.size())
        {
            auto cur = q.front();
            q.pop();

            if (cur == k)
            {
                cout << dist[cur];
                return;
            }

            vector<int> next;
            next.emplace_back(cur + 1);
            next.emplace_back(cur - 1);
            next.emplace_back(cur * 2);

            for (auto &&nex : next)
            {
                if (nex < 0 or nex > 2e5 or dist[nex] != -1)
                {
                    continue;
                }
                dist[nex] = dist[cur] + 1;
                q.push(nex);
            }
        }
    };

    bfs();
}

signed main()
{
    cin.tie(nullptr)->ios::sync_with_stdio(false);
    cout << setiosflags(ios::fixed) << setprecision(2);
    int TT = 1;
    // cin >> TT;
    while (TT--)
    {
        solve();
        cout << endl;
    }
}