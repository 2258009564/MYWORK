#include <bits/stdc++.h>
using namespace std;

/*
 * @lc app=leetcode.cn id=35 lang=cpp
 * @lcpr version=20001
 *
 * [35] 搜索插入位置
 */

// @lcpr-template-start

// @lcpr-template-end
// @lc code=start
class Solution
{
public:
    int searchInsert(vector<int> &nums, int target)
    {
        // auto n = nums.size();
        // int l = 0, r = n - 1, m, ans;
        // while (l <= r)
        // {
        //     m = l + (r - l) / 2;
        //     if (nums[m] == target)
        //     {
        //         return m;
        //     }
        //     else if (nums[m] > target)
        //     {
        //         r = m - 1;
        //     }
        //     else
        //     {
        //         l = m + 1;
        //     }
        // }
        // return l;
        return ranges::lower_bound(nums, target) - nums.begin();
    }
};
// @lc code=end

/*
// @lcpr case=start
// [1,3,5,6]\n5\n
// @lcpr case=end

// @lcpr case=start
// [1,3,5,6]\n2\n
// @lcpr case=end

// @lcpr case=start
// [1,3,5,6]\n7\n
// @lcpr case=end

 */
