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
    int n, a, b;
    cin >> n >> a >> b;
    vector<int> v(n);
    auto d = gcd(a, b);
    for (int i = 0; i < n; i++)
    {
        cin >> v[i];
        v[i] %= d;
    }
    // 2 3 4 5    2 4 gcd(2, 4) = 2
    // 6 3 4 5
    ranges::sort(v);
    int ans = v.back() - v.front();
    for (int i = 1; i < n; i++)
    {
        ans = min(ans, v[i - 1] + d - v[i]);
    }
    cout << ans;
}

signed main()
{
    cin.tie(nullptr)->ios::sync_with_stdio(false);
    cout << setiosflags(ios::fixed) << setprecision(2);
    int TT = 1;
    cin >> TT;
    while (TT--)
    {
        solve();
        cout << endl;
    }
}