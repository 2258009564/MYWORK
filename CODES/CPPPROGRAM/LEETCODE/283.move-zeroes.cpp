#include <bits/stdc++.h>
using namespace std;

/*
 * @lc app=leetcode.cn id=283 lang=cpp
 * @lcpr version=20001
 *
 * [283] 移动零
 */

// @lcpr-template-start

// @lcpr-template-end
// @lc code=start
class Solution
{
public:
    void moveZeroes(vector<int> &nums)
    {
        int slow = 0, fast = 0;
        while(slow<=fast&&fast<nums.size()){
            
            if(nums[fast]!=0){
                nums[slow] = nums[fast];
                slow++;
            }
            fast++;
        }
        while (slow < nums.size())
        {
            nums[slow] = 0;
            slow++;
        }
    }
};
// @lc code=end

/*
// @lcpr case=start
// [0,1,0,3,12]\n
// @lcpr case=end

// @lcpr case=start
// [0]\n
// @lcpr case=end

 */
