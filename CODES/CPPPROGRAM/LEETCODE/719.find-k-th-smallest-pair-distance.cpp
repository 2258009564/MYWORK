#include <bits/stdc++.h>
using namespace std;
#define int long long
#define endl '\n'

/*
 * @lc app=leetcode.cn id=719 lang=cpp
 * @lcpr version=20004
 *
 * [719] 找出第 K 小的数对距离
 */

// @lcpr-template-start

// @lcpr-template-end
// @lc code=start
class Solution
{
public:
    int f(vector<int> nums, int lim)
    {
        int ans = 0;
        int r = 0;
        for (int l = 0; l < nums.size(); l++)
        {
            while (r < nums.size() and nums[r] - nums[l] <= lim)
            {
                r++;
            }
            ans += r - l - 1;
        }
        return ans;
    }

    int smallestDistancePair(vector<int> &nums, int k)
    {
        ranges::sort(nums);

        long long l = 0, r = nums.back() - nums.front();

        long long mid, ans, cur;

        while (l <= r)
        {
            // 我们再对数字差作二分
            mid = l + (r - l) / 2;
            // 要验证是否是第k小 只需要遍历看看 差值 <= mid 的 是否有k个
            if (f(nums, mid) >= k) // 有可能有更小的 因为 f里面提到 差值 <= mid 即可
            {
                ans = mid;
                r = mid - 1;
            }
            else
            {
                l = mid + 1;
            }
        }
        return ans;
    }
};
// @lc code=end

/*
// @lcpr case=start
// [1,3,1]\n1\n
// @lcpr case=end

// @lcpr case=start
// [1,1,1]\n2\n
// @lcpr case=end

// @lcpr case=start
// [1,6,1]\n3\n
// @lcpr case=end

 */
