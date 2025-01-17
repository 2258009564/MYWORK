#include <bits/stdc++.h>
using namespace std;
#define int long long
#define endl '\n'

/*
 * @lc app=leetcode.cn id=2226 lang=cpp
 * @lcpr version=20004
 *
 * [2226] 每个小孩最多能分到多少糖果
 */

// @lcpr-template-start

// @lcpr-template-end
// @lc code=start
class Solution
{
public:
    bool f(vector<int> &candies, long long k, int m)
    {
        long long ans = 0;
        for (auto &&i : candies)
        {
            ans += i / m;
            if (ans >= k)
            {
                return 1;
            }
        }
        return 0;
    }
    int maximumCandies(vector<int> &candies, long long k)
    {
        if (accumulate(candies.begin(), candies.end(), 0ll) < k)
        {
            return 0;
        }
        int l = 1, r = ranges::max(candies), m, ans;

        while (l <= r)
        {
            m = l + (r - l) / 2;
            if (f(candies, k, m))
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
// [5,8,6]\n3\n
// @lcpr case=end

// @lcpr case=start
// [2,5]\n11\n
// @lcpr case=end

 */
