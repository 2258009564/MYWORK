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
    int n, b, c;
    cin >> n >> b >> c;
    int k = n - 1;
    
    if (b == 0) // 所有的 a_i 一样
    {
        if (k - c > 1)
        {
            cout << -1; // 差距太大无法构造
        }
        else if (k >= c)
        {
            cout << n - 1; // 有一个已经在了 不用构造
        }
        else // k < c
        {
            cout << n; // 全都需要构造
        }
    }
    else // b != 0
    {
        if (c > k)
        {
            cout << n;
        }
        else
        {
            int m;
            // k >= m * b + c 要让 m 最大
            m = (k - c) / b;
            // 如果m == 0 就说明还有一个是已经在的
            cout << n - max(0ll, 1 + m);
        }
    }
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