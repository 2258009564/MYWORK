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
    int n;
    cin >> n;
    vector<int> lf(n);
    char c;
    int index = 0;
    for (int i = 0; i < n; i++)
    {
        cin >> c;
        if (c == '-')
        {
            cout << i + 1 << ' ';
        }
        if (c == '(')
        {
            lf[index++] = i + 1;
        }
        if (c == ')')
        {
            cout << i + 1 << ' ' << lf[--index] << ' ';
        }
    }
}

signed main()
{
    cin.tie(0)->ios::sync_with_stdio(0);
    cout << setiosflags(ios::fixed) << setprecision(2);
    int TT = 1;
    // cin >> TT;
    while (TT--)
    {
        solve();
        cout << endl;
    }
}