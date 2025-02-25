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
    int n1 = n + 1;
    int sum = 0, cur = 1;
    while (n >= k)
    {
        if (n & 1)
        {
            sum += cur;
        }
        n >>= 1;
        cur <<= 1;
    }
    // cout << n1 << ' ' << sum << ' ' << sum / 2 << endl;
    cout << n1 * sum / 2;
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