#include <bits/stdc++.h>
using namespace std;

/*
 * @lc app=leetcode.cn id=70 lang=cpp
 * @lcpr version=20001
 *
 * [70] 爬楼梯
 */

// @lcpr-template-start
using namespace std;
#include <bits/stdc++.h>
// @lcpr-template-end
// @lc code=start
class Solution
{
public:
    int climbStairs(int n)
    {
        if(n<3){
            return n;
        }
        vector<int> dp(n+1,0);//dp是从0到n的方法总数
        // 状态转移:dp[i] = dp[i-2]+dp[i-1];
        dp[0] = 0;
        dp[1] = 1;
        dp[2] = 2;
        for (int i = 3; i <= n;i++){
            dp[i] = dp[i - 2] + dp[i - 1];
        }
        return dp[n];
    }
};
// @lc code=end

/*
// @lcpr case=start
// 2\n
// @lcpr case=end

// @lcpr case=start
// 3\n
// @lcpr case=end

 */
