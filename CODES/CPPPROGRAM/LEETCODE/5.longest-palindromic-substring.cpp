#include <bits/stdc++.h>
using namespace std;

/*
 * @lc app=leetcode.cn id=5 lang=cpp
 * @lcpr version=20001
 *
 * [5] 最长回文子串
 */

// @lcpr-template-start

// @lcpr-template-end
// @lc code=start
class Solution
{
public:
    string panduan(string s, int i, int j)
    {
        while(i>=0&&j<s.size()&&s[i] == s[j]){
            i--, j++;
        }
        return s.substr(i + 1, j - i - 1);
    }

    string longestPalindrome(string s)
    {
        string res = "";
        for (int k = 0; k < s.size();k++){
            string s1 = panduan(s, k, k), s2 = panduan(s, k, k + 1);
            res = res.length() > s1.length() ? res : s1;
            res = res.length() > s2.length() ? res : s2;
        }
        return res;
    }
};
// @lc code=end

/*
// @lcpr case=start
// "babad"\n
// @lcpr case=end

// @lcpr case=start
// "cbbd"\n
// @lcpr case=end

 */
