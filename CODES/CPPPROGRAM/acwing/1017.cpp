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
    int n;
    cin >> n;
    vector<int> v(n);
    for (int i = 0; i < n; i++)
    {
        cin >> v[i];
    }

    // 其实是一个最长上升子序列模型
    vector<int> dp(n, 1); // 表示以dp[i]结尾 最长的上升子序列

    for (int i = 1; i < n; i++)
    {
        for (int j = 0; j < i; j++)
        {
            if (v[i] > v[j])
            {
                dp[i] = max(dp[i], dp[j] + 1);
            }
        }
    }
    auto ans = ranges::max(dp);
    ranges::reverse(v);
    ranges::fill(dp, 1ll);
    for (int i = 1; i < n; i++)
    {
        for (int j = 0; j < i; j++)
        {
            if (v[i] > v[j])
            {
                dp[i] = max(dp[i], dp[j] + 1);
            }
        }
    }
    ans = max(ans, ranges::max(dp));
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