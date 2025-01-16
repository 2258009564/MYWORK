#include <bits/stdc++.h>
using namespace std;
#define int long long
#define endl '\n'

/*
 * @lc app=leetcode.cn id=1283 lang=cpp
 * @lcpr version=20004
 *
 * [1283] 使结果不超过阈值的最小除数
 */

// @lcpr-template-start

// @lcpr-template-end
// @lc code=start
class Solution
{
public:
    int smallestDivisor(vector<int> &nums, int threshold)
    {
        // 对除数二分
        // 除数的范围应该在[1, ranges::max(num)]

        int l = 1, r = ranges::max(nums), m, ans;
        while (l <= r)
        {
            m = l + (r - l) / 2;
            int sum = 0;
            for (auto &&i : nums)
            {
                sum += (i + m - 1) / m;
                if (sum > threshold)
                {
                    sum = threshold + 1;
                    break;
                }
            }
            if (sum <= threshold)
            {
                ans = m;
                r = m - 1;
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
// [1,2,5,9]\n6\n
// @lcpr case=end

// @lcpr case=start
// [2,3,5,7,11]\n11\n
// @lcpr case=end

// @lcpr case=start
// [19]\n5\n
// @lcpr case=end

 */
