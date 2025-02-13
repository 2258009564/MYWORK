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

    string s;
    cin >> s;

    bool canReduce = 0;
    for (int i = 0; i + 1 < s.size(); i++)
    {
        if (s[i] == s[i + 1])
        {
            canReduce = 1;
            break;
        }
    }

    cout << (canReduce ? 1 : (int)s.size());
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