#include <bits/stdc++.h>
using namespace std;
#define int long long
#define endl '\n'

/*
 * @lc app=leetcode.cn id=275 lang=cpp
 * @lcpr version=20004
 *
 * [275] H 指数 II
 */

// @lcpr-template-start

// @lcpr-template-end
// @lc code=start
class Solution
{
public:
    bool f(vector<int> &citations, int m)
    {
        int ans = 0;
        for (auto &&i : citations)
        {
            ans += (i >= m);
            if (ans >= m)
            {
                return 1;
            }
        }
        return 0;
    }

    int hIndex(vector<int> &citations)
    {
        int l = 0, r = ranges::max(citations), m, ans;

        while (l <= r)
        {
            m = l + (r - l) / 2;

            if (f(citations, m))
            {
                ans = m, l = m + 1;
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
// [0,1,3,5,6]\n
// @lcpr case=end

// @lcpr case=start
// [1,2,100]\n
// @lcpr case=end

 */
