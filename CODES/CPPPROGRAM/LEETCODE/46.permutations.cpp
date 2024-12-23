#include <bits/stdc++.h>
using namespace std;
#define int long long
#define endl '\n'

/*
 * @lc app=leetcode.cn id=46 lang=cpp
 * @lcpr version=20003
 *
 * [46] 全排列
 */

// @lcpr-template-start

// @lcpr-template-end
// @lc code=start
class Solution
{
private:
    vector<vector<int>> result;
    vector<int> path;
    void backtracking(vector<int> &nums, vector<bool> used)
    {
        if (path.size() == nums.size())
        {
            result.push_back(path);
            return;
        }
        for (int i = 0; i < nums.size(); i++)
        {
            if (!used[i])
            {
                used[i] = 1;
                path.push_back(nums[i]);
                backtracking(nums, used);
                path.pop_back();
                used[i] = 0;
            }
        }
    }

public:
    vector<vector<int>> permute(vector<int> &nums)
    {
        vector<bool> used(nums.size(), 0);
        backtracking(nums, used);
        return result;
    }
};
// @lc code=end

/*
// @lcpr case=start
// [1,2,3]\n
// @lcpr case=end

// @lcpr case=start
// [0,1]\n
// @lcpr case=end

// @lcpr case=start
// [1]\n
// @lcpr case=end

 */
