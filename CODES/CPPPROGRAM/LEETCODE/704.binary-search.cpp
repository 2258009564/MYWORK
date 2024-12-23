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
        // 双指针
        int lf = 0, ri = nums.size() - 1;
        while(lf<=ri){
            //设置的是闭区间 所以=有意义
            int mid = lf + (ri - lf) / 2;
            if(nums[mid]>target){
                ri = mid - 1;
            }else if(nums[mid]<target){
                lf = mid + 1;
            }else{
                return mid;
            }
        }
        return -1;
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
