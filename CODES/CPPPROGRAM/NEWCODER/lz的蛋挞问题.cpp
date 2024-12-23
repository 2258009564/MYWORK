#include <bits/stdc++.h>
using namespace std;

#define int long long

const int MAXN = 2e5 + 5;

int parent[MAXN], size[MAXN];
char grid[2][MAXN];

int find(int x)
{
    if (parent[x] != x)
    {
        parent[x] = find(parent[x]);
    }
    return parent[x];
}

void unite(int x, int y)
{
    x = find(x);
    y = find(y);
    if (x != y)
    {
        if (size[x] > size[y])
            swap(x, y);
        parent[x] = y;
        size[y] += size[x];
    }
}

signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n;
    cin >> n;
    for (int i = 0; i < 2; ++i)
    {
        cin >> grid[i];
    }

    // 初始化并查集
    iota(parent, parent + MAXN, 0);
    fill(size, size + MAXN, 1);

    // 连接原本相邻的蛋挞
    for (int i = 0; i < 2; ++i)
    {
        for (int j = 0; j < n; ++j)
        {
            if (grid[i][j] == '.')
            {
                if (i == 0 && j < n - 1 && grid[i][j + 1] == '.')
                {
                    unite(i * n + j, i * n + j + 1);
                }
                if (i == 1 && j < n - 1 && grid[i][j + 1] == '.')
                {
                    unite(i * n + j, i * n + j + 1);
                }
                if (i == 0 && grid[i + 1][j] == '.')
                {
                    unite(i * n + j, (i + 1) * n + j);
                }
            }
        }
    }

    // 统计原始的连通块数量
    int originalComponents = 0;
    for (int i = 0; i < 2 * n; ++i)
    {
        if (parent[i] == i)
        {
            ++originalComponents;
        }
    }

    // 模拟吃掉蛋挞后的变化
    int count = 0;
    for (int i = 0; i < 2; ++i)
    {
        for (int j = 0; j < n; ++j)
        {
            if (grid[i][j] == '.')
            {
                int before = originalComponents;

                // 吃掉 (i, j) 位置的蛋挞，替换成奶贝
                grid[i][j] = 'x';
                int newComponents = 0;
                for (int k = 0; k < 2 * n; ++k)
                {
                    if (parent[k] == k)
                    {
                        newComponents++;
                    }
                }

                if (newComponents != before)
                {
                    count++;
                }

                // 恢复
                grid[i][j] = '.';
            }
        }
    }

    cout << count << endl;

    return 0;
}
