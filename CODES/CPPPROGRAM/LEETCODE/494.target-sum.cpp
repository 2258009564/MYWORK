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
        int sum = accumulate(nums.begin(), nums.end(), 0ll);
        // left - right = target
        // left + right = sum
        // right = sum - left
        // left = (target + sum) / 2
        // 转化为01背包
        vector<int> dp((target + sum) / 2 + 1, 0ll); // dp[i] 背包容量为i的时候能装的方法总数
        for (int i = 0; i < nums.size(); i++)
        {
            for (int j = (target + sum) / 2; j >= nums[i]; j--)
            {
                dp[j] += dp[j - nums[i]] + nums[i];
            }
        }
        return dp.back();
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
