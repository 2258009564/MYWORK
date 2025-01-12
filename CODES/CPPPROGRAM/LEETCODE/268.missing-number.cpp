#include <bits/stdc++.h>
using namespace std;
#define int long long
#define endl '\n'

/*
 * @lc app=leetcode.cn id=268 lang=cpp
 * @lcpr version=20004
 *
 * [268] 丢失的数字
 */

// @lcpr-template-start

// @lcpr-template-end
// @lc code=start
class Solution
{
public:
    int xor_(int x)
    {
        if (x % 4 == 0)
        {
            return x;
        }
        if (x % 4 == 1)
        {
            return 1;
        }
        if (x % 4 == 2)
        {
            return x + 1;
        }
        return 0;
    }

    int missingNumber(vector<int> &nums)
    {
        int n = nums.size();

        // calculate xor from 0 to n

        int xor_1_to_n = xor_(n);

        // calculate xor from array
        int temp = 0;
        for (auto &&i : nums)
        {
            temp ^= i;
        }

        return xor_1_to_n ^ temp;
    }
};
// @lc code=end

/*
// @lcpr case=start
// [3,0,1]\n
// @lcpr case=end

// @lcpr case=start
// [0,1]\n
// @lcpr case=end

// @lcpr case=start
// [9,6,4,2,3,5,7,0,1]\n
// @lcpr case=end

 */
