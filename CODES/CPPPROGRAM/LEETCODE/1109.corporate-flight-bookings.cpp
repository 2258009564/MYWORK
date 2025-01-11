#include <bits/stdc++.h>
using namespace std;
#define int long long
#define endl '\n'

/*
 * @lc app=leetcode.cn id=1109 lang=cpp
 * @lcpr version=20004
 *
 * [1109] 航班预订统计
 */

// @lcpr-template-start

// @lcpr-template-end
// @lc code=start
class Solution
{
public:
    vector<int> corpFlightBookings(vector<vector<int>> &bookings, int n)
    {
        vector<int> diff(n + 2, 0); // 1-based

        for (auto &&v : bookings)
        {
            auto f = v[0], l = v[1], s = v[2];

            diff[f] += s, diff[l + 1] -= s;
        }

        vector<int> result(n);
        partial_sum(diff.begin() + 1, diff.begin() + n + 1, result.begin());

        return result;
    }
};
// @lc code=end

/*
// @lcpr case=start
// [[1,2,10],[2,3,20],[2,5,25]]\n5\n
// @lcpr case=end

// @lcpr case=start
// [[1,2,10],[2,2,15]]\n2\n
// @lcpr case=end

 */
