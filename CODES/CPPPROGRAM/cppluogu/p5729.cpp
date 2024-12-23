#include <bits/stdc++.h>
using namespace std;
#define int long long
#define endl '\n'

signed main() {
    int w, x, h, q, total = 0;
    cin >> w >> x >> h >> q;
    int x1, x2, y1, y2, z1, z2;
    int arr[w][x][h] = {1};
    while(q--)
    {
        cin >> x1 >> y1 >> z1 >> x2 >> y2 >> z2;
        for (int i = x1; i <= x2;i++)
        {
            for (int j = y1; j <= y2;j++)
            {
                for (int k = z1;k<=z2;k++)
                {
                    arr[i][j][k] = 0;
                }
            }
        }
    }
    for (int i = 0; i < w; i++)
    {
        for (int j = 0; j < x; j++)
        {
            for (int k = 0; k < h; k++)
            {
                total += arr[i][j][k];
            }
        }
    }
    cout << total;
}