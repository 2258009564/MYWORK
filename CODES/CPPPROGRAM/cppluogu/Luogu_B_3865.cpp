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
    int left = 0, right = n - 1;
    for (auto &&v : arr)
    {
        v[left++] = v[right--] = 1;
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