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
    // FU
    vector<int> father;
    auto init = [&](int n)
    {
        father.resize(n);
        iota(all(father), 0ll);
    };

    function<int(int)> ffind = [&](int i)
    {
        return i == father[i] ? i : father[i] = ffind(father[i]);
    };

    auto funion = [&](int i, int j) -> void
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
    // init(n);
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