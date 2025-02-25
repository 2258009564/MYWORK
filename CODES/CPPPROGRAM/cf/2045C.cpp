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
    string a, b;
    cin >> a >> b;
    map<char, int> mp;                 // 记录a中字符第一个出现的位置
    for (int i = 1; i < a.size(); i++) // a一定要出现一个字符 因为需要前缀
    {
        if (mp.count(a[i]) == 0)
        {
            mp[a[i]] = i;
        }
    }
    int ans = INT_MAX;
    string s = "";
    for (int j = 1; j < b.size(); j++)
    {
        char x = b[b.size() - j - 1];
        if (mp.count(x) and j + mp[x] < ans)
        {
            s = a.substr(0, mp[x] + 1) + b.substr(b.size() - j);
            ans = mp[x] + j;
        }
    }
    cout << (s.size() == 0 ? "-1" : s);
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