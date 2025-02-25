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
    // 每一座桥需要n块木板 问能弄n座桥的最少木板数量
    // 第一座桥需要长度为 18 的 n 块木板，第二座桥需要长度为 21 的 n 块木板，最后一座桥需要长度为 25 的 n 块木板
    // dp[i][j][k] 表示当前木板数量分别是i, j, k块 需要的最少木板数量

    int a = n, b = n, c = n;
    int ans = 0;
    
}

signed main()
{
    cin.tie(nullptr)->ios::sync_with_stdio(false);
    cout << setiosflags(ios::fixed) << setprecision(2);
    int TT = 1;
    // cin >> TT;
    while (TT--)
    {
        solve();
        cout << endl;
    }
}