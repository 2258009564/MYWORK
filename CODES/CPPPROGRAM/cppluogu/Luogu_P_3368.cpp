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
    vector<int> v(n + 1, 0), c(n + 1, 0);
    // bit
    auto lb = [&](int x) -> int
    {
        return x & -x;
    };
    auto add = [&](int i, int val) -> void
    {
        while (i <= n)
        {
            c[i] += val;
            i += lb(i);
        }
    };
    auto sum = [&](int i) -> int
    {
        int ans = 0;
        while (i)
        {
            ans += c[i];
            i -= lb(i);
        }
        return ans;
    };
    // bit
    for (int i = 1; i <= n; i++)
    {
        cin >> v[i];
        add(i, c[i]);
    }

    int num;
    while (cin >> num)
    {
        if (num == 1)
        {
            int x, y, k;
            cin >> x >> y >> k;
            for (int i = x; i <= y; i++)
            {
                add(i, k);
            }
        }
        else
        {
            int x;
            cin >> x;
            cout << sum(x) - sum(x - 1) << endl;
        }
    }
}

signed main()
{
    cin.tie(nullptr)->ios::sync_with_stdio(false);
    cout << setiosflags(ios::fixed) << setprecision(2);
    int TT = 1;
    // cin >> TT;
    while (TT--)
    {
        solve();
        cout << endl;
    }
}