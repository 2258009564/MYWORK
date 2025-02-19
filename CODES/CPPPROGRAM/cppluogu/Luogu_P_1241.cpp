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
    string s;
    cin >> s;
    int n = s.size();
    if (n == 0)
    {
        cout << "";
        return;
    }
    vector<int> ok(n, 0); // 用来记录哪些是配对成功的
    stack<char> stk;
    map<char, char> mp;
    mp[']'] = '[', mp[')'] = '(', mp['['] = ']', mp['('] = ')';
    auto isleft = [&](char c) -> bool
    {
        return c == '[' or c == '(';
    };

    string ans;
    for (int i = 0; i < n; i++)
    {
        auto c = s[i];
        if (isleft(c))
        {
            stk.push(i);
        }
        else
        {
            // 是右半部分 需要匹配
            if (stk.empty())
            {
                continue;
            }
            auto ll = stk.top();
            if (s[ll] == mp[c])
            {
                ok[ll] = ok[i] = 1; // 匹配的话就打标记
                stk.pop();
            }
            // 不匹配 但是左侧括号是不是应该删去？
        }
    }
    for (int i = 0; i < n; i++)
    {
        if (!ok[i])
        {
            ans += min(s[i], mp[s[i]]);
            ans += max(s[i], mp[s[i]]);
        }
        else
        {
            ans += s[i];
        }
    }
    cout << ans;
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