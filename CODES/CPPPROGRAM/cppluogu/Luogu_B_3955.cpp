
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
    int mid = n / 2;
    char arr[n][n] = {};
    for (int j = 0; j < n; j++)
    {
        arr[0][j] = arr[n - 1][j] = arr[mid][j] = '-';
    }
    for (int i = 0; i < n; i++)
    {
        arr[i][0] = arr[i][n - 1] = '|';
    }
    for (auto &&v : arr)
    {
        for (auto &&i : v)
        {
            cout << (i == 0 ? 'x' : i);
        }
        cout << endl;
    }
}
