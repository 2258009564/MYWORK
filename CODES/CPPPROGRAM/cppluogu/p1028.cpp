#include <bits/stdc++.h>
using namespace std;
#define int long long
#define endl '\n'

int find1(int n)
{
    int total = 0;
    vector<int> dp(n + 1);
    dp[1] = 1;
    for (int i = 2; i <= n; i++)
    {
        dp[i] = 1;
        for (int j = 1; j <= i / 2; j++)
        {
            dp[i] += dp[j];
        }
    }
    return dp[n];
}

signed main()
{
    int n;
    cin >> n;
    cout << find1(n);
}