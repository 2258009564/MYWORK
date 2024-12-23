#include <bits/stdc++.h>
using namespace std;

/*
 * @lc app=leetcode.cn id=55 lang=cpp
 * @lcpr version=20000
 *
 * [55] 跳跃游戏
 */

// @lcpr-template-start

// @lcpr-template-end
// @lc code=start
class Solution
{
public:
    bool canJump(vector<int> &nums)
    {
        int n = nums.size();
        vector<int> dp(n, 0);
        dp[0] = 1;
        // nums[i] = 可以跳跃的最大长度
        for (int i = 0; i < n; i++)
        {
            if (dp[i])  
            {
                for (int j = 1; j <= nums[i]; j++)
                {
                    if (i + j < n)  
                    {
                        dp[i + j] = true;
                    }
                }
            }
        }
        return dp[n - 1];
    }
};
// @lc code=end

/*
// @lcpr case=start
// [2,3,1,1,4]\n
// @lcpr case=end

// @lcpr case=start
// [3,2,1,0,4]\n
// @lcpr case=end

 */
