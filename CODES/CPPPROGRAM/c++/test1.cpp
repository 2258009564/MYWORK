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
    string s = "ANQNANBNQNANQNQNBNINQNQNANQNINANQNANBNQNANQNQNBNBNQNQNANQNINANQNANBNQNANQNQNBNINQNQNANQNINBNQNANBNQN";

    map<string, int> mp;
    for (int i = 1; i <= 10; i++)
    {
        for (int j = 0; j + i < s.size(); j++)
        {
            mp[s.substr(j, i)]++;
        }
    }
    for (auto it = mp.begin(); it != mp.end(); it++)
    {
        pair<string, int> pr = *it;
        cout << pr.first << ' ' << pr.second << ' ' << pr.first.size() * pr.second << endl;
    }
}

/*
void solve()
{
    auto check = [&](string s) -> bool // 检查
    {
        for (int i = 0; i + 4 < s.size(); i++)
        {
            int ans = 0;
            ans += s[i] == '1';
            ans += s[i + 1] == '1';
            ans += s[i + 2] == '1';
            ans += s[i + 3] == '1';
            ans += s[i + 4] == '1';
            if (ans > 3)
            {
                return false;
            }
        }
        return true;
    };
    vector<string> v;
    function<void(string)> backtracking = [&](string s) // 生成
    {
        if (s.size() == 24)
        {
            cout << s << endl;
            v.emplace_back(s);
            return;
        }

        for (auto &&x : {'0', '1'})
        {
            backtracking(s + x);
        }
    };

    backtracking("");
    int ans = 0;
    for (auto &&s : v)
    {
        ans += check(s);
    }
    cout << ans;
}
*/

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