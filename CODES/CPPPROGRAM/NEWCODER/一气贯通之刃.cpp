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
    vector<int> degree(n, 0);
    int v1, v2;
    while (cin >> v1 >> v2)
    {
        degree[--v1]++;
        degree[--v2]++;
    }
    vector<int> v;
    for (int i = 0; i < n; i++)
    {
        if (degree[i] > 2 or degree[i] < 1)
        {
            cout << -1;
            return;
        }
        if (degree[i] == 1)
        {
            v.emplace_back(i);
        }
    }
    cout << v[0] + 1 << ' ' << v[1] + 1;
}

signed main()
{
    cin.tie(0)->ios::sync_with_stdio(0);
    cout << setiosflags(ios::fixed) << setprecision(2);
    int TT = 1;
    // cin >> TT;
    while (TT--)
    {
        solve();
        cout << endl;
    }
}