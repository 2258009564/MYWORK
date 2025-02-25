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
    vector<int> v(n);
    for (int i = 0; i < n; i++)
        cin >> v[i];
    vector<int> pre(n + 1, 0);
    partial_sum(all(v), pre.begin() + 1);
    // 0   1   2   3   4
    // 1 + 2 + 3 + 4 + 5
    // 那么 4 + 5 其实就是 总和 - (1 + 2 + 3)
    /*
    定义 pre[i] 是 前i个元素的前缀和
    那么 pre[3] = v[0] + v[1] + v[2]
    那么 要求的 v[4] + v[5] = pre[5] - pre[3]
    */

    int l = 1, r = n, m, ans = INF, index;
    while (l <= r)
    {
        m = l + (r - l) / 2;
        if (pre[m] - (pre[n] - pre[m]) >= 0)
        {
            index = m;
            r = m - 1;
        }
        else
        {
            l = m + 1;
        }
    }

cout << min(abs(pre[index] - (pre[n] - pre[index])), abs(pre[index - 1] - (pre[n] - pre[index - 1])));
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