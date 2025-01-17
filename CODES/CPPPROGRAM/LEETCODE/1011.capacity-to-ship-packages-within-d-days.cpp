#include <bits/stdc++.h>
using namespace std;
#define int long long
#define endl '\n'

/*
 * @lc app=leetcode.cn id=1011 lang=cpp
 * @lcpr version=20004
 *
 * [1011] 在 D 天内送达包裹的能力
 */

// @lcpr-template-start

// @lcpr-template-end
// @lc code=start
class Solution
{
public:
    bool f(vector<int> &weights, int days, int m)
    {
        int ans = 1 /* 注意 起码需要一天！ */, sum = 0;
        for (auto &&i : weights)
        {
            sum += i;
            if (sum > m)
            {
                ans++;
                sum = i;
            }

            if (ans > days)
            {
                return 0;
            }
        }
        return 1;
    }
    int shipWithinDays(vector<int> &weights, int days)
    {
        // 二分能力
        int l = ranges::max(weights), r = accumulate(weights.begin(), weights.end(), 0ll), m, ans;

        while (l <= r)
        {
            m = l + (r - l) / 2;
            if (f(weights, days, m))
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
// [1,2,3,4,5,6,7,8,9,10]\n5\n
// @lcpr case=end

// @lcpr case=start
// [3,2,2,4,1,4]\n3\n
// @lcpr case=end

// @lcpr case=start
// [1,2,3,1,1]\n4\n
// @lcpr case=end

 */
