#include <bits/stdc++.h>
using namespace std;
#define int long long
#define endl '\n'

/*
 * @lc app=leetcode.cn id=1047 lang=cpp
 * @lcpr version=20004
 *
 * [1047] 删除字符串中的所有相邻重复项
 */

// @lcpr-template-start

// @lcpr-template-end
// @lc code=start
class Solution
{
public:
    string removeDuplicates(string s)
    {
        stack<char> stk;

        for (auto &&i : s)
        {
            if (stk.empty() or stk.top() != i)
            {
                stk.push(i);
            }
            else
            {
                stk.pop();
            }
        }
        string ans;
        while (!stk.empty())
        {
            ans += stk.top();
            stk.pop();
        }
        reverse(ans.begin(), ans.end());
        return ans;
    }
};
// @lc code=end

/*
// @lcpr case=start
// "abbaca"\n
// @lcpr case=end

 */
