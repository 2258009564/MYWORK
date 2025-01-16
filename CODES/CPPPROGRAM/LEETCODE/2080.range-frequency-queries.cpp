#include <bits/stdc++.h>
using namespace std;
#define int long long
#define endl '\n'

/*
 * @lc app=leetcode.cn id=2080 lang=cpp
 * @lcpr version=20004
 *
 * [2080] 区间内查询数字的频率
 */

// @lcpr-template-start

// @lcpr-template-end
// @lc code=start
class RangeFreqQuery
{
private:
    vector<int> arr;

public:
    RangeFreqQuery(vector<int> &arr) : arr(arr) {}

    int query(int left, int right, int value)
    {
        return count(arr.begin() + left, arr.end() + right + 1, value);
    }
};

/**
 * Your RangeFreqQuery object will be instantiated and called as such:
 * RangeFreqQuery* obj = new RangeFreqQuery(arr);
 * int param_1 = obj->query(left,right,value);
 */
// @lc code=end

/*
// @lcpr case=start
// ["RangeFreqQuery", "query", "query"][[[12, 33, 4, 56, 22, 2, 34, 33, 22, 12, 34, 56]], [1, 2, 4], [0, 11, 33]]\n
// @lcpr case=end

 */
