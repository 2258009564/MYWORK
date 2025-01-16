#include <bits/stdc++.h>
using namespace std;
#define int long long
#define endl '\n'

/*
 * @lc app=leetcode.cn id=744 lang=cpp
 * @lcpr version=20004
 *
 * [744] 寻找比目标字母大的最小字母
 */

// @lcpr-template-start

// @lcpr-template-end
// @lc code=start
class Solution
{
public:
    char nextGreatestLetter(vector<char> &letters, char target)
    {
        int r = letters.size() - 1, l = 0, m, ans = -1;
        while (l <= r)
        {
            m = l + (r - l) / 2;
            if (letters[m] > target)
            {
                ans = m;
                r = m - 1;
            }
            else
            {
                l = m + 1;
            }
        }
        return (ans == -1 ? letters[0] : letters[ans]);
    }
};
// @lc code=end

/*
// @lcpr case=start
// ["c", "f"\n"a"\n
// @lcpr case=end

// @lcpr case=start
// ["c","f","j"]\n"c"\n
// @lcpr case=end

// @lcpr case=start
// ["x","x","y","y"]\n"z"\n
// @lcpr case=end

 */
