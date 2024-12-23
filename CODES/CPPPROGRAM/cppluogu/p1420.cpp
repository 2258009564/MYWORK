#include <bits/stdc++.h>
using namespace std;
#define int long long
#define endl '\n'

signed main()
{
    int n, total = 1, max_total = INT_MIN;
    cin >> n;
    int arr[n];
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    for (int i = 0; i < n - 1; i++)
    {
        if (arr[i] + 1 != arr[i + 1]) // 1 2 3 4 5
        {
            max_total = max(max_total, total);
            total = 1;
        }
        else
        {
            // arr[i]+1 = arr[i+1]
            total++;
        }
    }
    max_total = max(max_total, total);

    cout << max_total;
}