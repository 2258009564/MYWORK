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
    string s;
    cin >> s;
    int r = ranges::count(s, '1'), l = 0, m, ans;
    while (l <= r) // 免费获得的数字数量
    {
        m = l + (r - l) / 2;
        auto f = [&](int m) -> bool
        {
            int n = s.size();
            vector<int> used(n, 0);
            for (int i = n - 1; i >= 0; i--)
            {
                if (s[i] == '1' and m)
                {
                    m--, used[i] = 1;
                }
            }

            int cur = 0;
            for (int i = 0; i < n; i++)
            {
                cur += (used[i] == 1 ? -1 : 1);
                if (cur < 0)
                {
                    return 0;
                }
            }
            return 1;
        };
        if (f(m))
        {
            l = (ans = m) + 1;
        }
        else
        {
            r = m - 1;
        }
    }
    int res = 0;
    for (int i = n - 1; i >= 0; i--)
    {
        if (s[i] == '1' and ans)
        {
            ans--;
        }
        else
        {
            res += i + 1;
        }
    }
    cout << res;
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