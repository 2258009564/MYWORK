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

    ranges::sort(v);

    int num1 = v[n / 4], num2 = v[3 * n / 4];
    int res = 1e18;
    for (auto &&x : {num1 - 1, num1})
    {
        for (auto &&y : {num2, num2 + 1})
        {
            if (x == y)
            {
                continue;
            }
            int ans = 0;
            for (int i = 0; i < n / 2; i++)
            {
                ans += abs(x - v[i]);
                ans += abs(y - v[n / 2 + i]);
            }
            res = min(ans, res);
        }
    }

    cout << res;
}

signed main()
{
    cin.tie(nullptr)->ios::sync_with_stdio(false);
    cout << setiosflags(ios::fixed) << setprecision(2);
    int TT = 1;
    cin >> TT;
    while (TT--)
    {
        solve();
        cout << endl;
    }
}