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
    map<int, int> mp1, mp2;
    int num;
    for (int i = 0; i < n; i++)
    {
        cin >> num;
        mp1[num]++;
    }
    for (int i = 0; i < n; i++)
    {
        cin >> num;
        mp2[num]++;
    }

    if (mp1.size() * mp2.size() > 2)
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
    cin.tie(nullptr)->sync_with_stdio(false);
    int TT = 1;
    cin >> TT;
    while (TT--)
    {
        solve();
        cout << endl;
    }
}