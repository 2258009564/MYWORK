#include <bits/stdc++.h>
using namespace std;

/*
 * @lc app=leetcode.cn id=977 lang=cpp
 * @lcpr version=20001
 *
 * [977] 有序数组的平方
 */

// @lcpr-template-start

// @lcpr-template-end
// @lc code=start
class Solution
{
public:
    vector<int> sortedSquares(vector<int> &nums)
    {
        int left = 0, right = nums.size() - 1;

        vector<int> result(nums.size(), 0);
        int n = nums.size() - 1;
        while (left <= right)
        {
            if (nums[left] * nums[left] < nums[right] * nums[right])
            {
                result[n--] = nums[right] * nums[right];
                right--;
            }
            else
            {
                result[n--] = nums[left] * nums[left];
                left++;
            }
        }
        return result;
    }
};
// @lc code=end

/*
// @lcpr case=start
// [-4,-1,0,3,10]\n
// @lcpr case=end

// @lcpr case=start
// [-7,-3,2,3,11]\n
// @lcpr case=end

 */
