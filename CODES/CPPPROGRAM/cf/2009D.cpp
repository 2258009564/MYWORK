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
    map<int, int> mp0, mp1;
    vector<int> y0, y1;
    for (int i = 0; i < n; i++)
    {
        int x, y;
        cin >> x >> y;
        if (y == 0)
        {
            mp0[x]++;
            y0.emplace_back(x);
        }
        else
        {
            mp1[x]++;
            y1.emplace_back(x);
        }
    }
    int ans = 0;
    for (auto &&x : y0)
    {
        if (mp0[x] and mp1[x])
        {
            ans += n - 2;
        }
    }
    for (auto &&x : y0)
    {
        ans += (mp1[x - 1] and mp1[x + 1]);
    }
    for (auto &&x : y1)
    {
        ans += (mp0[x - 1] and mp0[x + 1]);
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