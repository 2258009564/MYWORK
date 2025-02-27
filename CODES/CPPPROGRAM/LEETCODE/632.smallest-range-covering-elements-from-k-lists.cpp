#include <bits/stdc++.h>
using namespace std;
#define int long long
#define endl '\n'

/*
 * @lc app=leetcode.cn id=632 lang=cpp
 * @lcpr version=30008
 *
 * [632] 最小区间
 */

// @lcpr-template-start

// @lcpr-template-end
// @lc code=start
class Solution
{
public:
    vector<int> smallestRange(vector<vector<int>> &nums)
    {
        vector<int> szs(nums.size(), 0);
        for (int i = 0; i < nums.size(); i++)
        {
            szs[i] = nums[i].size();
        }
        struct datas
        {
            int num, index;
        };
        multiset<datas, function<bool(datas &, datas &)>> st(
            [](auto &a, auto &b)
            { return a.num < b.num; });
        vector<int> indexs(nums.size(), 0);
        for (int i = 0; i < indexs.size(); i++)
        {
            st.insert({nums[i][indexs[i]], i});
        }
        auto a = (*st.rbegin()).num, b = (*st.begin()).num;
        auto minsz = b - a + 1;
        pair<int, int> ans = {a, b};

        while (st.size())
        {
            auto data = *st.begin();
            st.erase(data);
            auto index1 = data.index;
            indexs[index1]++;
            if (indexs[index1] == nums[index1].size())
            {
                break;
            }
            st.insert({nums[index1][indexs[index1]], index1});
            auto c = (*st.rbegin()).num, d = (*st.begin()).num;
            auto cursz = d - c + 1;
            if (cursz < minsz)
            {
                cursz = minsz;
                ans = {c, d};
            }
        }
        return {ans.first, ans.second};
    }
};
// @lc code=end

/*
// @lcpr case=start
// [[4,10,15,24,26], [0,9,12,20], [5,18,22,30]]\n
// @lcpr case=end

// @lcpr case=start
// [[1,2,3],[1,2,3],[1,2,3]]\n
// @lcpr case=end

 */
