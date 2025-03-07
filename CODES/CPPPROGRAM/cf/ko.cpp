#include "MazeGenerator.h"
#include "PathFinder.h"
#include <algorithm>
#include <cmath>
#include <iostream>

using namespace std;

// 生成迷宫：maze 大小为 (2*rows+1) x (2*cols+1)，随机生成起点和终点
void generateMaze(int rows, int cols, vector<vector<char>> &maze, int &startX, int &startY, int &endX, int &endY)
{
    int mazeRows = 2 * rows + 1;
    int mazeCols = 2 * cols + 1;
    maze.assign(mazeRows, vector<char>(mazeCols, '□'));

    // 用于标记 cell grid 中哪些 cell 已经被访问
    vector<vector<bool>> visited(rows, vector<bool>(cols, false));

    // 随机选择起点
    int start_r = rand() % rows;
    int start_c = rand() % cols;

    // 计算迷宫中起点的实际坐标
    startX = 2 * start_r + 1;
    startY = 2 * start_c + 1;

    visited[start_r][start_c] = true;
    maze[startX][startY] = ' ';

    vector<Wall> walls;
    // 上下左右四个方向（cell grid 中的移动）
    int dr[4] = {-1, 1, 0, 0};
    int dc[4] = {0, 0, -1, 1};
    // 将起点相邻的墙加入列表
    for (int i = 0; i < 4; i++)
    {
        int nr = start_r + dr[i];
        int nc = start_c + dc[i];
        if (nr >= 0 && nr < rows && nc >= 0 && nc < cols)
        {
            Wall w;
            w.wx = 2 * start_r + 1 + dr[i]; // 墙壁在 maze 中的位置
            w.wy = 2 * start_c + 1 + dc[i];
            w.cx = nr;
            w.cy = nc;
            walls.emplace_back(w);
        }
    }

    // Prim 算法：不断从墙列表中随机挑选一堵墙
    while (!walls.empty())
    {
        int index = rand() % walls.size();
        Wall currentWall = walls[index];
        // 删除已选的墙（用末尾替换当前元素再 pop_back）
        walls[index] = walls.back();
        walls.pop_back();

        int cell_r = currentWall.cx;
        int cell_c = currentWall.cy;
        if (!visited[cell_r][cell_c])
        {
            // 打通墙壁
            maze[currentWall.wx][currentWall.wy] = ' ';
            // 标记新 cell 为通路
            visited[cell_r][cell_c] = true;
            maze[2 * cell_r + 1][2 * cell_c + 1] = ' ';

            // 将新 cell 周围的墙加入列表
            for (int i = 0; i < 4; i++)
            {
                int nr = cell_r + dr[i];
                int nc = cell_c + dc[i];
                if (nr >= 0 && nr < rows && nc >= 0 && nc < cols)
                {
                    int wall_x = 2 * cell_r + 1 + dr[i];
                    int wall_y = 2 * cell_c + 1 + dc[i];
                    if (maze[wall_x][wall_y] == '□')
                    {
                        Wall newWall;
                        newWall.wx = wall_x;
                        newWall.wy = wall_y;
                        newWall.cx = nr;
                        newWall.cy = nc;
                        walls.emplace_back(newWall);
                    }
                }
            }
        }
    }

    // 随机选择终点，确保与起点有一定距离
    while (true)
    {
        int end_r = rand() % rows;
        int end_c = rand() % cols;

        // 确保终点与起点不同
        if (end_r == start_r && end_c == start_c)
            continue;

        // 计算迷宫中终点的实际坐标
        endX = 2 * end_r + 1;
        endY = 2 * end_c + 1;

        // 检查所选终点是否为空通道
        if (maze[endX][endY] == ' ')
        {
            // 计算起点到终点的曼哈顿距离
            int manhattanDist = abs(start_r - end_r) + abs(start_c - end_c);

            // 确保起点和终点相距较远（至少为格子总数的1/3，增加距离要求）
            if (manhattanDist >= (rows + cols) / 3)
            {
                maze[endX][endY] = '@';
                break;
            }
        }
    }

    // 增加迷宫复杂度，打通一些墙壁形成环路
    // 增加复杂度参数(从/5改为/3)，创建更多环路
    int complexity = (rows * cols) / 3;
    addComplexity(maze, rows, cols, complexity);

    // 增强路径复杂度，创建更迂回的路径
    enhancePathComplexity(maze, startX, startY, endX, endY);

    // 确保最外围都是墙壁
    for (int i = 0; i < mazeRows; i++)
    {
        maze[i][0] = '□';
        maze[i][mazeCols - 1] = '□';
    }
    for (int j = 0; j < mazeCols; j++)
    {
        maze[0][j] = '□';
        maze[mazeRows - 1][j] = '□';
    }
}

// 增加迷宫复杂度：随机打通一些墙壁创建环路
void addComplexity(vector<vector<char>> &maze, int rows, int cols, int complexity)
{
    int mazeRows = maze.size();
    int mazeCols = maze[0].size();

    // 随机打通一些墙壁，但不打通外围墙壁
    for (int i = 0; i < complexity; i++)
    {
        // 选择内部墙壁（确保不是最外围的墙）
        int x = 2 + rand() % (mazeRows - 4);
        int y = 2 + rand() % (mazeCols - 4);

        // 只有是墙壁时才尝试打通
        if (maze[x][y] == '□')
        {
            // 确保打通墙壁不会导致两个相同的房间相连（避免无效打通）
            bool isValidWall = (x % 2 == 1 && y % 2 == 0) || (x % 2 == 0 && y % 2 == 1);
            if (isValidWall)
            {
                maze[x][y] = ' ';
            }
        }
    }
}

// 增强路径复杂度：创建更复杂的迷宫路径
void enhancePathComplexity(vector<vector<char>> &maze, int startX, int startY, int endX, int endY)
{
    int rows = maze.size();
    int cols = maze[0].size();

    // 在迷宫中随机阻塞部分路径，迫使玩家走迂回路线
    int blocksToAdd = (rows + cols) / 6; // 根据迷宫大小决定阻塞数量

    // 获取最短路径上的点
    vector<vector<bool>> onShortestPath(rows, vector<bool>(cols, false));
    vector<vector<int>> distance(rows, vector<int>(cols, -1));
    vector<vector<pair<int, int>>> parent(rows, vector<pair<int, int>>(cols, {-1, -1}));

    queue<pair<int, int>> q;
    q.push({startX, startY});
    distance[startX][startY] = 0;

    int dr[] = {-1, 1, 0, 0};
    int dc[] = {0, 0, -1, 1};

    // 使用BFS找到最短路径
    while (!q.empty())
    {
        auto [x, y] = q.front();
        q.pop();

        if (x == endX && y == endY)
            break;

        for (int i = 0; i < 4; i++)
        {
            int nx = x + dr[i];
            int ny = y + dc[i];

            if (nx >= 0 && nx < rows && ny >= 0 && ny < cols &&
                distance[nx][ny] == -1 && (maze[nx][ny] == ' ' || maze[nx][ny] == '@'))
            {
                distance[nx][ny] = distance[x][y] + 1;
                parent[nx][ny] = {x, y};
                q.push({nx, ny});
            }
        }
    }

    // 标记最短路径上的点
    if (distance[endX][endY] != -1)
    {
        int x = endX, y = endY;
        while (x != startX || y != startY)
        {
            onShortestPath[x][y] = true;
            auto [px, py] = parent[x][y];
            x = px;
            y = py;
        }
        onShortestPath[startX][startY] = true;
    }

    // 随机阻断最短路径上的一些点，但不阻断起点和终点附近
    int attemptCount = 0;
    int blocksAdded = 0;
    int maxAttempts = blocksToAdd * 10; // 防止无限循环

    while (blocksAdded < blocksToAdd && attemptCount < maxAttempts)
    {
        attemptCount++;

        // 选择内部位置
        int x = 2 + rand() % (rows - 4);
        int y = 2 + rand() % (cols - 4);

        // 检查是否在最短路径上，且不是关键点（起点、终点或附近）
        if (onShortestPath[x][y] && maze[x][y] == ' ' &&
            sqrt(pow(x - startX, 2) + pow(y - startY, 2)) > 3 && // 不在起点附近
            sqrt(pow(x - endX, 2) + pow(y - endY, 2)) > 3)
        { // 不在终点附近

            // 临时阻断该点
            maze[x][y] = '□';

            // 确保阻断后仍有路径从起点到终点
            if (checkPathExists(maze, startX, startY, endX, endY))
            {
                blocksAdded++;
            }
            else
            {
                // 如果阻断后无法从起点到终点，恢复该点
                maze[x][y] = ' ';
            }
        }
    }

    // 更强化迷宫复杂度：增加额外的环路和岔路
    int extraComplexity = (rows * cols) / 5;
    for (int i = 0; i < extraComplexity; i++)
    {
        int x = 2 + rand() % (rows - 4);
        int y = 2 + rand() % (cols - 4);

        // 打通一些额外的墙壁，增加岔路
        if (maze[x][y] == '□' &&
            ((x % 2 == 1 && y % 2 == 0) || (x % 2 == 0 && y % 2 == 1)))
        {

            maze[x][y] = ' ';
            // 这里不需要再次检查可达性，因为打通墙壁不会破坏已有路径
        }
    }
}

// 在迷宫中随机放置陷阱，陷阱以 '!' 表示，概率可调
void placeTraps(vector<vector<char>> &maze, int rows, int cols, double trapProbability)
{
    int mazeRows = 2 * rows + 1;
    int mazeCols = 2 * cols + 1;
    // 仅在实际 cell（奇数行列）中放置陷阱
    for (int i = 1; i < mazeRows; i += 2)
    {
        for (int j = 1; j < mazeCols; j += 2)
        {
            // 排除起点 (1,1) 和终点
            if ((i == 1 && j == 1) || maze[i][j] == '@')
            {
                continue;
            }
            if (maze[i][j] == ' ' && ((double)rand() / RAND_MAX < trapProbability))
            {
                maze[i][j] = '!';
            }
        }
    }
}
