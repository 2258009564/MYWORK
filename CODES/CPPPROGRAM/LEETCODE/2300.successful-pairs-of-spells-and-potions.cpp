#include <bits/stdc++.h>
using namespace std;
#define int long long
#define endl '\n'

/*
 * @lc app=leetcode.cn id=2300 lang=cpp
 * @lcpr version=20004
 *
 * [2300] 咒语和药水的成功对数
 */

// @lcpr-template-start

// @lcpr-template-end
// @lc code=start
class Solution
{
public:
    vector<int> successfulPairs(vector<int> &spells, vector<int> &potions, long long success)
    {
        ranges::sort(potions);

        vector<int> pairs;

        for (auto &&i : spells)
        {
            auto it = ranges::lower_bound(potions, (success + i - 1) / i);

            pairs.push_back(potions.end() - it);
        }
        return pairs;
    }
};
// @lc code=end

/*
// @lcpr case=start
// [5,1,3]\n[1,2,3,4,5]\n7\n
// @lcpr case=end

// @lcpr case=start
// [3,1,2]\n[8,5,8]\n16\n
// @lcpr case=end

 */
