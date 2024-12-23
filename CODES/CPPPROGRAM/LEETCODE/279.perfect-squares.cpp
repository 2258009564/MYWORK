#include <bits/stdc++.h>
using namespace std;
#define int long long
#define endl '\n'

/*
 * @lc app=leetcode.cn id=279 lang=cpp
 * @lcpr version=20004
 *
 * [279] 完全平方数
 */

// @lcpr-template-start

// @lcpr-template-end
// @lc code=start
class Solution
{
public:
    int numSquares(int n)
    {
        std::vector<int> dp(n + 1, INT_MAX);
        dp[0] = 0;
        for (int i = 0; i <= n; i++)
        {
            for (int j = 1; j * j <= i; j++)
            {
                dp[i] = std::min(dp[i - j * j] + 1, dp[i]);
            }
        }
        return dp[n];
    }
};
// @lc code=end

/*
// @lcpr case=start
// 12\n
// @lcpr case=end

// @lcpr case=start
// 13\n
// @lcpr case=end

 */
