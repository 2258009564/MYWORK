#include <bits/stdc++.h>
using namespace std;
#define int long long
#define endl '\n'

/*
 * @lc app=leetcode.cn id=518 lang=cpp
 * @lcpr version=20003
 *
 * [518] 零钱兑换 II
 */

// @lcpr-template-start

// @lcpr-template-end
// @lc code=start
class Solution
{
public:
    int change(int amount, vector<int> &coins)
    {
        vector<int> dp(amount + 1, 0);
        dp[0] = 1; // 只有一种方式达到0
        for (int i = 0; i < coins.size(); i++)
        { // 遍历物品
            for (int j = coins[i]; j <= amount; j++)
            { // 遍历背包
                if (dp[j] < INT_MAX - dp[j - coins[i]])
                { // 防止相加数据超int
                    dp[j] += dp[j - coins[i]];
                }
            }
        }
        return dp[amount]; // 返回组合数
    }
};
// @lc code=end

/*
// @lcpr case=start
// 5\n[1, 2, 5]\n
// @lcpr case=end

// @lcpr case=start
// 3\n[2]\n
// @lcpr case=end

// @lcpr case=start
// 10\n[10]\n
// @lcpr case=end

 */
