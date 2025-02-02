//#pragma GCC optimize(2)
#include <bits/stdc++.h>
using namespace std;
#define int long long
#define endl '\n'

const int INF = 1e9;     // 无穷大
const int INFLL = 1e18; // 长整型无穷大
const int MOD = 1e9 + 7; // 模数

void solve()
{
    int n;
    cin >> n;
    vector<int> v(n);
    for (auto &&i : v)
    {
        cin >> i;
    }
    ranges::sort(v);

    vector<int> ans(INF + 1, INT_MIN);
    // FU
    vector<int> father(INF + 1 + 1);
    iota(father.begin(), father.end(), 0ll);

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
    funion(v[0], v[1]);
    funion(v[n - 2], v[n - 1]);
    for (int i = 1; i + 1 < v.size(); i++)
    {
        if (v[i] - v[i - 1] <= v[i + 1] - v[i])
        {
            funion(i, i - 1); // v[i] 选择 v[i-1] 作为同伴
        }
        else
        {
            funion(i, i + 1); // v[i] 选择 v[i+1] 作为同伴
        }
    }
    set<int> st;

    for (int i = 0; i < )
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