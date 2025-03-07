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
    int n, tot, k;
    cin >> n >> tot >> k;

    vector<int> v(n);
    for (int i = 0; i < n; i++)
    {
        cin >> v[i];
    }
    ranges::sort(v);
    int l = 0, r = 2e14 + 5, m, ans;
    while (l <= r)
    {
        m = l + (r - l) / 2;
        auto check = [&](int m) -> bool
        {
            int ans = 0;
            for (int i = 0; i < n; i++)
            {
                ans += max(0ll, v[i] - m);
            }

            ans = min(ans, tot);
            // cout << m << ' ' << ans << endl;
            ans += k;

            for (int i = 0; i < n; i++)
            {
                if (v[i] < m)
                {
                    ans -= m - v[i];
                    if (ans < 0)
                    {
                        return 0;
                    }
                }
            }
            return 1;
        };

        if (check(m))
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
    cin >> TT;
    while (TT--)
    {
        solve();
        cout << endl;
    }
}