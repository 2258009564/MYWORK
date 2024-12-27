#include <bits/stdc++.h>
using namespace std;
#define int long long
#define endl '\n'

/*
 * @lc app=leetcode.cn id=239 lang=cpp
 * @lcpr version=20004
 *
 * [239] 滑动窗口最大值
 */

// @lcpr-template-start

// @lcpr-template-end
// @lc code=start
class Solution
{
public:
    vector<int> maxSlidingWindow(vector<int> &nums, int k)
    {
        deque<int> deq;
        for (int i = 0; i < k; i++)
        {
            deq.push_back(nums[i]);
            while (deq.front() > nums[i])
            {
                deq.pop_front();
            }
        }
        vector<int> v;
        v.push_back(deq.front());

        for (int i = k; i < nums.size(); i++)
        {
            deq.push_back(nums[i]);
            while (deq.front() > nums[i])
            {
                deq.pop_front();
            }
            v.push_back(deq.front());
        }
    }
};
// @lc code=end

/*
// @lcpr case=start
// [1,3,-1,-3,5,3,6,7]\n3\n
// @lcpr case=end

// @lcpr case=start
// [1]\n1\n
// @lcpr case=end

 */
