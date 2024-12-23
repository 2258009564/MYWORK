#pragma GCC optimize(2)
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
    vector<int> arr(n);
    for (auto &&i : arr)
    {
        cin >> i;
    }

    sort(arr.begin(), arr.end());
    int l = arr[0], r = arr[n - 1];
    int d1 = r - l;
    int x;
    cin >> x;

    for (auto &&i : arr)
    {
        if (i > 0)
        {
            i -= x;
        }
        else
        {
            i += x;
        }
    }
    sort(arr.begin(), arr.end());
    int d2 = arr[n - 1] - arr[0];
    cout << min(d1, d2);
}
