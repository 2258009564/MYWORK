#include <bits/stdc++.h>
using namespace std;
#define int long long
#define endl '\n'

/*
 * @lc app=leetcode.cn id=695 lang=cpp
 * @lcpr version=20004
 *
 * [695] 岛屿的最大面积
 */

// @lcpr-template-start

// @lcpr-template-end
// @lc code=start
class Solution
{
public:
    vector<pair<int, int>> d = {{1, 0}, {0, 1}, {-1, 0}, {0, -1}};
    int num = 0;

    void dfs(int i, int j, vector<vector<int>> &grid)
    {
        if (i < 0 or i == grid.size() or j < 0 or j == grid[0].size() or grid[i][j] == 0)
        {
            return;
        }
        grid[i][j] = 0;
        num++;
        for (auto &&[x, y] : d)
        {
            dfs(i + x, j + y, grid);
        }
    }
    int maxAreaOfIsland(vector<vector<int>> &grid)
    {
        int ans = 0;
        for (int i = 0; i < grid.size(); i++)
        {
            for (int j = 0; j < grid[0].size(); j++)
            {
                if (grid[i][j])
                {
                    num = 0;
                    dfs(i, j, grid);
                    ans = max(ans, num);
                }
            }
        }
        return ans;
    }
};
// @lc code=end

/*
// @lcpr case=start
// [[0,0,1,0,0,0,0,1,0,0,0,0,0],[0,0,0,0,0,0,0,1,1,1,0,0,0],[0,1,1,0,1,0,0,0,0,0,0,0,0],[0,1,0,0,1,1,0,0,1,0,1,0,0],[0,1,0,0,1,1,0,0,1,1,1,0,0],[0,0,0,0,0,0,0,0,0,0,1,0,0],[0,0,0,0,0,0,0,1,1,1,0,0,0],[0,0,0,0,0,0,0,1,1,0,0,0,0]]\n
// @lcpr case=end

// @lcpr case=start
// [[0,0,0,0,0,0,0,0]]\n
// @lcpr case=end

 */
