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
    int n, m;
    cin >> n >> m;
    struct Data
    {
        int x, y, t;
    };
    vector<Data> datas;
    while (m--)
    {
        int x, y, t;
        cin >> x >> y >> t;
        datas.emplace_back(x, y, t);
    }

    ranges::sort(datas, [](auto &a, auto &b)
                 { return a.t < b.t; });

    // FU
    vector<int> father(n + 1);
    iota(father.begin(), father.end(), 0);

    function<int(int)> ffind = [&](int i) -> int
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
    int totaldots = n;
    for (auto &&[x, y, t] : datas)
    {
        if (!issame(x, y))
        {
            totaldots--;
            funion(x, y);
        }

        if (totaldots == 1)
        {
            cout << t;
            return;
        }
    }
    cout << -1;
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