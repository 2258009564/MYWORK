#include <bits/stdc++.h>
using namespace std;
#define endl '\n'

/*
 * @lc app=leetcode.cn id=3185 lang=cpp
 * @lcpr version=20002
 *
 * [3185] 构成整天的下标对数目 II
 */

// @lcpr-template-start

// @lcpr-template-end
// @lc code=start
class Solution
{
public:
    long long countCompleteDayPairs(vector<int> &hours)
    {
        long long total = 0;
        int  mod, complement;
        vector<int> vec(24, 0);
        for (auto hour : hours)
        {
            mod = hour % 24;
            complement = (24 - mod) % 24;
            total += vec[complement];
            vec[mod]++;
        }
        return total;
    }
};
// @lc code=end

/*
// @lcpr case=start
// [12,12,30,24,24]\n
// @lcpr case=end

// @lcpr case=start
// [72,48,24,3]\n
// @lcpr case=end

 */
