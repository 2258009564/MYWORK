// #pragma GCC optimize(2)
#include <bits/stdc++.h>
using namespace std;
#define int long long
#define endl '\n'
#define all(x) (x).begin(), (x).end()

const int INF = 1e9;     // 无穷大
const int INFLL = 1e18;  // 长整型无穷大
const int MOD = 1e9 + 7; // 模数
// -9.2e18 ~ 9.2e18

void solve()
{
    int n, x;
    cin >> n >> x;
    int count = 0;
    vector<int> ans(n, 0);
    for (int i = 0; i < n; i++)
    {
        if ((x | i) == x)
        {
            ans[i] = i, count |= i;
        }
        else
        {
            break;
        }
    }
    if (count != x)
    {
        ans[n - 1] = x;
    }

    for (int i = 0; i < n; i++)
    {
        cout << ans[i] << ' ';
    }
}

signed main()
{
    cin.tie(0)->ios::sync_with_stdio(0);
    cout << setiosflags(ios::fixed) << setprecision(2);
    int TT = 1;
    cin >> TT;
    while (TT--)
    {
        solve();
        cout << endl;
    }
}