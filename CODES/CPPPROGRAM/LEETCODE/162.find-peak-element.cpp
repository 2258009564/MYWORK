#include <bits/stdc++.h>
using namespace std;
#define int long long
#define endl '\n'

/*
 * @lc app=leetcode.cn id=162 lang=cpp
 * @lcpr version=20004
 *
 * [162] 寻找峰值
 */

// @lcpr-template-start

// @lcpr-template-end
// @lc code=start
class Solution
{
public:
    int findPeakElement(vector<int> &nums)
    {
        // 首先检查nums.front() 和 nums.back()
        auto n = nums.size();

        if (n == 1)
        {
            return 0; // 特
        }

        if (nums[0] > nums[1])
        {
            return 0;
        }
        if (nums[n - 1] > nums[n - 2])
        {
            return n - 1;
        }

        // 现在已经确定 [1, n - 2] 中一定有极值点 可以开始二分搜索

        int l = 1, r = n - 2, mid;

        while(l <= r)
        {
            mid = l + (l - l) / 2;

            // 判断是不是极值点 要看nums[mid]和相邻左右的关系

            if (nums[mid] > nums[mid - 1] and nums[mid] > nums[mid + 1])
            {
                return mid;
            }
            else
            {
                if (nums[mid] < nums[mid - 1])
                {
                    // 左边呈上升趋势 缩短右边界 在左边查找
                    r = mid - 1;
                }
                else
                {
                    // 缩短左边界 在右边查找
                    l = mid + 1;
                }
            }
        }
        return mid;
    }
};
// @lc code=end

/*
// @lcpr case=start
// [1,2,3,1]\n
// @lcpr case=end

// @lcpr case=start
// [1,2,1,3,5,6,4]\n
// @lcpr case=end

 */
