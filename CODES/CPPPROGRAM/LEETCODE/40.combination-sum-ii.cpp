#include <bits/stdc++.h>
using namespace std;
#define int long long
#define endl '\n'

/*
 * @lc app=leetcode.cn id=40 lang=cpp
 * @lcpr version=20003
 *
 * [40] 组合总和 II
 */

// @lcpr-template-start

// @lcpr-template-end
// @lc code=start
class Solution
{
private:
    vector<vector<int>> result;
    vector<int> path;
    void backtracking(vector<int> &candidates /*树的全部节点*/, int target /*树的最深处*/, int sum /*纵向遍历*/, int startindex /*横向遍历*/)
    {
        if (sum >= target)
        {
            if (sum == target)
            {
                result.push_back(path);
            }
            return;
        }
        // 尝试表示每一个节点
        for (int i = startindex; i < candidates.size() and sum + candidates[i] <= target; i++)
        {
            // 判断重复
            if (i > startindex and candidates[i] == candidates[i - 1])
            {
                continue;
            }
            sum += candidates[i];
            path.push_back(candidates[i]);
            backtracking(candidates, target, sum, i + 1);
            path.pop_back();
            sum -= candidates[i];
        }
    }

public:
    vector<vector<int>> combinationSum2(vector<int> &candidates, int target)
    {
        sort(candidates.begin(), candidates.end());
        backtracking(candidates, target, 0, 0);
        return result;
    }
};
// @lc code=end

/*
// @lcpr case=start
// [10,1,2,7,6,1,5]\n8\n
// @lcpr case=end

// @lcpr case=start
// [2,5,2,1,2]\n5\n
// @lcpr case=end

 */
