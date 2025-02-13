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
    vector<pair<int, int>> v(n);
    for (auto &&[x, y] : v)
    {
        cin >> x >> y;
    }

    ranges::sort(v);

    // 现在每一对pair的first都已经被排序了 所以如果不产生交叉 我们直接找出second 的 LIS就行！
    vector<int> dp(n, 1ll);
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < i; j++)
        {
            if (v[i].second > v[j].second)
            {
                dp[i] = max(dp[i], dp[j] + 1);
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