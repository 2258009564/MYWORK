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
    int n;
    cin >> n;
    string s;
    cin >> s;

    string s1 = "CHICKEN ";
    if (s == s1.substr(0, 7))
    {
        cout << "YES";
        return;
    }

    int index = 0;
    map<char, int> mp;
    for (int i = 0; i < n; i++)
    {
        if (s[i] == s1[index])
        {
            index++;
        }
        else
        {
            mp[s[i]]++;
        }
    }

    if (index != 7)
    {
        cout << "NO";
        return;
    }

    vector<int> freq;
    for (auto &&[k, v] : mp)
    {
        freq.emplace_back(v);
    }

    auto tot = accumulate(freq.begin(), freq.end(), 0ll); // 3
    int maxnum = ranges::max(freq);
    if (tot % 2 == 0 and maxnum * 2 <= tot)
    {
        cout << "YES";
    }
    else
    {
        cout << "NO";
    }
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