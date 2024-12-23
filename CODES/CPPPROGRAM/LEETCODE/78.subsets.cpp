#include <bits/stdc++.h>
using namespace std;
#define int long long
#define endl '\n'

/*
 * @lc app=leetcode.cn id=78 lang=cpp
 * @lcpr version=20003
 *
 * [78] 子集
 */

// @lcpr-template-start

// @lcpr-template-end
// @lc code=start
class Solution
{
private:
    vector<vector<int>> result;
    vector<int> path;
    void backtracking(vector<int> &nums, int startindex)
    {
        result.push_back(path);
        if (startindex >= nums.size())
        {
            return;
        }
        // 尝试表示父节点 子节点
        // 父节点 : [startindex,nums.size())
        // 子节点 : nums[i]
        for (int i = startindex; i < nums.size(); i++)
        {
            path.push_back(nums[i]);
            backtracking(nums, i + 1);
            path.pop_back();
        }
    }

public:
    vector<vector<int>> subsets(vector<int> &nums)
    {
        result.clear();
        path.clear();
        backtracking(nums, 0);
        return result;
    }
};
// @lc code=end

/*
// @lcpr case=start
// [1,2,3]\n
// @lcpr case=end

// @lcpr case=start
// [0]\n
// @lcpr case=end

 */
