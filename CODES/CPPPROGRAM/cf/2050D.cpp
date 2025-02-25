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
    if (count(s.begin(), s.end(), '1') + count(s.begin(), s.end(), '2') == s.size())
    {
        cout << s;
        return;
    }
    
    int n = s.size();
    while (1)
    {
        int tot = 0;
        for (int i = 0; i + 1 < n; i++)
        {
            if (s[i] < s[i + 1] - 1)
            {
                swap(s[i], s[i + 1]);
                s[i]--;
                tot++;
            }
        }
        if (tot == 0)
        {
            break;
        }
    }
    cout << s;
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