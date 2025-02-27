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
    int n, x, k;
    cin >> n >> x >> k;
    string s;
    cin >> s;
    int t1 = -1, t2 = -1; // t1 是 第一次到达出发点的时间 t2 是 第一次到达0 的时间
    int pre = 0;          // 记录偏移量
    for (int i = 1; i <= n; i++)
    {
        pre += (s[i - 1] == 'R' ? 1 : -1);
        if (t1 == -1 and pre == 0) // 第一次到出发点
        {
            t1 = i;
        }
        if (t2 == -1 and pre + x == 0) // 第一次到达0
        {
            t2 = i;
        }

        if (t1 != -1 and t2 != -1) // 剪枝
        {
            break;
        }
    }

    if (t2 == -1) // 未能经过0
    {
        cout << 0;
        return;
    }

    if (t1 == -1) // 未能经过出发点
    {
        cout << 1;
        return;
    }
    cout << 1 + (k - t2) / t1;
}

signed main()
{
    cin.tie(0)->ios::sync_with_stdio(0);
    cout << setiosflags(ios::fixed) << setprecision(2);
    int TT = 1;
    cin >> TT;
    while (TT--)
    {
        solve();
        cout << endl;
    }
}