#include <bits/stdc++.h>
using namespace std;
#define int long long
#define endl '\n'

/*
 * @lc app=leetcode.cn id=2141 lang=cpp
 * @lcpr version=20004
 *
 * [2141] 同时运行 N 台电脑的最长时间
 */

// @lcpr-template-start

// @lcpr-template-end
// @lc code=start
class Solution
{
public:
    bool f(vector<int> &batteries, int t, int n)
    {
        if (batteries.size() < n)
            return 0;

        long long sum = 0;
        for (auto &&b : batteries)
        {
            if (b > t)
            {
                n--;
            }
            else
            {
                sum += b;
            }
            if (sum >= (long long)n * (long long)t)
            {
                return 1;
            }
        }
        return 0;
    }

    long long maxRunTime(int n, vector<int> &batteries)
    {
        long long l = 0, r = accumulate(batteries.begin(), batteries.end(), 0ll), m, ans = 0;

        while (l <= r)
        {
            m = l + (r - l) / 2;
            if (f(batteries, m, n))
            {
                ans = m;
                l = m + 1;
            }
            else
            {
                r = m - 1;
            }
        }
        return ans;
    }
};
// @lc code=end

/*
// @lcpr case=start
// 2\n[3,3,3]\n
// @lcpr case=end

// @lcpr case=start
// 2\n[1,1,1,1]\n
// @lcpr case=end

 */
