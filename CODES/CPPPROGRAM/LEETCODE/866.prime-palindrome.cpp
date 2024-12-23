#include <bits/stdc++.h>
using namespace std;
#define int long long
#define endl '\n'

/*
 * @lc app=leetcode.cn id=866 lang=cpp
 * @lcpr version=20003
 *
 * [866] 回文质数
 */

// @lcpr-template-start

// @lcpr-template-end
// @lc code=start
class Solution
{
private:
    bool isPrime(int n)
    {
        if (n == 1)
        {
            return 0;
        }
        if (n == 2 || n == 3)
        {
            return 1;
        }
        for (int i = 2; i <= n / i; i++)
        {
            if (n % i == 0)
            {
                return 0;
            }
        }
        return 1;
    }

    bool is12321(int n)
    {
        string str = to_string(n);
        int left = 0, right = str.size() - 1;
        while (left <= right)
        {
            if (str[left++] != str[right--])
            {
                return 0;
            }
        }
        return 1;
    }

public:
    int primePalindrome(int n)
    {
        for (int i = n;; i++)
        {
            if (is12321(i) && isPrime(i))
            {
                return i;
            }
        }
        return 0;
    }
};
// @lc code=end

/*
// @lcpr case=start
// 6\n
// @lcpr case=end

// @lcpr case=start
// 8\n
// @lcpr case=end

// @lcpr case=start
// 13\n
// @lcpr case=end

 */
