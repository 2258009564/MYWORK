#include <bits/stdc++.h>
using namespace std;

/*
 * @lc app=leetcode.cn id=167 lang=cpp
 * @lcpr version=20001
 *
 * [167] 两数之和 II - 输入有序数组
 */

// @lcpr-template-start

// @lcpr-template-end
// @lc code=start
class Solution
{
public:
    vector<int> twoSum(vector<int> &numbers, int target)
    {
        int sz = numbers.size();
        int left = 0, right = sz - 1;
        while(left<right){
            int total = numbers[left] + numbers[right];
            if(total<target){
                left++;
            }else if(total>target){
                right--;
            }else{
                return vector<int>{left + 1, right + 1};
            }
        }
        return vector<int>{-1, -1};
    }
};
// @lc code=end

/*
// @lcpr case=start
// [2,7,11,15]\n9\n
// @lcpr case=end

// @lcpr case=start
// [2,3,4]\n6\n
// @lcpr case=end

// @lcpr case=start
// [-1,0]\n-1\n
// @lcpr case=end

 */
