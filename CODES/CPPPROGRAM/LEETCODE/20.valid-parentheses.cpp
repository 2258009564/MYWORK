#include <bits/stdc++.h>
using namespace std;
#define int long long
#define endl '\n'

/*
 * @lc app=leetcode.cn id=20 lang=cpp
 * @lcpr version=20004
 *
 * [20] 有效的括号
 */

// @lcpr-template-start

// @lcpr-template-end
// @lc code=start
class Solution
{
public:
    bool isValid(string s)
    {
        stack<char> stk;

        for (auto &&c : s)
        {
            if (c == '(' or c == '[' or c == '{')
            {
                stk.push(c);
            }
            else if (c == ')')
            {
                if (stk.empty() || stk.top() != '(')
                    return false;
                stk.pop();
            }
            else if (c == ']')
            {
                if (stk.empty() || stk.top() != '[')
                    return false;
                stk.pop();
            }
            else
            {
                if (stk.empty() || stk.top() != '{')
                    return false;
                stk.pop();
            }
        }

        return stk.empty();
    }
};
// @lc code=end

/*
// @lcpr case=start
// "()"\n
// @lcpr case=end

// @lcpr case=start
// "()[]{}"\n
// @lcpr case=end

// @lcpr case=start
// "(]"\n
// @lcpr case=end

// @lcpr case=start
// "([])"\n
// @lcpr case=end

 */
