#include <bits/stdc++.h>
using namespace std;
#define int long long
#define endl '\n'

/*
 * @lc app=leetcode.cn id=463 lang=cpp
 * @lcpr version=20004
 *
 * [463] 岛屿的周长
 */

// @lcpr-template-start

// @lcpr-template-end
// @lc code=start
class Solution
{
public:
    int ans = 0;
    vector<pair<int, int>> d = {{1, 0}, {0, 1}, {-1, 0}, {0, -1}};

    void dfs(int i, int j, vector<vector<int>> &grid)
    {
        if (i < 0 or i == grid.size() or j < 0 or j == grid[0].size() or grid[i][j] == 0)
        {
            ans++;
            return;
        }

        if (grid[i][j] == 2)
        {
            return;
        }

        grid[i][j] = 2;

        for (auto &&[x, y] : d)
        {
            dfs(i + x, j + y, grid);
        }
    }
    int islandPerimeter(vector<vector<int>> &grid)
    {
        for (int i = 0; i < grid.size(); i++)
        {
            for (int j = 0; j < grid[0].size(); j++)
            {
                if (grid[i][j])
                {
                    dfs(i, j, grid);
                }
            }
        }
        return ans;
    }
};
// @lc code=end

/*
// @lcpr case=start
// [[0,1,0,0],[1,1,1,0],[0,1,0,0],[1,1,0,0]]\n
// @lcpr case=end

// @lcpr case=start
// [[1]]\n
// @lcpr case=end

// @lcpr case=start
// [[1,0]]\n
// @lcpr case=end

 */
