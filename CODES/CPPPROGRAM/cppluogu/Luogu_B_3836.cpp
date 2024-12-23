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
    int x, y, z, n, m;
    int total = 0;
    cin >> x >> y >> z >> n >> m;
    for (int i = 0; i <= m; i++)
    {
        for (int j = 0; j <= m - i; j++)
        {
            double k = m - i - j;
            if (i * x + j * y + k / z == n)
            {
                total++;
            }
        }
    }
    cout << total;
}