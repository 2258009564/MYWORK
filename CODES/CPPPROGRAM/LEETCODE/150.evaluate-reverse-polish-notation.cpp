#include <bits/stdc++.h>
using namespace std;
#define int long long
#define endl '\n'

/*
 * @lc app=leetcode.cn id=150 lang=cpp
 * @lcpr version=20004
 *
 * [150] 逆波兰表达式求值
 */

// @lcpr-template-start

// @lcpr-template-end
// @lc code=start
class Solution
{
public:
    int evalRPN(vector<string> &tokens)
    {
        stack<int> stk;

        for (const string &s : tokens)
        {
            if (s == "+" || s == "-" || s == "*" || s == "/")
            {
                int b = stk.top();
                stk.pop();
                int a = stk.top();
                stk.pop();

                if (s == "+")
                    stk.push(a + b);
                else if (s == "-")
                    stk.push(a - b);
                else if (s == "*")
                    stk.push(a * b);
                else if (s == "/")
                    stk.push(a / b);
            }
            else
            {
                stk.push(stoi(s));
            }
        }

        return stk.top();
    }
};
// @lc code=end

/*
// @lcpr case=start
// ["2","1","+","3","*"]\n
// @lcpr case=end

// @lcpr case=start
// ["4","13","5","/","+"]\n
// @lcpr case=end

// @lcpr case=start
// ["10","6","9","3","+","-11","*","/","*","17","+","5","+"]\n
// @lcpr case=end

 */
