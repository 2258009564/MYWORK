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
    int n, k;
    cin >> n >> k;
    vector<int> v(n);
    for (int i = 0; i < n; i++)
    {
        cin >> v[i];
    }

    int l = 1, r = ranges::max(v), m, ans = 0;
    while (l <= r)
    {
        m = l + (r - l) / 2;
        auto check = [&]() -> bool
        {
            int ans = 0;
            for (int i = 0; i < n; i++)
            {
                ans += v[i] / m;
            }
            return ans >= k;
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