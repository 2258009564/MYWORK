// #pragma GCC optimize(2)
#include <bits/stdc++.h>
using namespace std;
#define int long long
#define endl '\n'

const int INF = 1e9;     // 无穷大
const int INFLL = 1e18;  // 长整型无穷大
const int MOD = 1e9 + 7; // 模数
// -9.2e18 ~ 9.2e18

void solve()
{
    int n, m, k;
    cin >> n >> m >> k;

    if (k > max(n, m))
    {
        cout << -1;
        return;
    }
    if (n == 0 and m == 0)
    {
        cout << -1;
        return;
    }

    if (n == 0 or m == 0 and k != max(n, m))
    {
        cout << -1;
        return;
    }

    string s;
    if (n >= m)
    {
        for (int i = 0; i < k; i++)
        {
            if (n > 0)
            {
                s += '0';
                n--;
            }
            if (m > 0)
            {
                s += '1';
                m--;
            }
        }

        s.append(n, '0');
        s.append(m, '1');
    }
    else
    {
        for (int i = 0; i < k; i++)
        {
            if (m > 0)
            {
                s += '1';
                m--;
            }
            if (n > 0)
            {
                s += '0';
                n--;
            }
        }
        s.append(n, '0');
        s.append(m, '1');
    }

    cout << s;
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