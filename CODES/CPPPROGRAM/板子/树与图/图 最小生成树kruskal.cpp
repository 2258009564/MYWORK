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
    struct Edge
    {
        int v1, v2, val;
        Edge(int v1, int v2, int val) : v1(v1), v2(v2), val(val) {};
    };
    vector<Edge> edges;

    int v1, v2, val;
    while (m--)
    {
        cin >> v1 >> v2 >> val;
        auto [a, b] = minmax(v1, v2);
        edges.emplace_back(a, b, val);
    }
    ranges::sort(edges, [](Edge &a, Edge &b)
                 { return a.val < b.val; });

    // FU begin
    vector<int> father;
    auto init = [&](int n)
    {
        father.resize(n + 1);
        iota(father.begin(), father.end(), 0ll);
    };
    function<int(int)> ffind = [&](int i)
    {
        return i == father[i] ? i : ffind(father[i]);
    };
    auto funion = [&](int i, int j)
    {
        auto ri = ffind(i), rj = ffind(j);
        if (ri != rj)
        {
            father[ri] = rj;
        }
    };

    auto issame = [&](int i, int j) -> bool
    {
        return ffind(i) == ffind(j);
    };
    // FU end
    init(n);

    int MSTweight = 0, MSTnode = 0;

    for (auto &&[v1, v2, val] :edges)
    {
        if (!issame(v1, v2))
        {
            funion(v1, v2);
            MSTweight += val;
            MSTnode++;
        }
        if (MSTnode == n - 1)
        {
            cout << MSTnode;
            return;
        }
    }
    cout << -1;
    return;
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