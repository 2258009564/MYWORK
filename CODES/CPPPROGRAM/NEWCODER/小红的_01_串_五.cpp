#include <bits/stdc++.h>
using namespace std;
#define int long long

int mod = 1e9 + 7;

signed main()
{
    string s;
    cin >> s;
    int n = s.size();

    vector<vector<int>> dp(n + 1, vector<int>(13, 0));
    dp[0][0] = 1;

    for (int i = 0; i < n; i++)
    {
        for (int r = 0; r < 13; r++)
        {
            if (dp[i][r] > 0)
            {
                if (s[i] == '?')
                {
                    dp[i + 1][(r * 10 + 0) % 13] = (dp[i + 1][(r * 10 + 0) % 13] + dp[i][r]) % mod;
                    dp[i + 1][(r * 10 + 1) % 13] = (dp[i + 1][(r * 10 + 1) % 13] + dp[i][r]) % mod;
                }
                else
                {
                    int num = s[i] - '0';
                    dp[i + 1][(r * 10 + num) % 13] = (dp[i + 1][(r * 10 + num) % 13] + dp[i][r]) % mod;
                }
            }
        }
    }

    cout << dp[n][0] << endl;
}
