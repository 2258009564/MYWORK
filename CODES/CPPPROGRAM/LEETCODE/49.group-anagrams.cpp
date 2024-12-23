#include <bits/stdc++.h>
using namespace std;

/*
 * @lc app=leetcode.cn id=49 lang=cpp
 * @lcpr version=20002
 *
 * [49] 字母异位词分组
 */

// @lcpr-template-start

// @lcpr-template-end
// @lc code=start
class Solution
{
public:
    vector<vector<string>> groupAnagrams(vector<string> &strs)
    {
        unordered_map<string, vector<string>> mp;
        for(auto &str:strs){
            string str1 = str;
            sort(str1.begin(), str1.end());
                mp[str1].push_back(str);
        }
        vector<vector<string>> res;
        for(auto &mp1:mp){
            res.push_back(mp1.second);
        }
        return res;
    }
};
// @lc code=end

/*
// @lcpr case=start
// ["eat", "tea", "tan", "ate", "nat", "bat"]\n
// @lcpr case=end

// @lcpr case=start
// [""]\n
// @lcpr case=end

// @lcpr case=start
// ["a"]\n
// @lcpr case=end

 */
