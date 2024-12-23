#include <bits/stdc++.h>
using namespace std;
#define int long long
#define endl '\n'

/*
 * @lc app=leetcode.cn id=494 lang=cpp
 * @lcpr version=20004
 *
 * [494] 目标和
 */

// @lcpr-template-start

// @lcpr-template-end
// @lc code=start
class Solution
{
public:
    int findTargetSumWays(vector<int> &nums, int target)
    {
        int sum = 0;
        for (int i = 0; i < nums.size(); i++)
            sum += nums[i];
        if ((abs(target) > sum) or ((target + sum) % 2 == 1))
        {
            return 0;
        }
        int bagSize = (target + sum) / 2;
        vector<int> dp(bagSize + 1, 0);
        dp[0] = 1;
        for (int i = 0; i < nums.size(); i++)
        {
            for (int j = bagSize; j >= nums[i]; j--)
            {
                dp[j] += dp[j - nums[i]];
            }
        }
        return dp[bagSize];
    }
};
// @lc code=end

/*
// @lcpr case=start
// [1,1,1,1,1]\n3\n
// @lcpr case=end

// @lcpr case=start
// [1]\n1\n
// @lcpr case=end

 */
