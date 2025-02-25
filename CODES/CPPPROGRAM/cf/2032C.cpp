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
    vector<int> v(n);
    for (int i = 0; i < n; i++)
    {
        cin >> v[i];
    }
    ranges::sort(v);

    // a_i + a_j > a_k
    vector<int> v1(n, 0); // v1[i]记录的是 v[i] + v[i + 1] 所以i个元素在他之前
    for (int i = 0; i + 1 < n; i++)
    {
        v1[i] = v[i] + v[i + 1];
    }
    int ans = INT_MAX;
    for (int i = 0; i + 1 < n; i++)
    {
        auto it = ranges::lower_bound(v, v1[i]); // 找比v1 更大的那个元素
        ans = min(ans, i + distance(it, v.end()));
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