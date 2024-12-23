#include <bits/stdc++.h>
using namespace std;
#define int long long
#define endl '\n'

/*
 * @lc app=leetcode.cn id=343 lang=cpp
 * @lcpr version=20003
 *
 * [343] 整数拆分
 */

// @lcpr-template-start

// @lcpr-template-end
// @lc code=start
class Solution
{
public:
    int integerBreak(int n)
    {
        if (n == 2)
        {
            return 1;
        }
        // dp[i]: 把i拆分为若干个正整数的和 的 乘积 的 集合
        // 属性：max

        // dp[i] 可以是
        vector<int> dp(n + 1, 0);
        dp[2] = 1;
        for (int i = 3; i <= n; i++)
        {
            for (int j = 1; j <= i / 2; j++)
            {
                dp[i] = max({dp[i], dp[i - j] * j, (i - j) * j});
            }
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
// 10\n
// @lcpr case=end

 */
