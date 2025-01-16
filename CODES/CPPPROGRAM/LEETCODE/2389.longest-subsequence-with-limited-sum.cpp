#include <bits/stdc++.h>
using namespace std;
#define int long long
#define endl '\n'

/*
 * @lc app=leetcode.cn id=2389 lang=cpp
 * @lcpr version=20004
 *
 * [2389] 和有限的最长子序列
 */

// @lcpr-template-start

// @lcpr-template-end
// @lc code=start
class Solution
{
public:
    vector<int> answerQueries(vector<int> &nums, vector<int> &queries)
    {
        ranges::sort(nums);

        partial_sum(nums.begin(), nums.end(), nums.begin());

        for (auto &&q : queries)
        {
            q = ranges::upper_bound(nums, q) - nums.begin();
        }
        return queries;
    }
};
// @lc code=end

/*
// @lcpr case=start
// [4,5,2,1]\n[3,10,21]\n
// @lcpr case=end

// @lcpr case=start
// [2,3,4,5]\n[1]\n
// @lcpr case=end

 */
