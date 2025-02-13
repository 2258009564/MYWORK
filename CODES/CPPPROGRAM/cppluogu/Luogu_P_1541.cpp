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
    int n, m;
    cin >> n >> m;
    vector<int> grid(n + 1, 0), nums(5, 0);
    for (int i = 1; i <= n; i++)
    {
        cin >> grid[i];
    }
    for (int i = 1; i <= m; i++)
    {
        int num;
        cin >> num;
        nums[num]++;
    }
    vector dp(nums[1] + 1, vector(nums[2] + 1, vector(nums[3] + 1, vector<int>(nums[4] + 1, 0))));
    // 多重背包？
    dp[0][0][0][0] = grid[1];
    for (int i = 0; i <= nums[1]; i++)
    {
        for (int j = 0; j <= nums[2]; j++)
        {
            for (int k = 0; k <= nums[3]; k++)
            {
                for (int l = 0; l <= nums[4]; l++)
                {
                    int x = 1 + i + 2 * j + 3 * k + 4 * l;
                    if (i - 1 >= 0)
                    {
                        dp[i][j][k][l] = max(dp[i][j][k][l], dp[i - 1][j][k][l] + grid[x]);
                    }
                    if (j - 1 >= 0)
                    {
                        dp[i][j][k][l] = max(dp[i][j][k][l], dp[i][j - 1][k][l] + grid[x]);
                    }
                    if (k - 1 >= 0)
                    {
                        dp[i][j][k][l] = max(dp[i][j][k][l], dp[i][j][k - 1][l] + grid[x]);
                    }
                    if (l - 1 >= 0)
                    {
                        dp[i][j][k][l] = max(dp[i][j][k][l], dp[i][j][k][l - 1] + grid[x]);
                    }
                }
            }
        }
    }

    cout << dp[nums[1]][nums[2]][nums[3]][nums[4]];
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