#include <bits/stdc++.h>
using namespace std;
#define int long long
#define endl '\n'

/*
 * @lc app=leetcode.cn id=130 lang=cpp
 * @lcpr version=20004
 *
 * [130] 被围绕的区域
 */

// @lcpr-template-start

// @lcpr-template-end
// @lc code=start
class Solution
{
public:
    vector<pair<int, int>> d = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};

    void dfs(vector<vector<char>> &board, int i, int j, char c)
    {
        int n = board.size(), m = board[0].size();
        if (i == -1 or i == n or j == -1 or j == m or board[i][j] != 'O')
        {
            return;
        }
        board[i][j] = c;
        for (auto &&[x, y] : d)
        {
            dfs(board, i + x, j + y, c);
        }
    }
    void solve(vector<vector<char>> &board)
    {
        int n = board.size(), m = board[0].size();

        for (int i = 0; i < n; i++)
        {
            if (board[i][0] == 'O')
            {
                dfs(board, i, 0, 'x');
            }
            if (board[i][m - 1] == 'O')
            {
                dfs(board, i, m - 1, 'x');
            }
        }

        for (int j = 0; j < m; j++)
        {
            if (board[0][j] == 'O')
            {
                dfs(board, 0, j, 'x');
            }
            if (board[n - 1][j] == 'O')
            {
                dfs(board, n - 1, j, 'x');
            }
        }

        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                if (board[i][j] == 'O')
                {
                    dfs(board, i, j, 'X');
                }
            }
        }

        for (auto &&v : board)
        {
            for (auto &&i : v)
            {
                if (i == 'x')
                {
                    i = 'O';
                }
            }
        }
    }
};
// @lc code=end

/*
// @lcpr case=start
// [["X","X","X","X"],["X","O","O","X"],["X","X","O","X"],["X","O","X","X"]]\n
// @lcpr case=end

// @lcpr case=start
// [["X"]]\n
// @lcpr case=end

 */
