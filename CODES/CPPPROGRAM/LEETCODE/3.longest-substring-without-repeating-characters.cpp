#include <bits/stdc++.h>
using namespace std;

/*
 * @lc app=leetcode.cn id=3 lang=cpp
 * @lcpr version=20002
 *
 * [3] 无重复字符的最长子串
 */

// @lcpr-template-start

// @lcpr-template-end
// @lc code=start
class Solution
{
public:
    int lengthOfLongestSubstring(string s)
    {
        unordered_set<char> st;
        int slow = 0, fast = 0, total = 0;
        while (fast < s.size())
        {
            if (st.find(s[fast]) == st.end())
            {
                st.insert(s[fast]);
                total = max(total, fast + 1 - slow);
                fast++;
            }else{
                st.erase(s[slow]);
                slow++;
            }
        }
        return total;
    }
};
// @lc code=end

/*
// @lcpr case=start
// "abcabcbb"\n
// @lcpr case=end

// @lcpr case=start
// "bbbbb"\n
// @lcpr case=end

// @lcpr case=start
// "pwwkew"\n
// @lcpr case=end

 */
