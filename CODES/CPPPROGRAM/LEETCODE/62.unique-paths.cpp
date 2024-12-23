#include <bits/stdc++.h>
using namespace std;

/*
 * @lc app=leetcode.cn id=62 lang=cpp
 * @lcpr version=20000
 *
 * [62] 不同路径
 */

// @lcpr-template-start
using namespace std;
#include <bits/stdc++.h>
// @lcpr-template-end
// @lc code=start
class Solution
{
public:
    int uniquePaths(int m, int n)
    {
        if (m == 1 or n == 1)
        {
            return 1;
        }
        vector<vector<int>> dp(m, vector<int>(n, 0)); // dp[i][j]: 到(i, j) 的路径总数
        for (int i = 0; i < m; i++)
        {
            dp[i][0] = 1;
        }
        for (int i = 0; i < n; i++)
        {
            dp[0][i] = 1;
        }
        for (int i = 1; i < m; i++)
        {
            for (int j = 1; j < n; j++)
            {
                dp[i][j] = dp[i - 1][j] + dp[i][j - 1];
            }
        }
        return dp[m - 1][n - 1];
    }
};
// @lc code=end

/*
// @lcpr case=start
// 3\n7\n
// @lcpr case=end

// @lcpr case=start
// 3\n2\n
// @lcpr case=end

// @lcpr case=start
// 7\n3\n
// @lcpr case=end

// @lcpr case=start
// 3\n3\n
// @lcpr case=end

 */
