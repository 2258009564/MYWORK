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
    for (auto &&i : a)
    {
        cin >> i;
    }
    for (auto &&i : b)
    {
        cin >> i;
    }

    vector<int> pre(n + 1, 0);

    while (q--)
    {
        int l, r;
        cin >> l >> r;
        --l;
        --r; // 0-indexed

        long long result = 0;
        for (int i = l; i <= r; ++i)
        {
            for (int j = i; j <= r; ++j)
            {
                result = (result + (a[i] ^ b[j])) % MOD;
            }
        }
        cout << result << endl;
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
        // cout << endl;
    }
}