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
    if (n == 1 or n == 3)
    {
        cout << -1;
        return;
    }

    if (n % 2 == 0)
    {
        string s(n - 2, '3');
        cout << s << 66;
    }
    else
    {
        string s(n - 4, '3');
        cout << s << 6366;
    }
}

signed main()
{
    cin.tie(nullptr)->sync_with_stdio(false);
    int TT = 1;
    cin >> TT;
    while (TT--)
    {
        solve();
        cout << endl;
    }
}