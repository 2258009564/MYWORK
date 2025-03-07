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
    int n;
    cin >> n;
    vector<int> c(n + 1, 0);
    // BIT
    auto lowbit = [&](int x)
    {
        return x & -x;
    };

    auto add = [&](int val, int x) -> void
    {
        while (x <= n)
        {
            c[x] = val;
            x += lowbit(x);
        }
    };

    auto sum = [&](int x) -> int
    {
        int ans = 0;
        while (x >= 0)
        {
            ans += c[x];
            x -= lowbit(x);
        }
        return ans;
    };
    // BIT end
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