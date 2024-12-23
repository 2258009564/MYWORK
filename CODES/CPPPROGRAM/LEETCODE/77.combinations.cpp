#include <bits/stdc++.h>
using namespace std;
#define int long long
#define endl '\n'

/*
 * @lc app=leetcode.cn id=77 lang=cpp
 * @lcpr version=20003
 *
 * [77] 组合
 */

// @lcpr-template-start

// @lcpr-template-end
// @lc code=start

class Solution
{
private:
    vector<vector<int>> result; // 收集不同的路径 作为leetcode函数的返回值
    vector<int> path;           // 路径 12 13 14

    void backtracking(int n, int k, int startindex)
    {
        if(path.size() == k)
        {
            result.push_back(path);
            return;
        }
        for (int i = startindex;i<=n;i++)
        {
            path.push_back(i);
            backtracking(n, k, i + 1);
            path.pop_back();
        }
    }

public:
    vector<vector<int>> combine(int n, int k)
    {
        backtracking(n, k, 1);
        return result;
    }
};
// @lc code=end

/*
// @lcpr case=start
// 4\n2\n
// @lcpr case=end

// @lcpr case=start
// 1\n1\n
// @lcpr case=end

 */
