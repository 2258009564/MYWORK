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
    if (s == "N")
    {
        cout << "S";
    }
    else if (s == "S")
    {
        cout << "N";
    }
    else if (s == "E")
    {
        cout << "S";
    }
    else if (s == "S")
    {
        cout << "E";
    }
    else if (s == "NE")
    {
        cout << "SW";
    }
    else if (s == "SW")
    {
        cout << "NE";
    }
    else if (s == "NW")
    {
        cout << "SE";
    }
    else
    {
        cout << "NW";
    }
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