#include <bits/stdc++.h>
using namespace std;
#define int long long
#define endl '\n'

signed main() {
    int n;
    cin >> n;
    vector<int> dp(n + 1);
    dp[0] = 1; // 无意义
    dp[1] = 1;
    dp[2] = 2;// 1 2   2 1
    dp[3] = 5;// 1 2 3   1 3 2
    /*
    dp[i+1] = dp[i] + i;
    */
}