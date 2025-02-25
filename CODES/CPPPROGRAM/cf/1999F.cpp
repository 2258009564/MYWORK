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

    int ans = 0;
    // 1 1 0 0
    int kk = k / 2;
    // 1 0 1 0 1 1
    // 6 3
    // 1 1 1 1 0 0
    // 2
    vector<int> v(n);
    for (int i = 0; i < n; i++)
    {
        cin >> v[i];
    }
    ranges::sort(v, greater<int>());

    for (int i = kk; i + 1 < n and v[i] != 0; i++)
    {
        // 前面的 有 i 项  后面的 有 n - i - 1 项
        ans += (i % MOD * (n - i - 1) % MOD);
        ans %= MOD;
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