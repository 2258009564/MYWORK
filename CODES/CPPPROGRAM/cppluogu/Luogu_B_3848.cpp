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
    int total = 0;
    int arr[n];
    for (auto &&i : arr)
    {
        cin >> i;
    }
    int x;
    cin >> x;
    for (auto &&i : arr)
    {
        if (x >= i)
        {
            x -= i;
            total++;
        }
    }
    cout << total;
}