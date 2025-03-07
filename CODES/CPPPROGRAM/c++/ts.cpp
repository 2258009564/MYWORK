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
    vector<string> v(n);
    for (int i = 0; i < n; i++)
    {
        cin >> v[i];
    }

    int k;
    cin >> k;
    cin.ignore();
    string s;
    getline(cin, s);
    int ans = 0;
    for (int i = 0; i < s.size(); i++)
    {
        for (auto &&ss : v)
        {

            if (s.substr(i, ss.size()) == ss)
            {
                ans++;
                s = s.substr(0, i) + '-' + s.substr(i + ss.size());
            }
        }
    }
    if (ans >= k)
    {
        cout << ans << endl
             << "He Xie Ni Quan Jia!";
        return;
    }
    for (int i = 0; i < s.size(); i++)
    {
        if (s[i] == '-')
        {
            cout << "<censored>";
        }
        else
        {
            cout << s[i];
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
        cout << endl;
    }
}