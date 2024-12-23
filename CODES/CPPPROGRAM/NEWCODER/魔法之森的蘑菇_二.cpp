#include <bits/stdc++.h>
using namespace std;
#define int long long
#define endl '\n'

void solve()
{
    int n, m;
    cin >> n >> m;
    vector<string> vec(n);
    for (auto &i : vec)
    {
        cin >> i;
    }

    int total = 0;
    int X1 = 0, Y1 = 0, X2 = 0, Y2 = 0;

    for (int x1 = 0; x1 < n; x1++)
    {
        for (int x2 = x1; x2 < n; x2++)
        {
            for (int y1 = 0; y1 < m; y1++)
            {
                for (int y2 = y1; y2 < m; y2++)
                {
                    bool found = true;

                    for (int i = x1; i <= x2 && found; i++)
                    {
                        for (int j = y1; j <= y2 && found; j++)
                        {
                            if (vec[i][j] == '*') 
                            {
                                found = false;
                            }
                        }
                    }

                    if (found)
                    {
                        int area = (x2 - x1 + 1) * (y2 - y1 + 1);
                        if (area > total) 
                        {
                            total = area;
                            X1 = x1;
                            Y1 = y1;
                            X2 = x2;
                            Y2 = y2;
                        }
                    }
                }
            }
        }
    }

    cout << X1 + 1 << " " << Y1 + 1 << " " << X2 + 1 << " " << Y2 + 1 << endl;
}

signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    solve();
}
