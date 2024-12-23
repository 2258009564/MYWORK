#include <bits/stdc++.h>
using namespace std;

/*
 * @lc app=leetcode.cn id=344 lang=cpp
 * @lcpr version=20001
 *
 * [344] 反转字符串
 */

// @lcpr-template-start

// @lcpr-template-end
// @lc code=start
class Solution
{
public:
    void reverseString(vector<char> &s)
    {
        if (s.size() == 1)
        {
            return;
        }
        int left = 0, right = s.size() - 1;
        while (left < right)
        {
            swap(s[left], s[right]);
            left++;
            right--;
        }
        return;
    }
};
// @lc code=end

/*
// @lcpr case=start
// ["h","e","l","l","o"]\n
// @lcpr case=end

// @lcpr case=start
// ["H","a","n","n","a","h"]\n
// @lcpr case=end

 */
