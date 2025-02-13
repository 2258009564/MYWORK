// #pragma GCC optimize(2)
#include <bits/stdc++.h>
using namespace std;
#define int long long
#define endl '\n'

const int INF = 1e9;     // 无穷大
const int INFLL = 1e18;  // 长整型无穷大
const int MOD = 1e9 + 7; // 模数
// -9.2e18 ~ 9.2e18

void solve()
{
    int x, y;
    cin >> x >> y;
    // y / 2   y / 2 + 1
    // y 加起来一定是偶数
    if (y % 2 == 0)
    {
        cout << "NO";
        return;
    }

    y /= 2;
    cout << (abs(y - x) % 2 == 0 ? "YES" : "NO");
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