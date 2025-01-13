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
    int minEatingSpeed(vector<int> &piles, int h)
    {
        int l = 1, r = *max_element(piles.begin(), piles.end());

        int ans = 0;
        int mid = 0;
        while (l <= r)
        {
            mid = l + (r - l) / 2;
            /*
            这个mid是什么？是速度
            我们要求什么？求时间
            因此我们应该遍历整个香蕉数组， 把用时求出来 和 h 进行比较
            */
            long long h1 = 0;
            for (auto &&pile : piles)
            {
                /*
                是熟悉的区间分割诶！
                区间是 mid
                要划分的变量是 pile
                用时就是 (pile - 1) / mid + 1
                我们其实也可以写成
                (pile + mid - 1) / mid
                */

                h1 += (pile - 1) / mid + 1;
            }

            if (h1 <= h)
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
// [3,6,7,11]\n8\n
// @lcpr case=end

// @lcpr case=start
// [30,11,23,4,20]\n5\n
// @lcpr case=end

// @lcpr case=start
// [30,11,23,4,20]\n6\n
// @lcpr case=end

 */
