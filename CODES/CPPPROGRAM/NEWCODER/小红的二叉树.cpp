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
    int n;
    cin >> n;
    if (n < 2)
    {
        cout << 0;
        return;
    }

    int result = 1;
    int base = 2;
    while (n)
    {
        if (n % 2)
        {
            result = (result * base) % MOD;
        }
        base = (base * base) % MOD;
        n /= 2;
    }

    cout << (result - 2 + MOD) % MOD;
}

signed main()
{
    cin.tie(nullptr)->sync_with_stdio(false);
    int TT = 1;
    // cin >> TT;
    while (TT--)
    {
        solve();
        cout << endl;
    }
}