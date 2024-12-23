// #pragma GCC optimize(2)
#include <bits/stdc++.h>
using namespace std;
#define BUFF ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
#define int long long
typedef pair<int, int> pii;
typedef pair<double, double> pdd;
typedef vector<string> vs;
typedef vector<vs> vvs;
typedef vector<vvs> vvvs;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<vvi> vvvi;
typedef vector<pii> vpii;
typedef vector<vpii> vvpii;
typedef vector<pdd> vpdd;
typedef vector<double> vd;
typedef vector<vd> vvd;
typedef vector<char> vc;
typedef vector<vc> vvc;
typedef vector<vvc> vvvc;
typedef vector<bool> vb;
typedef vector<vb> vvb;
typedef vector<vvb> vvvb;
typedef map<int, int> mii;
typedef map<char, int> mci;
#define endl '\n'
#define ts    \
    int T;    \
    cin >> T; \
    while (T--)
#define all(v) v.begin(), v.end()
#define sall(x) sort(all(x))
#define re(v) reverse(all(v))
#define pb push_back
#define qb pop_back
#define pf push_front
#define qf pop_front

// 通用版本的 >> 重载，用于任意类型的 std::vector<T>
template <typename T>
istream &operator>>(istream &in, vector<T> &v)
{
    for (auto &x : v)
    {
        in >> x;
    }
    return in;
}

// 通用版本的 << 重载，用于任意类型的 std::vector<T>
template <typename T>
ostream &operator<<(ostream &out, const vector<T> &v)
{
    for (const auto &x : v)
    {
        out << x << ' ';
    }
    return out;
}

int dir[4][2] = {1, 0, 0, 1, -1, 0, 0, -1};
void bfs(vvi &grid, vvi &visited, int x, int y)
{
    queue<pii> que;
    que.push({x, y});
    visited[x][y] = 1; // 只要加入队列，立刻标记
    while (!que.empty())
    {
        pii cur = que.front();
        que.pop();
        int curx = cur.first;
        int cury = cur.second;
        for (auto &&i : dir)
        {
            int nextx = curx + i[0], nexty = cury + i[1];
            if (nextx < 0 || nextx >= grid.size() || nexty < 0 || nexty >= grid[0].size())
            {
                continue;
            } // 越界了，直接跳过
            if (!visited[nextx][nexty] and grid[nextx][nexty] == 1)
            {
                que.push({nextx, nexty});
                visited[nextx][nexty] = 1; // 只要加入队列立刻标记
            }
        }
    }
}

signed main()
{
    BUFF;
    int n, m;
    cin >> n >> m;
    vvi grid(n, vi(m)), visited(n, vi(m, 0));
    for (auto &&i : grid)
    {
        cin >> i;
    }
    int result = 0;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if(visited[i][j])
            {
                continue;
            }
            visited[i][j] = 1;
            if(grid[i][j])
            {
                result++;
                bfs(grid, visited, i, j);
            }
        }
    }
    cout << result;
}