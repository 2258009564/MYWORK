#include <bits/stdc++.h>
using namespace std;
#define int long long
#define endl '\n'

/*
 * @lc app=leetcode.cn id=2187 lang=cpp
 * @lcpr version=20004
 *
 * [2187] 完成旅途的最少时间
 */

// @lcpr-template-start

// @lcpr-template-end
// @lc code=start
class Solution
{
public:
    bool f(long long m, vector<int>& time, int target)
    {
        int ans = 0;
        for (auto &&t : time)
        {
            ans += m / t;
            if (ans >= target)
            {
                return 1;
            }
        }
        return 0;
    }
    long long minimumTime(vector<int> &time, int totalTrips)
    {
        // 二分时间
        long long l = ranges::min(time), r = l * totalTrips, m, ans;
        while (l <= r)
        {
            m = l + (r - l) / 2;

            if (f(m, time, totalTrips))
            {
                ans = m, r = m - 1;
            }
            else
            {
                l = m + 1;
            }
        }
        return ans;
    }
};
// @lc code=end

/*
// @lcpr case=start
// [1,2,3]\n5\n
// @lcpr case=end

// @lcpr case=start
// [2]\n1\n
// @lcpr case=end

 */
