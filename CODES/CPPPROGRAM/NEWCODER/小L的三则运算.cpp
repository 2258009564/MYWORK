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
    int x;
    char c;
    cin >> x >> c;
    if (c == '+')
    {
        cout << 1 << ' ' << x - 1;
    }
    else if (c == '-')
    {
        cout << x + 1 << '  ' << 1;
    }
    else
    {
        cout << x << ' ' << 1;
    }
}

signed main()
{
    cin.tie(nullptr)->sync_with_stdio(false);
    cout << setiosflags(ios::fixed) << setprecision(2);
    int TT = 1;
    // cin >> TT;
    while (TT--)
    {
        solve();
        cout << endl;
    }
}