#include <bits/stdc++.h>
using namespace std;
#define int long long
#define endl '\n'

/*
 * @lc app=leetcode.cn id=377 lang=cpp
 * @lcpr version=20003
 *
 * [377] 组合总和 Ⅳ
 */

// @lcpr-template-start

// @lcpr-template-end
// @lc code=start
class Solution
{
public:
    int combinationSum4(vector<int> &nums, int target)
    {
        vector<int> dp(target + 1, 0);
        // dp[i]: 大小为i的背包装满的方法总数
        // 初始化 dp[0]就是 大小为0的背包 装满只有一种方法
        dp[0] = 1;
        
        for (int i = 0; i < nums.size(); i++)
        {
            for (int j = nums[i]; j <= target; j++)
            {
                dp[j] += dp[j - nums[i]];
            }
        }
        return dp[target];
    }
};
// @lc code=end

/*
// @lcpr case=start
// [1,2,3]\n4\n
// @lcpr case=end

// @lcpr case=start
// [9]\n3\n
// @lcpr case=end

 */
