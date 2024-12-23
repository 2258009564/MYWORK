#include <bits/stdc++.h>
using namespace std;
#define int long long
#define endl '\n'

/*
 * @lc app=leetcode.cn id=491 lang=cpp
 * @lcpr version=20003
 *
 * [491] 非递减子序列
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
        if (path.size() >= 2)
        {
            st.insert(path);
        }
        if (startindex >= nums.size())
        {
            return;
        }
        // fa [startindex,nums.size()-1]
        // son [startindex , i]
        for (int i = startindex; i < nums.size(); i++)
        {
            path.push_back(nums[i]);
            backtracking(nums, i + 1);
            path.pop_back();
        }
    }

public:
    vector<vector<int>> findSubsequences(vector<int> &nums)
    {

        backtracking(nums, 0);
        for (auto &&i : st)
        {
            vector<int> i1 = i;
            sort(i1.begin(), i1.end());
            if (i1 == i)
            {
                result.push_back(i);
            }
        }
        return result;
    }
};
// @lc code=end

/*
// @lcpr case=start
// [4,6,7,7]\n
// @lcpr case=end

// @lcpr case=start
// [4,4,3,2,1]\n
// @lcpr case=end

 */
