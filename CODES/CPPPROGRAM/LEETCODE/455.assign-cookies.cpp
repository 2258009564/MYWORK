#include <bits/stdc++.h>
using namespace std;

/*
 * @lc app=leetcode.cn id=455 lang=cpp
 * @lcpr version=20001
 *
 * [455] 分发饼干
 */

// @lcpr-template-start

// @lcpr-template-end
// @lc code=start
class Solution
{
public:
    int findContentChildren(vector<int> &g /*胃口*/, vector<int> &s /*饼干尺寸*/)
    {
        sort(g.begin(), g.end());
        sort(s.begin(), s.end());
        int weikou = 0;
        for (auto &&i : s)
        {
            if(weikou < g.size() and i >= g[weikou])
            {
                weikou++;
            }
        }
        return weikou;
    }
};
// @lc code=end

/*
// @lcpr case=start
// [1,2,3]\n[1,1]\n
// @lcpr case=end

// @lcpr case=start
// [1,2]\n[1,2,3]\n
// @lcpr case=end

 */
