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

    vector<int> wenhao;
    for (int i = 0; i < n; i++)
    {
        if (s[i] == '?')
        {
            wenhao.emplace_back(i);
        }
    }
    int ans = 0;
    auto check = [&]() -> void
    {
        int cnt10 = 0, cnt01 = 0;
        for (int i = 0; i + 1 < s.size(); i++)
        {
            if (s[i] == '1' and s[i + 1] == '0')
            {
                cnt10++;
            }
            if (s[i] == '0' and s[i + 1] == '1')
            {
                cnt01++;
            }
        }

        if (cnt01 == cnt10)
        {
            ans = (ans + 1) % MOD;
        }
    };

    auto takeplace = [&]()
    {
        for (int i = 0; i < n; i++)
        {
            if (s[i] == '1')
            {
                s[i] = '0';
            }
            else
            {
                s[i] = '1';
            }

            check();

            if (s[i] == '1')
            {
                s[i] = '0';
            }
            else
            {
                s[i] = '1';
            }
        }
    };

    map<string, int> mp;
    
    auto backtracking = [&](auto &&self, int startindex) -> void
    {
        if (startindex == wenhao.size() and mp[s] == 0)
        {
            takeplace();
            mp[s]++;
            return;
        }

        for (int i = startindex; i < wenhao.size(); i++)
        {
            for (auto &&x : {'0', '1'})
            {
                s[wenhao[i]] = x;
                self(self, i + 1);
            }
        }
    };
    backtracking(backtracking, 0);
    cout << ans;
}

signed main()
{
    cin.tie(nullptr)->sync_with_stdio(false);
    cout << setiosflags(ios::fixed) << setprecision(2);
    int TT = 1;
    cin >> TT;
    while (TT--)
    {
        solve();
        cout << endl;
    }
}