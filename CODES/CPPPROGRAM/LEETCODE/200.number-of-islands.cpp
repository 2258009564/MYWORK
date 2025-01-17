#include <bits/stdc++.h>
using namespace std;
#define int long long
#define endl '\n'

/*
 * @lc app=leetcode.cn id=200 lang=cpp
 * @lcpr version=20004
 *
 * [200] 岛屿数量
 */

// @lcpr-template-start

// @lcpr-template-end
// @lc code=start
class Solution
{
public:
    vector<pair<int, int>> d = {{1, 0}, {0, 1}, {-1, 0}, {0, -1}};
    void dfs(int i, int j, vector<vector<char>> &g)
    {
        if (g[i][j] != '1')
        {
            return;
        }
        g[i][j] = '0';
        for (auto &&xy : d)
        {
            dfs(i + xy.first, j + xy.second, g);
        }
    }

    int numIslands(vector<vector<char>> &grid)
    {
        vector<vector<char>> g(grid.size() + 2, vector<char>(grid[0].size() + 2));

        for (int i = 1; i <= grid.size(); i++)
        {
            for (int j = 1; j <= grid[0].size(); j++)
            {
                g[i][j] = grid[i - 1][j - 1];
            }
        }
        int ans = 0;
        for (int i = 1; i <= grid.size(); i++)
        {
            for (int j = 1; j <= grid[0].size(); j++)
            {
                if (g[i][j] == '1')
                {
                    dfs(i, j, g);
                    ans++;
                }
            }
        }
        return ans;
    }
};
// @lc code=end

/*
// @lcpr case=start
// [["1","1","1","1","0"],["1","1","0","1","0"],["1","1","0","0","0"],["0","0","0","0","0"]]\n
// @lcpr case=end

// @lcpr case=start
// [["1","1","0","0","0"],["1","1","0","0","0"],["0","0","1","0","0"],["0","0","0","1","1"]]\n
// @lcpr case=end

 */
