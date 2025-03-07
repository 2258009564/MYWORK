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
    int n, q;
    cin >> n >> q;
    vector<int> s(n + 1);

    auto check = [&](int x) -> bool
    {
        if (x % 2 == 0)
        {
            return 1;
        }
        int sq = sqrt(x);
        return sq * sq == x;
    };

    for (int i = 1, x; i <= n; i++)
    {
        cin >> x;
        s[i] = s[i - 1] + check(x);
    }

    while (q--)
    {
        int l, r;
        cin >> l >> r;
        cout << s[r] - s[l - 1] << endl;
    }
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