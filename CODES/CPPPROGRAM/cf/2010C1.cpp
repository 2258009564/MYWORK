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
    int k = n / 2;
    

    
    for (int i = k + 1; i < n; i++)
    {
        if (s.substr(0, i) == s.substr(n - i))
        {
            cout << "YES" << endl
                 << s.substr(0, i);
            return;
        }
    }
    cout << "NO";
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