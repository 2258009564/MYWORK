#include <bits/stdc++.h>
using namespace std;
#define int long long
#define endl '\n'

/*
 * @lc app=leetcode.cn id=39 lang=cpp
 * @lcpr version=20003
 *
 * [39] 组合总和
 */

// @lcpr-template-start

// @lcpr-template-end
// @lc code=start
class Solution
{
private:
    vector<vector<int>> result;
    vector<int> path;
    void backtracking(int target, vector<int> &candidates, int startindex, int sum)
    {
        if (sum >= target)
        {
            if (sum == target)
            {
                result.push_back(path);
            }
            return;
        }
        for (int i = startindex; i < candidates.size() and sum + candidates[i] <= target; i++)
        {
            sum += candidates[i];
            path.push_back(candidates[i]);
            backtracking(target, candidates, i, sum);
            path.pop_back();
            sum -= candidates[i];
        }
    }

public:
    vector<vector<int>> combinationSum(vector<int> &candidates, int target)
    {
        path.clear();
        result.clear();
        sort(candidates.begin(), candidates.end());
        backtracking(target, candidates, 0, 0);
        return result;
    }
};
// @lc code=end

/*
// @lcpr case=start
// [2,3,6,7]\n7\n
// @lcpr case=end

// @lcpr case=start
// [2,3,5]\n8\n
// @lcpr case=end

// @lcpr case=start
// [2]\n1\n
// @lcpr case=end

 */
