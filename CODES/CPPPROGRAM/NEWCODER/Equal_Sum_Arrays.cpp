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
    if (n == 1)
    {
        cout << 1;
        return;
    }
    int ans = 0;
    function<void(int)> dfs = [&](int sum)
    {
        if (sum >= n)
        {
            if (sum == n)
            {
                ans++;
            }
            return;
        }

        for (int i = 1; i + sum <= n; i++)
        {
            // cout << i << ' ' << sum << endl;
            dfs(sum + i);
        }
    };
    dfs(0);
    cout << ans;
}

signed main()
{
    cin.tie(0)->ios::sync_with_stdio(0);
    cout << setiosflags(ios::fixed) << setprecision(2);
    int TT = 1;
    // cin >> TT;
    while (TT--)
    {
        solve();
        cout << endl;
    }
}