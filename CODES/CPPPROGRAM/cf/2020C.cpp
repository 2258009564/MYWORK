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
    int b, c, d;
    cin >> b >> c >> d;
    string sb, sc, sd;
    while (b)
    {
        sb += ((b & 1) ? '1' : '0');
        b >>= 1;
    }
    while (c)
    {
        sc += ((c & 1) ? '1' : '0');
        c >>= 1;
    }
    while (d)
    {
        sd += ((d & 1) ? '1' : '0');
        d >>= 1;
    }

    auto maxsize = max({sb.size(), sc.size(), sd.size()});
    sb += string(maxsize - sb.size(), '0');
    sc += string(maxsize - sc.size(), '0');
    sd += string(maxsize - sd.size(), '0');
    ranges::reverse(sb);
    ranges::reverse(sc);
    ranges::reverse(sd);
    // cout << sb << ' ' << sc << ' ' << sd << endl;
    string sa(maxsize, '0');
    for (int i = 0; i < maxsize; i++)
    {
        if ((sb[i] == '1' and sc[i] == '0' and sd[i] == '0') or (sb[i] == '0' and sc[i] == '1' and sd[i] == '1'))
        {
            cout << -1;
            return;
        }
        for (auto &&x : {'0', '1'})
        {
            if (((x - '0') | (sb[i] - '0')) - ((x - '0') & (sc[i] - '0')) == sd[i] - '0')
            {
                sa[i] = x;
            }
        }
    }
    int ans = 0, base = 1;
    for (int i = sa.size() - 1; i >= 0; i--)
    {
        ans += base * (sa[i] - '0');
        base <<= 1;
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