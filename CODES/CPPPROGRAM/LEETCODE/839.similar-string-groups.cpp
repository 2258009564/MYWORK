#include <bits/stdc++.h>
using namespace std;
#define int long long
#define endl '\n'

/*
 * @lc app=leetcode.cn id=839 lang=cpp
 * @lcpr version=20004
 *
 * [839] 相似字符串组
 */

// @lcpr-template-start

// @lcpr-template-end
// @lc code=start
class Solution
{
public:
    vector<int> father;
    int s;
    void init(int n)
    {
        father.resize(n);
        for (int i = 0; i < n; i++)
        {
            father[i] = i;
        }
        s = n;
    }

    int ffind(int n)
    {
        if (n - father[n])
        {
            father[n] = ffind(father[n]);
        }
        return father[n];
    }

    void funion(int i, int j)
    {
        int fi = ffind(i), fj = ffind(j);
        if (fi - fj)
        {
            father[fi] = fj;
            s--;
        }
    }

    bool f(string s1, string s2)
    {
        if (s1.size() - s2.size())
        {
            return 0;
        }

        unordered_map<char, int> mp;
        for (int i = 0; i < s1.size(); i++)
        {
            if (s1[i] - s2[i])
            {
                mp[s1[i]]++, mp[s2[i]]++;
            }
        }
        return (mp.size() == 2 or mp.empty());
    }

    int numSimilarGroups(vector<string> &strs)
    {
        int n = strs.size();
        init(n);

        for (int i = 0; i + 1 < n; i++)
        {
            for (int j = i + 1; j < n; j++)
            {
                if (f(strs[i], strs[j]))
                {
                    funion(i, j);
                }
            }
        }
        return s;
    }
};
// @lc code=end

/*
// @lcpr case=start
// ["tars","rats","arts","star"]\n
// @lcpr case=end

// @lcpr case=start
// ["omv","ovm"]\n
// @lcpr case=end

 */
