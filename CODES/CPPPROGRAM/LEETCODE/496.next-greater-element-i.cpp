#include <bits/stdc++.h>
using namespace std;
#define int long long
#define endl '\n'

/*
 * @lc app=leetcode.cn id=496 lang=cpp
 * @lcpr version=20004
 *
 * [496] 下一个更大元素 I
 */

// @lcpr-template-start

// @lcpr-template-end
// @lc code=start
class Solution
{
public:
    vector<int> nextGreaterElement(vector<int> &nums1, vector<int> &nums2)
    {
        vector<int> result(nums2.size(), -1);

        stack<int> stk;

        for (int i = 0; i < nums2.size(); i++)
        {
            while(!stk.empty() and nums2[stk.top()] < nums2[i])
            {
                result[stk.top()] = nums2[i];
                stk.pop();
            }
            stk.push(i);
        }
        vector<int> ans;

        for (int i = 0; i < nums1.size(); i++)
        {
            ans.push_back(result[i]);
        }
        return ans;
    }
};
// @lc code=end

/*
// @lcpr case=start
// [4,1,2]\n[1,3,4,2].\n
// @lcpr case=end

// @lcpr case=start
// [2,4]\n[1,2,3,4].\n
// @lcpr case=end

 */
