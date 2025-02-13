// #pragma GCC optimize(2)
#include <bits/stdc++.h>
using namespace std;
#define int long long
#define endl '\n'

const int INF = 1e9;     // 无穷大
const int INFLL = 1e18;  // 长整型无穷大
const int MOD = 1e9 + 7; // 模数
// -9.2e18 ~ 9.2e18

void solve()
{
    int num;
    vector<int> v;
    while (cin >> num)
    {
        v.emplace_back(num);
    }
    int n = v.size();

    ranges::reverse(v);

    vector<int> dp(n, 1ll);  // dp[i] 以i结尾 最多能拦截多少枚导弹
    vector<int> dp1(n, 1ll); //

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < i; j++)
        {
            if (v[i] >= v[j])
            {
                dp[i] = max(dp[i], dp[j] + 1);
            }
            else
            {
                dp1[i] = max(dp1[i], dp1[j] + 1);
            }
        }
    }
    cout << ranges::max(dp) << endl
         << ranges::max(dp1);
}

signed main()
{
    cin.tie(nullptr)->ios::sync_with_stdio(false);
    cout << setiosflags(ios::fixed) << setprecision(2);
    int TT = 1;
    // cin >> TT;
    while (TT--)
    {
        solve();
        cout << endl;
    }
}