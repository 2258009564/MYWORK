//#pragma GCC optimize(2)
#include <bits/stdc++.h>
using namespace std;
#define int long long
#define endl '\n'

const int INF = 1e9;     // 无穷大
const int INFLL = 1e18; // 长整型无穷大
const int MOD = 1e9 + 7; // 模数

void solve()
{
    int l, r;
    cin >> l >> r;
    cout << r - l + 1;
    /*
    在二进制下 观察 + & | ^ 这四个运算
    &记录了所有进位的地方 |记录所有不进位的地方
    这两个相加 就有： (a & b) + (a | b) == a + b 恒成立
    因此 a ^ b 是多余的 所以有 a ^ b == 0 => a == b
    */
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