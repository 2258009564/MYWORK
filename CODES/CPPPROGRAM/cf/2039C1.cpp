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
    int x, m;
    cin >> x >> m;

    // num [1, m]
    // x ^ num == y
    // x % num == 0
    // y % num == 0

    // x 是 不变的
    int ans = 0;

    for (int y = 1; y <= min(2ll * x, m); y++)
    {
        ans += (x - y and (x % (x ^ y) == 0 or y % (x ^ y) == 0));
    }
    cout << ans;
}

signed main()
{
    cin.tie(nullptr)->sync_with_stdio(false);
    int TT = 1;
    cin >> TT;
    while (TT--)
    {
        solve();
        cout << endl;
    }
}