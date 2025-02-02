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
    int n, q;
    cin >> n >> q;
    vector<int> v(n), pre(n);
    for (auto &&i : v)
    {
        cin >> i;
    }

    partial_sum(v.begin(), v.end(), pre.begin());

    int l, r;
    while (q--)
    {
        cin >> l >> r;
        l--, r--; // 0-based

        cout << pre[r] - (l - 1 < 0 ? 0ll : pre[l - 1]) << endl;
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