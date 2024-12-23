// #pragma GCC optimize(2)
#include <bits/stdc++.h>
using namespace std;
#define int long long
#define endl '\n'

signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int n;
    cin >> n;
    int a[n][n] = {};
    int x = 0, y = n / 2;
    a[x][y] = 1;
    for (int cnt = 2; cnt <= n * n; cnt++)
    {
        int tx = (x + n - 1) % n, ty = (y + 1) % n;
        if (!a[tx][ty])
            a[x = tx][y = ty] = cnt;
        else
            a[x = (x + 1) % n][y] = cnt;
    }
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
            cout << a[i][j] << " ";
        cout << endl;
    }
}