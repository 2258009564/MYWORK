#include <bits/stdc++.h>
using namespace std;
#define int long long
#define endl '\n'

/*
 * @lc app=leetcode.cn id=2982 lang=cpp
 * @lcpr version=20004
 *
 * [2982] 找出出现至少三次的最长特殊子字符串 II
 */

// @lcpr-template-start

// @lcpr-template-end
// @lc code=start
class Solution
{
public:
    bool ff(string &s)
    {
        return ranges::count(s, s[0]) == s.size();
    }
    bool f(string &s, int m)
    {
        unordered_map<string, int> mp;
        auto s1 = s.substr(0, m);
        if (ff(s1))
        {
            mp[s1]++;
        }
        for (int i = 1; i + m <= s.size(); i++)
        {
            s1 = s1.substr(1) + s[i + m - 1];
            if (ff(s1))
            {
                mp[s1]++;
                if (mp[s1] == 3)
                {
                    return 1;
                }
            }
        }
        return 0;
    }

    int maximumLength(string s)
    {
        if (s.empty())
        {
            return -1;
        }
        int l = 1, r = s.size(), m, ans = -1;

        while (l <= r)
        {
            m = l + (r - l) / 2;
            if (f(s, m))
            {
                ans = m, l = m + 1;
            }
            else
            {
                r = m - 1;
            }
        }
        return ans;
    }
};
// @lc code=end

/*
// @lcpr case=start
// "aaaa"\n
// @lcpr case=end

// @lcpr case=start
// "abcdef"\n
// @lcpr case=end

// @lcpr case=start
// "abcaba"\n
// @lcpr case=end

 */
