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
    int n, k;
    cin >> n >> k;
    set<int> st;
    vector<int> a(n), b(n);
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
        st.insert(a[i]);
    }
    for (int i = 0; i < n; i++)
    {
        cin >> b[i];
        st.insert(b[i]);
    }
    int res = 0;
    for (auto &&price : st)
    {
        int ans = 0;
        int fumian = 0;
        for (int i = 0; i < n; i++)
        {
            if (a[i] >= price)
            {
                ans += price;
            }
            else if (b[i] >= price)
            {
                ans += price;
                fumian++;
                if (fumian > k)
                {
                    break;
                }
            }
            else
            {
                continue;
            }
        }
        if (fumian <= k)
        {
            res = max(res, ans);
        }
    }
    cout << res;
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