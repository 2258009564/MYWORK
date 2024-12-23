// #pragma GCC optimize(2)
#include <bits/stdc++.h>
using namespace std;
#define int long long
#define endl '\n'

void solve()
{
    int n;
    cin >> n;
    string s;
    cin >> s;
    int total = 0;
    for (auto &&i : s)
    {
        if(!(i - '0'))
        {
            total++;
        }
    }
    
    cout << total;
}

signed main()
{
    ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
    int T = 1;
    // cin >> T;
    while (T--)
    {
        solve();
    }
}