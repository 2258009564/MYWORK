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
    pair<int, int> pr = {0, 0};
    for (int i = 0; i < n; i++)
    {
        int num;
        cin >> num;
        vector<int> v(num, 0);
        for (int i = 0; i < num; i++)
        {
            cin >> v[i];
        }

        auto check = [&]() -> pair<int, int>
        {
            int ok = 0;
            vector<int> ab(2);
            for (int i = 0; i < num; i++)
            {
                if (i != v[i])
                {
                    ab[ok++] = i;
                }
                if (ok == 2)
                {
                    return {ab[0], ab[1]};
                }
            }
            if (ok == 0)
            {
                return {num, num};
            }
            return {ab[0], num};
        };
        auto pr1 = check();
        if (pr.second < pr1.second)
        {
            pr = pr1;
        }
    }
    int k = pr.second;
    if (m <= k)
    {
        cout << (m + 1) * k;
        return;
    }
    int ans = 0;
    for (int i = 0; i < k; i++)
    {
        ans += k;
    }
    for (int i = k; i <= m; i++)
    {
        ans += m;
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