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
    int n;
    cin >> n;
    vector<int> v(n);
    for (int i = 0; i < n; i++)
    {
        cin >> v[i];
    }

    vector dp = v; // dp[i] 表示 以i结尾的最大上升子序列和

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < i; j++)
        {
            if (v[i] > v[j])
            {
                dp[i] = max(dp[i], dp[j] + v[i]);
            }
        }
    }

    cout << ranges::max(dp);
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