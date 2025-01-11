#include <bits/stdc++.h>
using namespace std;
#define int long long
#define endl '\n'

/*
 * @lc app=leetcode.cn id=303 lang=cpp
 * @lcpr version=20004
 *
 * [303] 区域和检索 - 数组不可变
 */

// @lcpr-template-start

// @lcpr-template-end
// @lc code=start
class NumArray
{
private:
    vector<int> pre;

public:
    NumArray(vector<int> &nums)
    {
        pre.resize(nums.size());

        partial_sum(nums.begin(), nums.end(), pre.begin());
    }

    int sumRange(int left, int right)
    {
        return pre[right] - (left - 1 >= 0 ? pre[left - 1] : 0);
    }
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(nums);
 * int param_1 = obj->sumRange(left,right);
 */
// @lc code=end

/*
// @lcpr case=start
// ["NumArray", "sumRange", "sumRange", "sumRange"][[[-2, 0, 3, -5, 2, -1]], [0, 2], [2, 5], [0, 5]]\n
// @lcpr case=end

 */
