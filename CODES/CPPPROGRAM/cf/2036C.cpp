// #pragma GCC optimize(2)
#include <bits/stdc++.h>
using namespace std;
#define int long long
#define endl '\n'

const int INF = 1e9;     // 无穷大
const int INFLL = 1e18;  // 长整型无穷大
const int MOD = 1e9 + 7; // 模数

void solve()
{
    string s, s1 = "1100";
    cin >> s;
    int cnt = 0;
    for (int i = 0; i + 3 < s.size(); i++)
    {
        cnt += s.substr(i, 4) == s1;
    }
    int q;
    cin >> q;
    auto ffind = [&](int i) -> bool
    {
        // i is index so i + 3 < s.size()
        if (i + 3 >= s.size())
        {
            return 0;
        }
        return s.substr(i, 4) == s1;
    };
    while (q--)
    {
        int a;
        char b;
        cin >> a >> b;
        a--; // 0-based
        bool before = 0, after = 0;
        for (int i = max(0ll, a - 3); i <= a; i++)
        {
            if (ffind(i))
            {
                before = 1;
                break;
            }
        }
        s[a] = b;
        for (int i = max(0ll, a - 3); i <= a; i++)
        {
            if (ffind(i))
            {
                after = 1;
                break;
            }
        }
        cnt -= before - after;
        cout << (cnt ? "YES" : "NO") << endl;
    }
}

signed main()
{
    cin.tie(nullptr)->sync_with_stdio(false);
    int TT = 1;
    cin >> TT;
    while (TT--)
    {
        solve();
        // cout << endl;
    }
}