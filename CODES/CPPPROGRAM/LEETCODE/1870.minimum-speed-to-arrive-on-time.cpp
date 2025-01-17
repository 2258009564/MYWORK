#include <bits/stdc++.h>
using namespace std;
#define int long long
#define endl '\n'

/*
 * @lc app=leetcode.cn id=1870 lang=cpp
 * @lcpr version=20004
 *
 * [1870] 准时到达的列车最小时速
 */

// @lcpr-template-start

// @lcpr-template-end
// @lc code=start
class Solution
{
public:
    bool f(vector<int> &dist, double hour, int m)
    {
        int ans = 0;
        for (auto &&d : dist)
        {
            ans += (d + m - 1) / m;
            if (ans > hour)
            {
                return 0;
            }
        }
        return 1;
    }

    int minSpeedOnTime(vector<int> &dist, double hour)
    {
        if (hour < dist.size())
        {
            return -1;
        }
        // 对 时速 二分
        int l = 1, r = 1e7 + 1, m, ans = -1;
        while (l <= r)
        {
            m = l + (r - l) / 2;
            if (f(dist, hour, m))
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
// [1,3,2]\n6\n
// @lcpr case=end

// @lcpr case=start
// [1,3,2]\n2.7\n
// @lcpr case=end

// @lcpr case=start
// [1,3,2]\n1.9\n
// @lcpr case=end

 */
