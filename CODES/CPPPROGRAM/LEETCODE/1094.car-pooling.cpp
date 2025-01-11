#include <bits/stdc++.h>
using namespace std;
#define int long long
#define endl '\n'

/*
 * @lc app=leetcode.cn id=1094 lang=cpp
 * @lcpr version=20004
 *
 * [1094] 拼车
 */

// @lcpr-template-start

// @lcpr-template-end
// @lc code=start
class Solution
{
public:
    bool carPooling(vector<vector<int>> &trips, int capacity)
    {
        vector<int> diff(capacity + 1, 0);

        for (auto &&v : trips)
        {
            auto num = v[0], from = v[1], to = v[2];

            diff[from] += num, diff[to + 1] -= num;
        }

        vector<int> pre(capacity, 0);

        partial_sum(diff.begin(), diff.begin() + capacity, pre.begin());

        
    }
};
// @lc code=end

/*
// @lcpr case=start
// [[2,1,5],[3,3,7]]\n4\n
// @lcpr case=end

// @lcpr case=start
// [[2,1,5],[3,3,7]]\n5\n
// @lcpr case=end

 */
