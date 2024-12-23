#include <bits/stdc++.h>
using namespace std;

/*
 * @lc app=leetcode.cn id=1 lang=cpp
 * @lcpr version=20002
 *
 * [1] 两数之和
 */

// @lcpr-template-start

// @lcpr-template-end
// @lc code=start
class Solution
{
public:
    vector<int> twoSum(vector<int> &nums, int target)
    {
        // 创建一个无序映射，用于存储数组元素和索引的对应关系
        unordered_map<int, int> mp;
        // 遍历数组
        for (int i = 0; i < nums.size(); i++)
        {
            // 如果映射中存在目标值减去当前元素的差值，则返回该差值的索引和当前元素的索引
            if (mp.find(target - nums[i]) != mp.end())
            {
                return {mp[target - nums[i]], i};
            }
            // 将当前元素和索引存入映射中
            mp[nums[i]] = i;
        }
        // 如果没有找到符合条件的元素，则返回空数组
        return {};
    }
};
// @lc code=end

/*
// @lcpr case=start
// [2,7,11,15]\n9\n
// @lcpr case=end

// @lcpr case=start
// [3,2,4]\n6\n
// @lcpr case=end

// @lcpr case=start
// [3,3]\n6\n
// @lcpr case=end

 */
