#include <bits/stdc++.h>
using namespace std;

/*
 * @lc app=leetcode.cn id=844 lang=cpp
 * @lcpr version=20001
 *
 * [844] 比较含退格的字符串
 */

// @lcpr-template-start

// @lcpr-template-end
// @lc code=start
class Solution
{
public:
    string processString(const string &s)
    {
        string res;
        for (auto c : s)
        {
            if (c == '#')
            {
                if (!res.empty())
                {
                    res.pop_back();
                }
            }
            else
            {
                res.push_back(c);
            }
        }
        return res;
    }

    bool backspaceCompare(string s, string t)
    {
        return processString(s) == processString(t); // 比较处理后的字符串
    }
};
// @lc code=end

/*
// @lcpr case=start
// "ab#c"\n"ad#c"\n
// @lcpr case=end

// @lcpr case=start
// "ab##"\n"c#d#"\n
// @lcpr case=end

// @lcpr case=start
// "a#c"\n"b"\n
// @lcpr case=end

 */
