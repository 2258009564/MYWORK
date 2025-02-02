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
    int a, b;
    cin >> a >> b;
    struct Data
    {
        int v1, v2, val;
        Data(int v1, int v2, int val) : v1(v1), v2(v2), val(val) {};
    };
    vector<Data> datas;
    int v1, v2, val;
    while (b--)
    {
        cin >> v1 >> v2 >> val;
        datas.emplace_back(min(v1, v2), max(v1, v2), val);
    }

    // K
    ranges::sort(datas, [](Data &a, Data &b)
                 { return a.val < b.val; });
    vector<int> minDist(a + 1, INF);
    int MSTnode = 0, MSTweight = 0;
    // FU
    vector<int> father;
    auto init = [&](int n)
    {
        father.resize(n + 1);
        iota(father.begin(), father.end(), 0ll);
    };
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
        }
    };
    auto issame = [&](int i, int j) -> bool
    {
        return ffind(i) == ffind(j);
    };
    // FU end
    init(a);
    for (auto &&[v1, v2, val] : datas)
    {
        if (!issame(v1, v2))
        {
            funion(v1, v2);
            MSTnode++;
            MSTweight += val;
        }
        if (MSTnode == a - 1)
        {
            cout << MSTweight;
            return;
        }
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