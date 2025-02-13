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

    int totalnum = n;
    vector<int> dp1(n, 1ll), dp2(n, 1ll);

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < i; j++)
        {
            if (v[i] > v[j])
            {
                dp1[i] = max(dp1[i], dp1[j] + 1);
            }
        }
    }

    for (int i = n - 1; i >= 0; i--)
    {
        for (int j = n - 1; j > i; j--)
        {
            if (v[i] > v[j])
            {
                dp2[i] = max(dp2[i], dp2[j] + 1);
            }
        }
    }

    int ans = 0;
    for (int i = 0; i < n; i++)
    {
        ans = max(ans, dp1[i] + dp2[i] - 1);
    }

    cout << totalnum - ans;
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