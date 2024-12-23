#include <bits/stdc++.h>
using namespace std;

/*
 * @lc app=leetcode.cn id=367 lang=cpp
 * @lcpr version=20001
 *
 * [367] 有效的完全平方数
 */

// @lcpr-template-start

// @lcpr-template-end
// @lc code=start
class Solution
{
public:
    bool isPerfectSquare(int num)
    {
        if(num<=1){
            return 1;
        }
        int i = 1;
        while((i+1)<=num/(i+1)){
            i++;
        }
        if(i*i==num){
            return 1;
        }else{
            return 0;
        }
    }
};
// @lc code=end

/*
// @lcpr case=start
// 16\n
// @lcpr case=end

// @lcpr case=start
// 14\n
// @lcpr case=end

 */
