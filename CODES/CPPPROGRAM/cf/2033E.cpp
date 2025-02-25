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
    int n;
    cin >> n;
    vector<int> v(n + 1, 0), vis = v;
    for (int i = 1; i <= n; i++)
    {
        cin >> v[i];
    }
    int ans = 0;
    for (int i = 1; i <= n; i++)
    {
        int tot = 0;
        int x = i;
        while (!vis[x])
        {
            tot++;
            vis[x] = 1;
            x = v[x];
        }
        ans += (tot - 1) / 2;
    }
    cout << ans;
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