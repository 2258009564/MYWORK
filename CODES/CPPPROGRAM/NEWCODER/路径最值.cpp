#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cin >> n;
    int arr[n][n] = {};
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j <= i; j++)
        {
            cin >> arr[i][j];
        }
    }
    int dp[n][n] = {}; // dp[i][j] = i,j 的最大和
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            dp[i][j] = arr[i][j];
        }
    }
    for (int i = 1; i < n; i++)
    {
        dp[i][0] += dp[i - 1][0];
    }
    for (int i = 1; i < n; i++)
        for (int j = 1; j < n; j++)
        {
            dp[i][j] += max(dp[i - 1][j], dp[i - 1][j - 1]);
        }
    int maxnum = INT_MIN;
    for (int i = 0; i < n; i++)
    {
        maxnum = max(maxnum, dp[n - 1][i]);
    }
    cout << maxnum;
}