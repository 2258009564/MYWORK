#include <bits/stdc++.h>
using namespace std;
#define int long long
#define endl '\n'

/*
 * @lc app=leetcode.cn id=90 lang=cpp
 * @lcpr version=20003
 *
 * [90] 子集 II
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
    void backtracking(vector<int> &nums, int startindex)
    {
        //path压入result其实跟到达树根是分开的
        //应当具体情况具体分析
        st.insert(path);

        if (startindex >= nums.size())
        {
            return;
        }
        // father [startindex,nums.size()-1]
        // son [startindex,i]
        for (int i = startindex; i < nums.size(); i++)
        {

            path.push_back(nums[i]);
            backtracking(nums, i + 1);
            path.pop_back();
        }
    }

public:
    vector<vector<int>> subsetsWithDup(vector<int> &nums)
    {
        sort(nums.begin(), nums.end());
        backtracking(nums, 0);
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
// [1,2,2]\n
// @lcpr case=end

// @lcpr case=start
// [0]\n
// @lcpr case=end

 */
