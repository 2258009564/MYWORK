#include <bits/stdc++.h>
using namespace std;

/*
 * @lc app=leetcode.cn id=34 lang=cpp
 * @lcpr version=20001
 *
 * [34] 在排序数组中查找元素的第一个和最后一个位置
 */

// @lcpr-template-start

// @lcpr-template-end
// @lc code=start
class Solution
{
public:
    vector<int> searchRange(vector<int> &nums, int target)
    {
        // // 先用二分找到一个
        // auto n = nums.size();
        // int l = 0, r = n - 1, m, ll, rr;
        // bool found = 0;
        // while (l <= r)
        // {
        //     m = l + (r - l) / 2;

        //     if (nums[m] == target)
        //     {
        //         found = 1;
        //         break;
        //     }
        //     else if (nums[m] > target)
        //     {
        //         // 找更小的
        //         r = m - 1;
        //     }
        //     else
        //     {
        //         l = m + 1;
        //     }
        // }
        // if (found)
        // {
        //     ll = m, rr = m;
        //     while (ll - 1 >= 0 and nums[ll - 1] == target)
        //     {
        //         ll--;
        //     }
        //     while (rr + 1 < n and nums[rr + 1] == target)
        //     {
        //         rr++;
        //     }
        //     return {ll, rr};
        // }
        // return {-1, -1};

        int it = ranges::lower_bound(nums, target) - nums.begin();

        if (it == nums.size() or nums[it] != target)
        {
            return {-1, -1};
        }
        else
        {
            int it2 = ranges::upper_bound(nums, target) - 1 - nums.begin();
            return {it, it2};
        }
    }
};
// @lc code=end

/*
// @lcpr case=start
// [5,7,7,8,8,10]\n8\n
// @lcpr case=end

// @lcpr case=start
// [5,7,7,8,8,10]\n6\n
// @lcpr case=end

// @lcpr case=start
// []\n0\n
// @lcpr case=end

 */
