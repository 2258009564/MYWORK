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
    int n;
    cin >> n;

    map<int, vector<int>> adj;

    for (int i = 1; i <= n; i++)
    {
        int num;
        cin >> num;
        adj[num].emplace_back(i);
    }

    int maxnum = 0;

    for (auto &&[_, v] : adj)
    {
        int num = v.size();
        maxnum = max(maxnum, num);
    }
    int ok = 1;
    for (int i = 1; i <= n; i++)
    {
        if (!adj[i].empty())
        {
            if (maxnum != adj[i].size())
            {
                ok = 0;
                break;
            }
        }
    }
    cout << maxnum << ' ' << (ok ? "yes" : "no") << endl;
    vector<int> v;
    function<void(int)> dfs = [&](int i) -> void
    {
        v.emplace_back(i);
        for (auto &&x : adj[i])
        {
            dfs(x);
        }
    };

    dfs(adj[0].front());

    for (int i = 0; i < v.size(); i++)
    {
        cout << v[i] << ' ';
    }
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