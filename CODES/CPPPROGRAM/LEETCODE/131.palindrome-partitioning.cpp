#include <bits/stdc++.h>
using namespace std;
#define int long long
#define endl '\n'

/*
 * @lc app=leetcode.cn id=131 lang=cpp
 * @lcpr version=20003
 *
 * [131] 分割回文串
 */

// @lcpr-template-start

// @lcpr-template-end
// @lc code=start
class Solution
{
private:
    vector<vector<string>> result; // result 用来存放 path
    vector<string> path;

    bool isPalindrome(string s, int startindex, int i)
    {
        int left = startindex, right = i;
        while (left <= right)
        {
            if (s[left++] != s[right--])
            {
                return 0;
            }
        }
        return 1;
    }

    void backtracking(string s,int startindex)
    {
        if(startindex == s.size())
        {
            result.push_back(path);
            return;
        }
        for (int i = startindex; i < s.size();i++)
        {
            if(isPalindrome(s,startindex,i))
            {
                path.push_back(s.substr(startindex, i + 1 - startindex));
                backtracking(s, i + 1);
                path.pop_back();
            }
        }
    }

public:
    vector<vector<string>> partition(string s)
    {
        backtracking(s, 0);
        return result;
    }
};
// @lc code=end

/*
// @lcpr case=start
// "aab"\n
// @lcpr case=end

// @lcpr case=start
// "a"\n
// @lcpr case=end

 */
