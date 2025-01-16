#include <bits/stdc++.h>
using namespace std;
#define int long long
#define endl '\n'

/*
 * @lc app=leetcode.cn id=2563 lang=cpp
 * @lcpr version=20004
 *
 * [2563] 统计公平数对的数目
 */

// @lcpr-template-start

// @lcpr-template-end
// @lc code=start
class Solution
{
public:
    long long countFairPairs(vector<int> &nums, int lower, int upper)
    {
        ranges::sort(nums);

        // nums[i]  >= lower - nums[j]
        // nums[i]  <= upper - nums[j]

        long long ans = 0;

        for (int j = 0; j < nums.size(); j++)
        {
            auto l = lower_bound(nums.begin(), nums.begin() + j, lower - nums[j]);
            auto r = upper_bound(nums.begin(), nums.begin() + j, upper - nums[j]);

            ans += r - l;
        }
        return ans;
    }
};
// @lc code=end

/*
// @lcpr case=start
// [0,1,7,4,4,5]\n3\n6\n
// @lcpr case=end

// @lcpr case=start
// [1,7,9,2,5]\n11\n11\n
// @lcpr case=end

 */
