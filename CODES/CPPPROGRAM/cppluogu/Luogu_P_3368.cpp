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
    int n, m;
    cin >> n >> m;

    vector<int> v(n + 1, 0);
    for (int i = 1; i <= n; i++)
    {
        cin >> v[i];
    }

    // bit
    vector<int> c(n + 2, 0);
    auto lowbit = [&](int x) -> int
    {
        return x & -x;
    };

    auto add = [&](int i, int val) -> void
    {
        while (i <= n)
        {
            c[i] += val;
            i += lowbit(i);
        }
    };

    auto sum = [&](int i) -> int
    {
        int ans = 0;
        while (i)
        {
            ans += c[i];
            i -= lowbit(i);
        }
        return ans;
    };

    for (int i = 1; i <= n; i++)
    {
        add(i, v[i] - v[i - 1]);
    }

    while (m--)
    {
        int num;
        cin >> num;
        if (num == 1)
        {
            int x, y, k;
            cin >> x >> y >> k;
            add(x, k);
            add(y + 1, -k);
        }
        else
        {
            int x;
            cin >> x;
            cout << sum(x) << endl;
        }
    }
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
        // cout << endl;
    }
}