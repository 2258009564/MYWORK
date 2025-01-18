#include <bits/stdc++.h>
using namespace std;
#define int long long
#define endl '\n'

/*
 * @lc app=leetcode.cn id=947 lang=cpp
 * @lcpr version=20004
 *
 * [947] 移除最多的同行或同列石头
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
        for (int i = 0; i < n; i++)
        {
            father[i] = i;
        }
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
        auto ri = ffind(i), rj = ffind(j);

        if (ri - rj)
        {
            father[ri] = rj;
            s--;
        }
    }

    int removeStones(vector<vector<int>> &stones)
    {
        auto n = stones.size();
        init(n);
        unordered_map<int, int> xmp, ymp;

        for (int i = 0; i < n; i++) // 第i块石头
        {
            auto x = stones[i][0];
            auto y = stones[i][1];

            if (!xmp.count(x))
            {
                xmp[x] = i;
            }
            else
            {
                funion(i, xmp[x]);
            }

            if (!ymp.count(y))
            {
                ymp[y] = i;
            }
            else
            {
                funion(i, ymp[y]);
            }
        }
        return n - s;
    }
};
// @lc code=end

/*
// @lcpr case=start
// [[0,0],[0,1],[1,0],[1,2],[2,1],[2,2]]\n
// @lcpr case=end

// @lcpr case=start
// [[0,0],[0,2],[1,1],[2,0],[2,2]]\n
// @lcpr case=end

// @lcpr case=start
// [[0,0]]\n
// @lcpr case=end

 */
