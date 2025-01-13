#include <bits/stdc++.h>
using namespace std;
#define int long long
#define endl '\n'

/*
 * @lc app=leetcode.cn id=410 lang=cpp
 * @lcpr version=20004
 *
 * [410] 分割数组的最大值
 */

// @lcpr-template-start

// @lcpr-template-end
// @lc code=start
class Solution
{
public:
    int f(vector<int> nums, int m)
    {
        int ans = 1, sum = 0;

        for (auto &&i : nums)
        {
            if (sum + i <= m)
            {
                sum += i;
            }
            else
            {
                ans++;
                sum = i;
            }
        }
        return ans;
    }
    int splitArray(vector<int> &nums, int k)
    {
        long long sum = accumulate(nums.begin(), nums.end(), 0ll);
        // 二分的是最大值 要求的答案是k
        // k 可以尽可能小 因为小于k段却满足条件 我们大可以把其中的一些段分开 也不会影响答案
        long long ans = 0;

        long long l = *max_element(nums.begin(), nums.end()), r = sum, mid, need;
        while (l <= r)
        {
            // 必须让每一部分的累加和 <= mid， 请问划分成几个部分才够？

            mid = l + (r - l) / 2;

            need = f(nums, mid);

            if (need <= k) // 达标 更新答案 缩小右区间
            {
                ans = mid;
                r = mid - 1;
            }
            else // 未达标 缩小左区间
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
// [7,2,5,10,8]\n2\n
// @lcpr case=end

// @lcpr case=start
// [1,2,3,4,5]\n2\n
// @lcpr case=end

// @lcpr case=start
// [1,4,4]\n3\n
// @lcpr case=end

 */
