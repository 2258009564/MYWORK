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
    string s;
    cin >> s;
    auto s1 = "ab";
    while (1)
    {
        auto pos = s.find(s1);
        if (pos == string::npos)
        {
            break;
        }

        s.erase(pos, 2);
    }

    cout << (s.empty() ? "Good" : "Bad");
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