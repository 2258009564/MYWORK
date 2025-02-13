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
    int n, m, k;
    cin >> n >> m >> k; // 分别代表小智的精灵球数量、皮卡丘初始的体力值、野生小精灵的数量。
    vector<int> cost(k + 1, 0), need(k + 1, 0);
    // 小智的目标有两个：主要目标是收服尽可能多的野生小精灵；如果可以收服的小精灵数量一样，小智希望皮卡丘受到的伤害越小（剩余体力越大），因为他们还要继续冒险。
    m--;
    vector dp(n + 1, vector<int>(m + 1, 0)); // dp[i][j] 精灵球总数为i 体力总数为j 捕捉的最多精灵
    dp[0][0] = 0;
    for (int i = 1; i <= k; i++) // 枚举精灵
    {
        // cost[i] 精灵扣血 need[i] 精灵需要精灵球
        for (int j = m; j >= need[i]; j--)
        {
            for (int k = n; k >= cost[i]; k--)
            {
                dp[j][k] = max(dp[j][k], dp[j - need[i]][k - cost[i]] + 1);
            }
        }
    }
    cout << dp[n][m] << ' ';
    int cos = m;
    for (int i = 0; i <= m; i++)
    {
        if (dp[n][i] == dp[n][m])
        {
            cos = min(m, i);
        }
    }
    cout << m + 1 - cos;
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