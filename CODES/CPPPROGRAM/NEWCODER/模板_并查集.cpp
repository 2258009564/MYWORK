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

    // fu begin
    vector<int> father;
    vector<int> sz;
    int tot;
    auto init = [&](int n)
    {
        father.resize(n);
        sz.resize(n, 1ll);
        iota(father.begin(), father.end(), 0ll);
        tot = n;
    };

    function<int(int)> ffind = [&](int n)
    {
        return n == father[n] ? n : father[n] = ffind(father[n]);
    };

    auto funion = [&](int i, int j)
    {
        auto ri = ffind(i), rj = ffind(j);
        if (sz[ri] > sz[rj])
        {
            swap(ri, rj);
        }
        // rj is greater
        if (ri - rj)
        {
            sz[rj] += sz[ri];
            father[ri] = rj;
            tot--;
        }
    };

    auto issame = [&](int i, int j)
    {
        return ffind(i) == ffind(j);
    };
    // fu end
    init(n);
    int v1, v2;
    while (m--)
    {
        cin >> v1 >> v2;
        v1--, v2--; // 0-based

        funion(v1, v2);
    }

    cout << tot << ' ' << ranges::max(sz);
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