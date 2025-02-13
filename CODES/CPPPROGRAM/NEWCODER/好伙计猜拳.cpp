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
    int n, c1, c2;
    cin >> n >> c1 >> c2;
    vector v(n, vector<int>(2));
    for (int i = 0; i < n; i++)
    {
        cin >> v[i][0] >> v[i][1];
    }
    int ans = n * c1; // 全部删掉 这样就可以挣钱了！(bushi)
    vector dp(n, vector<int>(2));
    // dp[i][0]表示第i个记录不翻转, dp[i][1]表示翻转
    int ans1 = 0ll, ans2 = 0ll;
    for (int i = 0; i < n; i++)
    {
        dp[i][0] = c1; // 把i安稳地放在这里我们可以得到多少呢？直接放可以获得c1, 反过来放可以获得c1 - c2 为啥？
        dp[i][1] = max(0ll, c1 - c2);
        for (int j = 0; j < i; j++)
        {
            if (v[i][0] >= v[j][0] and v[i][1] >= v[j][1])
            {
                // 不用翻转
                dp[i][0] = max(dp[i][0], dp[j][0] + c1), dp[i][1] = max(dp[i][1], dp[j][1] + c1 - c2);
            }
            if (v[i][0] >= v[j][1] and v[i][1] >= v[j][0])
            {
                // 需要翻转
                dp[i][1] = max(dp[i][1], dp[j][0] + c1 - c2), dp[i][0] = max(dp[j][1] + c1, dp[i][0]);
            }
        }
        ans1 = max(ans1, dp[i][0]), ans2 = max(ans2, dp[i][1]);
    }
    cout << ans - max(ans1, ans2);
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