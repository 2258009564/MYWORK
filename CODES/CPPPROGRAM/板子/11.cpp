#include <bits/stdc++.h>
using namespace std;
#define int long long
const int N = 1010;
char a[N][N];
signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int t;
    t = 1;
    // cin>>t;
    while (t--)
    {
        int n;
        cin >> n;
        for (int i = 1; i <= n; i++)
        {
            for (int j = n; j >= i; j--)
            {
                if (i % 2 == 1)
                {
                    a[i][j] = a[j][i] = '0';
                }
                else
                {
                    a[i][j] = a[j][i] = '1';
                }
            }
        }
        for (int i = 1; i <= n; i++)
        {
            for (int j = 1; j <= n; j++)
            {
                cout << a[i][j];
            }
            cout << "\n";
        }
    }
    return 0;
}