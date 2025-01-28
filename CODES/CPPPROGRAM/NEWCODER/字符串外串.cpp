// #pragma GCC optimize(2)
#include <bits/stdc++.h>
using namespace std;
#define int long long
#define endl '\n'

const int INF = 1e9;     // 无穷大
const int INFLL = 1e18;  // 长整型无穷大
const int MOD = 1e9 + 7; // 模数

void solve()
{
    int n, m;
    cin >> n >> m;
    if (n <= m or n - m - 1 >= 26)
    {
        cout << "NO";
        return;
    }
    cout << "YES" << endl;

    string ans(n, 'a');
    auto x = n - m;

    for (int i = 0; i < n; i++)
    {
        ans[i] = char('a' + i % x);
    }

    cout << ans;
}

signed main()
{
    cin.tie(nullptr)->sync_with_stdio(false);
    int TT = 1;
    cin >> TT;
    while (TT--)
    {
        solve();
        cout << endl;
    }
}