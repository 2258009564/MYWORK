#include <bits/stdc++.h>
using namespace std;
#define int long long
#define endl '\n'

/*
 * @lc app=leetcode.cn id=2529 lang=cpp
 * @lcpr version=20004
 *
 * [2529] 正整数和负整数的最大计数
 */

// @lcpr-template-start

// @lcpr-template-end
// @lc code=start
class Solution
{
public:
    int maximumCount(vector<int> &nums)
    {
        int a = ranges::lower_bound(nums, 0) - nums.begin();

        int b = nums.end() - ranges::upper_bound(nums, 0);
        return max(a, b);
    }
};
// @lc code=end

/*
// @lcpr case=start
// [-2,-1,-1,1,2,3]\n
// @lcpr case=end

// @lcpr case=start
// [-3,-2,-1,0,0,1,2]\n
// @lcpr case=end

// @lcpr case=start
// [5,20,66,1314]\n
// @lcpr case=end

 */
