// #pragma GCC optimize(2)
#include <bits/stdc++.h>
using namespace std;
#define int long long
#define endl '\n'

const int INF = 1e9;     // 无穷大
const int INFLL = 1e18;  // 长整型无穷大
const int MOD = 1e9 + 7; // 模数

void solve()
{
    int n, q;
    cin >> n >> q;
    vector<int> a(n), b(n);

    // 读取数组 a 和 b
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    for (int i = 0; i < n; i++)
    {
        cin >> b[i];
    }

    vector<int> prefix_sum(n + 1, 0);

    for (int i = 0; i < n; i++)
    {
        for (int j = i; j < n; j++)
        {
            prefix_sum[i + 1] += (a[i] ^ b[j]);
            prefix_sum[i + 1] %= MOD;
        }
    }

    while (q--)
    {
        int l, r;
        cin >> l >> r;

        int sum = 0;
        for (int i = l; i <= r; i++)
        {
            sum = (sum + prefix_sum[i]) % MOD;
        }

        cout << sum << endl;
    }
}

signed main()
{
    cin.tie(nullptr)->sync_with_stdio(false);
    cout << setiosflags(ios::fixed) << setprecision(2);
    int TT = 1;
    cin >> TT;
    while (TT--)
    {
        solve();
    }
}