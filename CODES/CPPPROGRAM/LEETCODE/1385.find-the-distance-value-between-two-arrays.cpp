#include <bits/stdc++.h>
using namespace std;
#define int long long
#define endl '\n'

/*
 * @lc app=leetcode.cn id=1385 lang=cpp
 * @lcpr version=20004
 *
 * [1385] 两个数组间的距离值
 */

// @lcpr-template-start

// @lcpr-template-end
// @lc code=start
class Solution
{
public:
    int findTheDistanceValue(vector<int> &arr1, vector<int> &arr2, int d)
    {
        ranges::sort(arr2);
        int ans = 0;

        for (auto &&x : arr1)
        {
            auto it = ranges::lower_bound(arr2, x - d);
            if (it == arr2.end() or *it > x + d)
            {
                ans++;
            }
        }
        return ans;
    }
};
// @lc code=end

/*
// @lcpr case=start
// [4,5,8]\n[10,9,1,8]\n2\n
// @lcpr case=end

// @lcpr case=start
// [1,4,2,3]\n[-4,-3,6,10,20,30]\n3\n
// @lcpr case=end

// @lcpr case=start
// [2,1,100,3]\n[-5,-2,10,-3,7]\n6\n
// @lcpr case=end

 */
