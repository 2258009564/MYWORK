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
    vector<int> v(n + 1, 0);
    for (int i = 1; i <= n; i++)
    {
        cin >> v[i];
    }
    int ans = n;
    function<void(int)> dfs = [&](int k) // 记录当前长度
    {
        // cout << "k right now is :" << k << endl;
        ans = max(ans, k);
        vector<int> v1;
        for (int i = 1; i <= n; i++)
        {
            if (v[i] == k + 1 - i)
            {
                if (i - 1 != 0)
                v1.emplace_back(i - 1);
            }
        }
        if (v1.size() == 0)
        {
            // cout << "when return k right now is :" << k << endl;
            ans = max(ans, k);
            return;
        }
        for (auto &&i : v1)
        {
            if (i != 0)
            {
                dfs(k + i);
            }
        }
    };
    dfs(n);
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