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
    vector<pair<int, int>> v(n + 1);
    for (int i = 1; i <= n; i++)
    {
        cin >> v[i].first >> v[i].second;
    }

    vector dp(n + 1, vector<int>(2, 0)); // 在原有的dp上加一维

    auto dist = [&](int i, int j) -> int
    {
        return abs(i - j);
    };

    dp[1][0] = dist(1, v[1].second) + dist(v[1].first, v[1].second);
    dp[1][1] = dist(v[1].second, 1);

    for (int i = 2; i <= n; i++)
    {
        dp[i][0] = min(dp[i - 1][0] + dist(v[i - 1].first, v[i].second) + dist(v[i].second, v[i].first), dp[i - 1][1] + dist(v[i - 1].second, v[i].second) + dist(v[i].second, v[i].first)) + 1;

        dp[i][1] = min(dp[i - 1][0] + dist(v[i - 1].first, v[i].first) + dist(v[i].second, v[i].first), dp[i - 1][1] + dist(v[i - 1].second, v[i].first) + dist(v[i].second, v[i].first)) + 1;
    }

    cout << min(dp[n][0] + dist(n, v[n].first), dp[n][1] + dist(n, v[n].second));
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