#include <bits/stdc++.h>
using namespace std;
#define int long long
#define endl '\n'

signed main()
{
    int n, total = 0;
    cin >> n;
    int arr[n][4];
    for (auto &arr1 : arr)
    {
        cin >> arr1[0] >> arr1[1] >> arr1[2];
        arr1[3] = arr1[0] + arr1[1] + arr1[2];
    }
    for (int i = 0; i < n - 1; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            if (abs(arr[i][0] - arr[j][0]) <= 5 && abs(arr[i][1] - arr[j][1]) <= 5 && abs(arr[i][2] - arr[j][2]) <= 5 && abs(arr[i][3] - arr[j][3]) <= 10)
            {
                total++;
            }
        }
    }
    cout << total;
}