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
    int n, k;
    cin >> n >> k;
    int arr[n];
    for (auto &&i : arr)
    {
        cin >> i;
    }
    int total = 0;
    for (auto &&i : arr)
    {
        if (i > 0 and i >= arr[k - 1])
        {
            total++;
        }
    }
    cout << total;
}