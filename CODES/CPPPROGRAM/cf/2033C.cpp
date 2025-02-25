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
    vector<int> v(n + 1, 0);
    for (int i = 1; i <= n; i++)
        cin >> v[i];

    // 固定v[1] 和 v[n]  这样我们第一步处理就是处理 v[1] v[2] 以及 v[n - 1] v[n] 之间的关系 不需要考虑他们之后的结构 达到贪心的目的

    for (int i = 2; i <= n / 2; i++)
    {
        if (v[i] == v[i - 1] or v[n + 1 - i] == v[n + 2 - i])
        {
            swap(v[i], v[n + 1 - i]);
        }
    }

    int ans = 0;
    for (int i = 1; i + 1 <= n; i++)
        ans += v[i] == v[i + 1];

    cout << ans;
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