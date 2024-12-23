#include <bits/stdc++.h>
using namespace std;

/*
 * @lc app=leetcode.cn id=45 lang=cpp
 * @lcpr version=20000
 *
 * [45] 跳跃游戏 II
 */

// @lcpr-template-start
using namespace std;
#include <bits/stdc++.h>
// @lcpr-template-end
// @lc code=start
class Solution
{
public:
    int jump(vector<int> &nums)
    {
        int n = nums.size();
        //dp[i]表示到达dp[i]的最小跳跃次数
        vector<int> dp(n, INT_MAX);
        //nums[i] = 从i向前跳转的最大长度
        dp[0] = 0;
        //从0到0不需要跳跃
        for (int i = 0; i < n;i++){
            for (int j = 0; i + j < n && j <= nums[i];j++){
                dp[i + j] = min(dp[i + j], dp[i] + 1);
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
// [2,3,0,1,4]\n
// @lcpr case=end

 */
