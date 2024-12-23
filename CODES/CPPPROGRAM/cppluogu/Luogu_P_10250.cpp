// #pragma GCC optimize(2)
#include <bits/stdc++.h>
using namespace std;
#define int long long
#define endl '\n'

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int n;
    cin >> n;
    int dp[n + 1];// dp[i] 上i个台阶的总共方案数
    dp[0] = 0;
    dp[1] = 1;
    dp[2] = 2;
    /*
    1 1 1
    1 2
    2 1
    3
    */
    dp[3] = 4;
    for (int i = 4; i <= n;i++)
    {
        dp[i] = dp[i - 1] + dp[i - 2] + dp[i - 3];
    }
    cout << dp[n];
}