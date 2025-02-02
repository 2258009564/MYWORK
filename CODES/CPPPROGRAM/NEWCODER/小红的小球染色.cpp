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
    if (n == 1)
    {
        cout << 0 << ' ' << 0;
        return;
    }
    else if (n == 2)
    {
        cout << 1 << ' ' << 1;
        return;
    }
    // min
    int minnum = n / 3;
    if (n % 3 == 2)
    {
        minnum++;
    }
    // max
    int maxnum = n / 2;
    cout << minnum << ' ' << maxnum;
    // 0 0
    // 0 0 0
    // 0 0 0 0
    // 0 0 0 0 0
    // 0 0 0 0 0 0
    // 0 0 0 0 0 0 0 0
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