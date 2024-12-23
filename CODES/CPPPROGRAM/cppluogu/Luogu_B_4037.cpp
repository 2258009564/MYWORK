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
    int arr[n][n] = {};
    for (int i = 0; i < n; i++)
    {
        arr[i][0] = arr[i][n - 1] = 1;
    }
    int pointer = 0;
    for (auto &&i : arr)
    {
        i[pointer++] = 1;
    }
    for (auto &&v : arr)
    {
        for (auto &&i : v)
        {
            cout << (i ? '+' : '-');
        }
        cout << endl;
    }
}