#include <bits/stdc++.h>
using namespace std;

/*
 * @lc app=leetcode.cn id=746 lang=cpp
 * @lcpr version=20001
 *
 * [746] 使用最小花费爬楼梯
 */

// @lcpr-template-start
using namespace std;
#include <bits/stdc++.h>
// @lcpr-template-end
// @lc code=start
class Solution
{
public:
    int minCostClimbingStairs(vector<int> &cost)
    {
        int s = cost.size();
        vector<int> dp(s + 1, 0);
        dp[0] = dp[1] = 0;
        // dp[i]: 到i的最低花费
        for (int i = 2; i <= s; i++)
        {
            dp[i] = min(dp[i - 1] + cost[i - 1], dp[i - 2] + cost[i - 2]);
        }
        return dp[s];
    }
};
// @lc code=end

/*
// @lcpr case=start
// [10,15,20]\n
// @lcpr case=end

// @lcpr case=start
// [1,100,1,1,1,100,1,1,100,1]\n
// @lcpr case=end

 */
