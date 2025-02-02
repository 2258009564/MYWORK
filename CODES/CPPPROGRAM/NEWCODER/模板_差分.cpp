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
    vector<int> v(n + 1), diff(n + 2);
    for (int i = 1; i <= n; i++)
    {
        cin >> v[i];
    }

    diff[1] = v[1];
    for (int i = 2; i <= n; i++)
    {
        diff[i] = v[i] - v[i - 1];
    }

    int l, r, k;
    while (m--)
    {
        cin >> l >> r >> k;
        diff[l] += k, diff[++r] -= k;
    }

    vector<int> pre(n);
    partial_sum(diff.begin() + 1, diff.begin() + 1 + n, pre.begin());

    for (auto &&i : pre)
    {
        cout << i << ' ';
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