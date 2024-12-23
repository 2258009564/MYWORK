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
        // 找到第一个 >= target 的元素
        // auto lower = lower_bound(nums.begin(), nums.end(), target);
        // // 找到第一个 > target 的元素
        // auto upper = upper_bound(nums.begin(), nums.end(), target);

        // // 检查目标值是否存在
        // if (lower == nums.end() || *lower != target)
        // {
        //     return {-1, -1};
        // }

        // // 计算起始和结束位置
        // int start = distance(nums.begin(), lower);
        // int end = distance(nums.begin(), upper) - 1;

        // return {start, end};

        int lf = 0, ri = nums.size() - 1;
        while (lf <= ri)
        {
            int mid = lf + (ri - lf) / 2;
            if (nums[mid] > target)
            {
                ri = mid - 1;
            }
            else if (nums[mid] < target)
            {
                lf = mid + 1;
            }
            else
            {
                // 找到目标值后，分别向左和向右扩展，找到边界
                int start = mid, end = mid;

                // 向左扩展查找起始位置
                while (start > 0 && nums[start - 1] == target)
                {
                    start--;
                }

                // 向右扩展查找结束位置
                while (end < nums.size() - 1 && nums[end + 1] == target)
                {
                    end++;
                }

                return {start, end};
            }
        }
        return {-1, -1};
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
