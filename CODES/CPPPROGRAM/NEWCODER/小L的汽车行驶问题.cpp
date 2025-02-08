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
    int n;
    string s;
    cin >> n >> s;
    // 0 -> 10
    // 1 -> max(sp - 5, 0ll)
    // 2 -> max(sp - 10, 0ll) sp

    int sp = 0;
    int ans = 0;
    for (auto &&i : s)
    {
        if (i == '0')
        {
            sp += 10;
            ans += sp;
        }
        if (i == '1')
        {
            sp = max(sp - 5, 0ll);
            ans += sp;
        }
        if (i == '2')
        {
            int sp1 = sp;
            sp = max(sp - 10, 0ll);
            ans += sp;
            sp = sp1;
        }
    }
    cout << ans;
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