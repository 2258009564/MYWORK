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

    // BIT
    vector<int> c(n + 2, 0), c1 = c;
    auto lowbit = [&](int x) -> int
    {
        return x & -x;
    };

    auto add = [&](vector<int> &c, int i, int val) -> void
    {
        while (i <= n)
        {
            c[i] += val;
            i += lowbit(i);
        }
    };

    auto sum = [&](vector<int> &c, int i) -> int
    {
        int ans = 0;
        while (i)
        {
            ans += c[i];
            i -= lowbit(i);
        }
        return ans;
    };

    auto radd = [&](int x, int y, int val) -> void
    {
        add(c, x, val);
        add(c, y + 1, -val);
        add(c1, x, val * (x - 1));
        add(c1, y + 1, -val * (y));
    };

    auto rsum = [&](int x, int y) -> int
    {
        return y * sum(c, y) - (x - 1) * sum(c, x - 1) - (sum(c1, y) - sum(c1, x - 1));
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