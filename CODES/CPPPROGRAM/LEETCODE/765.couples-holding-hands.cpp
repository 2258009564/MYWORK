#include <bits/stdc++.h>
using namespace std;
#define int long long
#define endl '\n'

/*
 * @lc app=leetcode.cn id=765 lang=cpp
 * @lcpr version=20004
 *
 * [765] 情侣牵手
 */

// @lcpr-template-start

// @lcpr-template-end
// @lc code=start
class Solution
{
public:
    vector<int> father;
    int s;
    void init(int n)
    {
        father.resize(n);
        iota(father.begin(), father.end(), 0);
        s = n;
    }
    int ffind(int n)
    {
        if (n - father[n])
        {
            father[n] = ffind(father[n]);
        }
        return father[n];
    }

    void funion(int i, int j)
    {
        int fi = ffind(i), fj = ffind(j);

        if (fi - fj)
        {
            father[fi] = fj;
            s--;
        }
    }
    int minSwapsCouples(vector<int> &row)
    {
        int n = row.size();

        init(n / 2);
        for (int i = 0; i < n; i += 2)
        {
            funion(row[i] / 2, row[i + 1] / 2);
        }
        return n / 2 - s;
    }
};
// @lc code=end

/*
// @lcpr case=start
// [0,2,1,3]\n
// @lcpr case=end

// @lcpr case=start
// [3,2,0,1]\n
// @lcpr case=end

 */
