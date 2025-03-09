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
    int n, p;
    cin >> n >> p;
    vector<pair<int, int>> v(n);
    int sum = 0;
    for (auto &&[a, b] : v)
    {
        cin >> a >> b;
        sum += a;
    }
    if (sum <= p )
    {
        cout << -1.0000000000;
        return;
    }
    int l = 0, r = 1e9, m, ans = -1;
    while (l <= r)
    {
        m = l + (r - l) / 2;
        auto check = [&]() -> bool
        {
            int ans = 0, rest = 0;
            for (auto &&[a, b] : v)
            {
                if (b - m * a >= 0)
                {
                    continue;
                }
                else
                {
                    rest = m * a - b;
                }
            }
            // rs记录了 需要充电的总数量
            return m * p >= rest;
        };
        if (check())
        {
            l = (ans = m) + 1;
        }
        else
        {
            r = m - 1;
        }
    }
    cout << ans;
    
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