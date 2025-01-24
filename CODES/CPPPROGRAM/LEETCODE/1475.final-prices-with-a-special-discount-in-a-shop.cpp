#include <bits/stdc++.h>
using namespace std;
#define int long long
#define endl '\n'

/*
 * @lc app=leetcode.cn id=1475 lang=cpp
 * @lcpr version=20004
 *
 * [1475] 商品折扣后的最终价格
 */

// @lcpr-template-start

// @lcpr-template-end
// @lc code=start
class Solution
{
public:
    vector<int> finalPrices(vector<int> &prices)
    {
        int n = prices.size();
        vector<int> st(n, -1);

        stack<int> stk;

        for (int i = 0; i < n; i++)
        {
            while (!stk.empty() and stk.top() <= prices[i])
            {
                st[stk.top()] = i;
                stk.pop();
            }
            stk.push(i);
        }

        // 预处理结束
        vector<int> ans;
        for (int i = 0; i < n; i++)
        {
            ans.push_back(prices[i] - (st[i] == -1 ? 0 : prices[st[i]]));
        }
        return ans;
    }
};
// @lc code=end

/*
// @lcpr case=start
// [8,4,6,2,3]\n
// @lcpr case=end

// @lcpr case=start
// [1,2,3,4,5]\n
// @lcpr case=end

// @lcpr case=start
// [10,1,1,6]\n
// @lcpr case=end

 */
