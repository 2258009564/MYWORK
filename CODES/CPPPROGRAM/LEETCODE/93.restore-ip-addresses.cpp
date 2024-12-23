#include <bits/stdc++.h>
using namespace std;
#define int long long
#define endl '\n'

/*
 * @lc app=leetcode.cn id=93 lang=cpp
 * @lcpr version=20003
 *
 * [93] 复原 IP 地址
 */

// @lcpr-template-start

// @lcpr-template-end
// @lc code=start
class Solution
{
private:
    vector<string> result;
    vector<string> path;
    void backtracking(string s, int startindex)
    {
        if (path.size() == 4 and path[0] + path[1] + path[2] + path[3] == s)
        {
            result.push_back(path[0] + '.' + path[1] + '.' + path[2] + '.' + path[3]);
            return;
        }
        // 尝试表示父节点 子节点
        // [startindex,s.size()-1]
        for (int i = startindex; i < s.size() and i - startindex + 1 <= 3; i++)
        {
            string news = s.substr(startindex, i - startindex + 1);
            if (to_string(stoll(news)) == news and stoll(news) <= 255 and stoll(news) >= 0)
            {
                path.push_back(news);
                backtracking(s, i + 1);
                path.pop_back();
            }
        }
    }

public:
    vector<string> restoreIpAddresses(string s)
    {
        path.clear();
        result.clear();
        backtracking(s, 0);
        return result;
    }
};
// @lc code=end

/*
// @lcpr case=start
// "25525511135"\n
// @lcpr case=end

// @lcpr case=start
// "0000"\n
// @lcpr case=end

// @lcpr case=start
// "101023"\n
// @lcpr case=end

 */
