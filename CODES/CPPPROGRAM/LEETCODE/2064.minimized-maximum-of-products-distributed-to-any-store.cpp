#include <bits/stdc++.h>
using namespace std;
#define int long long
#define endl '\n'

/*
 * @lc app=leetcode.cn id=2064 lang=cpp
 * @lcpr version=20004
 *
 * [2064] 分配给商店的最多商品的最小值
 */

// @lcpr-template-start

// @lcpr-template-end
// @lc code=start
class Solution
{
public:
    int f(int n, vector<int> &quantities, int m)
    {
        int ans = 0;
        for (auto &&i : quantities)
        {
            ans += (i + m - 1) / m;
            if (ans > n)
            {
                return 0;
            }
        }
        return 1;
    }

    int minimizedMaximum(int n, vector<int> &quantities)
    {
        int l = 1, r = ranges::max(quantities), m, ans;

        while (l <= r)
        {
            m = l + (r - l) / 2;

            if (f(n, quantities, m))
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
// 6\n[11,6]\n
// @lcpr case=end

// @lcpr case=start
// 7\n[15,10,10]\n
// @lcpr case=end

// @lcpr case=start
// 1\n[100000]\n
// @lcpr case=end

 */
