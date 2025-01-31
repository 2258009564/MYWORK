#include <bits/stdc++.h>
using namespace std;
#define int long long
#define endl '\n'

/*
 * @lc app=leetcode.cn id=875 lang=cpp
 * @lcpr version=20004
 *
 * [875] 爱吃香蕉的珂珂
 */

// @lcpr-template-start

// @lcpr-template-end
// @lc code=start
class Solution
{
public:
    int f(vector<int> &piles, int h, int m)
    {
        int ans = 0;
        for (auto &&p : piles)
        {
            ans += (p + m - 1) / m;
            if (ans > h)
            {
                return 0;
            }
        }
        return 1;
    }

    int minEatingSpeed(vector<int> &piles, int h)
    {
        int l = 1, r = ranges::max(piles), m, ans;
        while (l <= r)
        {
            m = l + (r - l) / 2;

            if (f(piles, h, m))
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
// [3,6,7,11]\n8\n
// @lcpr case=end

// @lcpr case=start
// [30,11,23,4,20]\n5\n
// @lcpr case=end

// @lcpr case=start
// [30,11,23,4,20]\n6\n
// @lcpr case=end

 */
