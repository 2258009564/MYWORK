#include <bits/stdc++.h>
using namespace std;
int mx[4] = {-1, 1, 0, 0}, my[4] = {0, 0, -1, 1};
int s[6][6], p[6][6];
int n, m, t, x1, x2, y1, y2, a, b, ans;
void dfs(int c, int d)
{
    if (c > n || d > m || c == 0 || d == 0)
    {
        return;
    }
    if (c == x2 && d == y2)
    {
        ans++;
        return;
    }
    else
    {
        for (int i = 0; i < 4; i++)
        {
            int nx = c + mx[i], ny = d + my[i];
            if (nx > 0 && nx <= n && ny > 0 && ny <= m && s[nx][ny] == 0 && p[nx][ny] == 0)
            {
                s[nx][ny] = 1;
                dfs(nx, ny);
                s[nx][ny] = 0;
            }
            else
                continue;
        }
    }
}
int main()
{
    cin >> n >> m >> t;
    cin >> x1 >> y1 >> x2 >> y2;
    s[x1][y1] = 1;
    for (int i = 1; i <= t; i++)
    {
        cin >> a >> b;
        p[a][b] = 1;
    }
    dfs(x1, y1);
    cout << ans;
    return 0;
}