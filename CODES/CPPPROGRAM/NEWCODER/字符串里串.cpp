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
    int n;
    string s;
    cin >> n >> s;
    map<char, int> mp;
    int ans = 0;
    for (int i = n - 1; i >= 1; i--)
    {
        auto c = s[i];
        mp[c]++;
        if (mp[c] == 2)
        {
            ans = max(ans, i + 1);
            break;
        }
    }
    ranges::reverse(s);
    mp.clear();
    for (int i = n - 1; i >= 1; i--)
    {
        auto c = s[i];
        mp[c]++;
        if (mp[c] == 2)
        {
            ans = max(ans, i + 1);
            break;
        }
    }
    cout << ans;
}

signed main()
{
    cin.tie(nullptr)->sync_with_stdio(false);
    int TT = 1;
    // cin >> TT;
    while (TT--)
    {
        solve();
        cout << endl;
    }
}