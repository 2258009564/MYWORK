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
    int n;
    cin >> n;
    int k = 0;
    /*
    & 保留所有的进位
    | 保留所有的1
    n = 5
    000
    10010 and
    10001 or
    10000 and
    01111 or
    10101 and
    */
    /*

    0100 and
    0111 or
    0110 and
    1000 (1 << 31 - __builtin_clz(n))
    1010 n
    0101
    */
    // 对于奇数位的 需要前面有一样的 才能让答案最大化
    // 对于偶数位 可以让前面有不一样的 这样答案都可以最大化
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