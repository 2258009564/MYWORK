#include <bits/stdc++.h>
using namespace std;
#define int long long
#define endl '\n'

/*
 * @lc app=leetcode.cn id=216 lang=cpp
 * @lcpr version=20003
 *
 * [216] 组合总和 III
 */

// @lcpr-template-start

// @lcpr-template-end
// @lc code=start
class Solution
{
private:
    // 确定递归函数的参数
    vector<int> path;
    vector<vector<int>> result;
    void backtracking(int targetsum, int k, int sum, int startindex)
    {
        if (sum > targetsum)
        { // 剪枝操作
            return;
        }
        if (path.size() == k)
        {
            if (sum == targetsum)
            {
                result.push_back(path);
            }
            return;
        }
        for (int i = startindex; 9 - (i - 1) >= k - path.size();i++)
        {
            sum += i;
            path.push_back(i);
            backtracking(targetsum, k, sum, i + 1);
            // 怎么来的就怎么回
            sum -= i;
            path.pop_back();
        }
    }

public:
    vector<vector<int>>
    combinationSum3(int k, int n)
    {
        backtracking(n, k, 0, 1);
        return result;
    }
};
// @lc code=end

/*
// @lcpr case=start
// 3\n7\n
// @lcpr case=end

// @lcpr case=start
// 3\n9\n
// @lcpr case=end

// @lcpr case=start
// 4\n1\n
// @lcpr case=end

 */
