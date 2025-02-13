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
    int m, s, t;
    cin >> m >> s >> t;

    int v = 17;

    vector<int> dp(t + 1, 0); // dp[i] 第i秒最多的距离

    for (int i = 1; i <= t; i++)
    {
        if (m >= 10)
        {
            dp[i] = dp[i - 1] + 60;
            m -= 10;
        }
        else
        {
            dp[i] = dp[i - 1];
            m += 4;
        }
    }

    for (int i = 1; i <= t; i++)
    {
        dp[i] = max(dp[i], dp[i - 1] + 17);
    }

    for (int i = 1; i <= t; i++)
    {
        if (dp[i] >= s)
        {
            cout << "Yes" << endl
                 << i;
            return;
        }
    }
    cout << "No" << endl
         << dp[t];
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