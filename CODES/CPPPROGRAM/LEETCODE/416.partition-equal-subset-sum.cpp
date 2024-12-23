#include <bits/stdc++.h>
using namespace std;
#include <numeric>
#include <ranges>

/*
 * @lc app=leetcode.cn id=416 lang=cpp
 * @lcpr version=20001
 *
 * [416] 分割等和子集
 */

// @lcpr-template-start
using namespace std;
#include <bits/stdc++.h>
// @lcpr-template-end
// @lc code=start
class Solution
{
public:
    bool canPartition(vector<int> &nums)
    {
        int sum = accumulate(nums.begin(), nums.end(), 0);
        int sum1 = sum / 2;
        if (sum1 * 2 != sum)
        {
            return 0;
        }
        int n = nums.size();
        vector<vector<int>> dp(n, vector<int>(sum1 + 1, 0));

        // dp[i][j]: 前i个元素任选， 总和不超过j
        // attribute: max
        for (int v = nums[0]; v <= sum1; v++)
        {
            dp[0][v] = nums[0];
        }

        for (int i = 1; i < n; i++)
        {
            for (int j = 1; j <= sum1; j++)
            {
                if (j >= nums[i])
                {
                    dp[i][j] = max(dp[i - 1][j], dp[i - 1][j - nums[i]] + nums[i]);
                }
                else
                {
                    dp[i][j] = dp[i - 1][j];
                }
            }
        }
        return dp[n - 1][sum1] == sum1;
    }
};
// @lc code=end

/*
// @lcpr case=start
// [1,5,11,5]\n
// @lcpr case=end

// @lcpr case=start
// [1,2,3,5]\n
// @lcpr case=end

 */
