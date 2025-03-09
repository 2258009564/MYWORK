// #pragma GCC optimize(2)
#include <bits/stdc++.h>
using namespace std;
#define int long long
#define endl '\n'
#define all(x) (x).begin(), (x).end()

const int INF = 1e9;     // 无穷大
const int INFLL = 1e18;  // 长整型无穷大
const int MOD = 1e9 + 7; // 模数
// -9.2e18 ~ 9.2e18

void solve()
{
    int n, a, b;
    cin >> n >> a >> b;
    if (a == b)
    {
        cout << 0;
        return;
    }
    vector<int> v(n + 1);
    for (int i = 1; i <= n; i++)
    {
        cin >> v[i];
    }

    vector<int> vis(n + 1, 0);

    auto bfs = [&]() -> void
    {
        queue<int> q;
        q.push(a);
        vis[a] = 0;

        while (q.size())
        {
            auto x = q.front();
            q.pop();
            auto d = v[x];
            for (auto dx : {d, -d})
            {
                auto xx = x + dx;
                if (xx < 1 or xx > n or vis[xx])
                {
                    continue;
                }
                vis[xx] = vis[x] + 1;
                q.push(xx);
            }
        }
    };
    bfs();
    cout << (vis[b] ? vis[b] : -1);
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
        cout << endl;
    }
}