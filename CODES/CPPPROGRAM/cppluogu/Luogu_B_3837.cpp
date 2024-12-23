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
    char c = 'A';
    int n;
    cin >> n;
    int row = 1;
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= row; j++)
        {
            cout << c;
            c = (c - 'A' + 1) % 26 + 'A';
        }
        cout << endl;
        row++;
    }
}