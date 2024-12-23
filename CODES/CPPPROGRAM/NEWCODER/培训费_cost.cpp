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
    int arr[n][3];
    for (auto &&v : arr)
    {
        for (auto &&i : v)
        {
            cin >> i;
        }
    }
    int dp[n][3];
    for (int i = 0; i < 3; i++)
    {
        dp[0][i] = arr[0][i];
    }
    for (int i = 1; i < n; i++)
    {
        dp[i][0] = arr[i][0] + min(dp[i - 1][1], dp[i - 1][2]);
        dp[i][1] = arr[i][1] + min(dp[i - 1][0], dp[i - 1][2]);
        dp[i][2] = arr[i][2] + min(dp[i - 1][0], dp[i - 1][1]);
    }
    cout << min(dp[n - 1][0], min(dp[n - 1][1], dp[n - 1][2])) << endl;
}