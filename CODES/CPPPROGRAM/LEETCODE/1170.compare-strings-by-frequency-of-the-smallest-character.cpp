#include <bits/stdc++.h>
using namespace std;
#define int long long
#define endl '\n'

/*
 * @lc app=leetcode.cn id=1170 lang=cpp
 * @lcpr version=20004
 *
 * [1170] 比较字符串最小字母出现频次
 */

// @lcpr-template-start

// @lcpr-template-end
// @lc code=start
class Solution
{
public:
    int f(string s)
    {
        return ranges::count(s, (*ranges::min_element(s)));
    }
    vector<int> numSmallerByFrequency(vector<string> &queries, vector<string> &words)
    {
        vector<int> ans, fw;

        for (auto &&w : words)
        {
            fw.push_back(f(w));
        }

        ranges::sort(fw);

        for (auto &&q : queries)
        {
            auto it = f(q);
            ans.push_back(fw.size() - (ranges::upper_bound(fw, it) - fw.begin()));
        }
        return ans;
    }
};
// @lc code=end

/*
// @lcpr case=start
// ["cbd"]\n["zaaaz"]\n
// @lcpr case=end

// @lcpr case=start
// ["bbb","cc"]\n["a","aa","aaa","aaaa"]\n
// @lcpr case=end

 */
