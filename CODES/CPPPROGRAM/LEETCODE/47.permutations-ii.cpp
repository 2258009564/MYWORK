#include <bits/stdc++.h>
using namespace std;
#define int long long
#define endl '\n'

/*
 * @lc app=leetcode.cn id=47 lang=cpp
 * @lcpr version=20003
 *
 * [47] 全排列 II
 */

// @lcpr-template-start

// @lcpr-template-end
// @lc code=start
class Solution
{
private:
    vector<vector<int>> result;
    vector<int> path;
    set<vector<int>> st;
    void backtracking(vector<int> &nums, vector<bool> used)
    {
        if(path.size() == nums.size())
        {
            st.insert(path);
            return;
        }

        // fa: nums
        // son: num
        for (int i = 0; i < nums.size(); i++)
        {
            if(!used[i])
            {
                used[i] = 1;
                path.emplace_back(nums[i]);
                backtracking(nums, used);
                path.pop_back();
                used[i] = 0;
            }
        }
    }

public:
    vector<vector<int>> permuteUnique(vector<int> &nums)
    {
        result.clear();
        path.clear();
        vector<bool> used(nums.size(), 0);
        backtracking(nums, used);
        for (auto &&i : st)
        {
            result.push_back(i);
        }
        return result;
    }
};
// @lc code=end

/*
// @lcpr case=start
// [1,1,2]\n
// @lcpr case=end

// @lcpr case=start
// [1,2,3]\n
// @lcpr case=end

 */
