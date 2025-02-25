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
    int n, m1, m2;
    cin >> n >> m1 >> m2;
    vector<vector<int>> adj1(n + 1), adj2(n + 1);
    int tot1 = n, tot2 = n;
    int v1, v2;
    while (m1--)
    {
        cin >> v1 >> v2;
        adj1[min(v1, v2)].emplace_back(max(v1, v2));
    }
    while (m2--)
    {
        cin >> v1 >> v2;
        adj2[min(v1, v2)].emplace_back(max(v1, v2));
    }

    vector<int> father(n + 1, 0);
    iota(all(father), 0ll);

    function<int(int)> ffind = [&](int i)
    {
        return i == father[i] ? i : father[i] = ffind(father[i]);
    };

    auto funion = [&](int i, int j)
    {
        auto ri = ffind(i), rj = ffind(j);
        if (ri != rj)
        {
            father[ri] = rj;
            tot2--;
        }
    };

    auto issame = [&](int i, int j) -> bool
    {
        return ffind(i) == ffind(j);
    };

    int ans = 0;

    for (int v1 = 1; v1 <= n; v1++)
    {
        for (auto &&v2 : adj2[v1])
        {
            funion(v1, v2); // 对所有g的都合并
        }
    }

    for (int v1 = 1; v1 <= n; v1++)
    {
        for (auto &&v2 : adj1[v1])
        {
            if (!issame(v1, v2)) // 如果在g中没有 说明要删掉
            {
                ans++;
            }
            else
            {
                tot1--; // 否则 就合并
            }
        }
    }

    cout << ans + tot1 - tot2;
}

signed main()
{
    cin.tie(nullptr)->ios::sync_with_stdio(false);
    cout << setiosflags(ios::fixed) << setprecision(2);
    int TT = 1;
    cin >> TT;
    while (TT--)
    {
        solve();
        cout << endl;
    }
}

