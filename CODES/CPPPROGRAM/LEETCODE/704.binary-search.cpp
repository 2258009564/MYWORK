#include <bits/stdc++.h>
using namespace std;

/*
 * @lc app=leetcode.cn id=704 lang=cpp
 * @lcpr version=20001
 *
 * [704] 二分查找
 */

// @lcpr-template-start
// @lcpr-template-end
// @lc code=start
class Solution
{
public:
    int search(vector<int> &nums, int target)
    {
        // int r = nums.size() - 1, l = 0, m;
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
        // return -1;
        auto num = ranges::lower_bound(nums, target) - nums.begin();
        return (num != nums.size() and nums[num] == target ? num : -1);
    }
};
// @lc code=end

/*
// @lcpr case=start
// [-1,0,3,5,9,12]\n9\n
// @lcpr case=end

// @lcpr case=start
// [-1,0,3,5,9,12]\n2\n
// @lcpr case=end

 */
