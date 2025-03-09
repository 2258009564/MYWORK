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
    int a, b, n, m, h;
    cin >> a >> b >> n >> m >> h;

    int l = 0, r = m - 1, mid, ans;
    while (l <= r)
    {
        mid = l + (r - l) / 2;
        auto check = [&]() -> bool
        {
            auto wa = n, wb = m - mid, ans = mid;
            ans -= (h - a) * (wa / b);
            wa %= b;
            ans -= (h - b) * ((wa + wb) / b);
            return ans <= 0ll;
        };
        if (check())
        {
            l = (ans = mid) + 1;
        }
        else
        {
            r = mid - 1;
        }
    }
    cout << n + m - ans;
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