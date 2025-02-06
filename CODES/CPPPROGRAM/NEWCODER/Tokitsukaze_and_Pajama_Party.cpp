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
    cin >> n;
    string s, s1 = "uwawauwa";
    cin >> s;

    vector<int> poss, uposs;
    for (int i = 0; i + 7 < s.size(); i++)
    {
        if (s[i] == 'u' and s[i + 1] == 'w' and s[i + 2] == 'a' and s[i + 3] == 'w' and s[i + 4] == 'a' and s[i + 5] == 'u' and s[i + 6] == 'w' and s[i + 7] == 'a')
        {
            poss.emplace_back(i);
        }
        if (s[i] == 'u')
        {
            uposs.emplace_back(i);
        }
    }
    if (poss.size() == 0)
    {
        cout << 0;
        return;
    }

    int ans = 0;
    for (auto &&pot : uposs)
    {
        // 对于每一个点 的索引
        auto it = upper_bound(poss.begin(), poss.end(), pot);
        if (it == poss.end())
        {
            continue;
        }
        if (*it == pot + 1)
        {
            it++;
        }
        ans += poss.end() - it;
    }

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