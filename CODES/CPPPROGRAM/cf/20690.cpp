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
    n -= 2;
    vector<int> v(n);
    for (int i = 0; i < n; i++)
    {
        cin >> v[i];
    }
    if (n == 1)
    {
        cout << "YES" << endl;
        return;
    }
    for (int i = 1; i + 1 < n; i++)
    {
        if (v[i - 1] == 1 and v[i] == 0 and v[i + 1] == 1)
        {
            cout << "NO" << endl;
            return;
        }
    }
    cout << "YES" << endl;
    //   0 1 0 1 1 0 0 1
    // 1 2 2 2 3 3
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
        // cout << endl;
    }
}