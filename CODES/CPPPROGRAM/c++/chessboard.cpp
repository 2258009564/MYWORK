#include <bits/stdc++.h>
using namespace std;

void displayBoard(const vector<vector<int>> &board)
{
    cout << "—————————" << endl;
    for (int i = 0; i < 3; ++i)
    {
        for (int j = 0; j < 3; ++j)
        {
            cout << (board[i][j] == 1 ? "X" : board[i][j] == 2 ? "O"
                                                               : " ")
                 << " | ";
        }
        cout << endl
             << "—————————" << endl;
    }
}

bool checkWin(const vector<vector<int>> &board, int player)
{
    for (int i = 0; i < 3; ++i)
    {
        if ((board[i][0] == player && board[i][1] == player && board[i][2] == player) ||
            (board[0][i] == player && board[1][i] == player && board[2][i] == player))
        {
            return true;
        }
    }
    return (board[0][0] == player && board[1][1] == player && board[2][2] == player) ||
           (board[0][2] == player && board[1][1] == player && board[2][0] == player);
}

bool isBoardFull(const vector<vector<int>> &board)
{
    for (const auto &row : board)
    {
        for (const auto &cell : row)
        {
            if (cell == 0)
                return false;
        }
    }
    return true;
}

pair<int, int> findBestMove(vector<vector<int>> &board)
{
    // AI 尝试赢
    for (int i = 0; i < 3; ++i)
    {
        for (int j = 0; j < 3; ++j)
        {
            if (board[i][j] == 0)
            {
                board[i][j] = 2; // AI
                if (checkWin(board, 2))
                    return {i, j};
                board[i][j] = 0; // 撤销
            }
        }
    }

    // 阻止玩家胜利
    for (int i = 0; i < 3; ++i)
    {
        for (int j = 0; j < 3; ++j)
        {
            if (board[i][j] == 0)
            {
                board[i][j] = 1; // 玩家
                if (checkWin(board, 1))
                {
                    board[i][j] = 2; // AI 下在此位置
                    return {i, j};
                }
                board[i][j] = 0; // 撤销
            }
        }
    }

    // 随机选择
    int aiRow, aiCol;
    do
    {
        aiRow = rand() % 3;
        aiCol = rand() % 3;
    } while (board[aiRow][aiCol] != 0);
    return {aiRow, aiCol};
}

int main()
{
    vector<vector<int>> board(3, vector<int>(3, 0));
    int row, col;

    srand(time(0));

    while (true)
    {
        displayBoard(board);

        // 玩家输入
        cout << "你的回合 (输入行和列 1-3): ";
        cin >> row >> col;
        if (board[row - 1][col - 1] != 0)
        {
            cout << "这个位置已被占用，请重新选择。" << endl;
            continue;
        }
        board[row - 1][col - 1] = 1;

        if (checkWin(board, 1))
        {
            displayBoard(board);
            cout << "你赢了！" << endl;
            break;
        }

        if (isBoardFull(board))
        {
            displayBoard(board);
            cout << "平局！" << endl;
            break;
        }

        // AI 回合
        auto [aiRow, aiCol] = findBestMove(board);
        board[aiRow][aiCol] = 2;

        if (checkWin(board, 2))
        {
            displayBoard(board);
            cout << "AI 赢了！" << endl;
            break;
        }
    }
    system("pause");
    return 0;
}
