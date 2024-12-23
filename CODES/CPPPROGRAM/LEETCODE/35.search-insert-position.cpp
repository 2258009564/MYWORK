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
        int lf = 0, ri = nums.size() - 1;
        while(lf<=ri){
            int mid = lf + (ri - lf) / 2;
            if(nums[mid]>target){
                ri = mid - 1;
            }
            else if(nums[mid]<target){
                lf = mid + 1;
            }else{
                return mid;
            }
        }
        return lf;//只需要思考细节就行了
        // 也可以return ri + 1;
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
