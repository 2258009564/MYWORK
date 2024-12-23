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
    int n, x, y, z, t;
    cin >> n >> x >> y >> z >> t;
    vector<pair<int, int>> vec(n);
    for (auto &&pr : vec)
    {
        int num1, num2;
        cin >> num1 >> num2 >> pr.second;
        pr.first = num1 + num2;
    }
    // pr.first = value pr.second = weight
    //  不卖东西 金币为t
    //  int money1 = t;
    //  int dp[t + 1] = {};
    //  for (int i = 0; i < vec.size(); i++)
    //  {
    //      for(int j = t; j >= )
    //  }
    int money = t + z;
    int fighttotal1 = 0;
    for (auto &&pr : vec)
    {
        if (pr.second <= money)
        {
            fighttotal1 = max(fighttotal1, pr.first);
        }
    }
    cout << max(fighttotal1, x + y);
}