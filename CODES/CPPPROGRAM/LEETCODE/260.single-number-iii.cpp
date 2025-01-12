#include <bits/stdc++.h>
using namespace std;
#define int long long
#define endl '\n'

/*
 * @lc app=leetcode.cn id=260 lang=cpp
 * @lcpr version=20004
 *
 * [260] 只出现一次的数字 III
 */

// @lcpr-template-start

// @lcpr-template-end
// @lc code=start
class Solution
{
public:
    vector<int> singleNumber(vector<int> &nums)
    {
        unsigned xor_nums = 0;
        for (auto &&i : nums)
        {
            xor_nums ^= i;
        }

        int lowbit = xor_nums & (-xor_nums);

        int res1 = 0;
        for (auto &&i : nums)
        {
            if (lowbit & i)
            {
                res1 ^= i;
            }
        }
        return {res1, res1 ^ (int)xor_nums};
    }
};
// @lc code=end

/*
// @lcpr case=start
// [1,2,1,3,2,5]\n
// @lcpr case=end

// @lcpr case=start
// [-1,0]\n
// @lcpr case=end

// @lcpr case=start
// [0,1]\n
// @lcpr case=end

 */
