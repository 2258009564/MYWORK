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
    int n, m;
    cin >> m >> n;
    vector<int> v(m);
    for (int i = 0; i < m; i++)
    {
        cin >> v[i];
    }

    vector<int> d(n);
    for (int i = 0; i < n; i++)
    {
        cin >> d[i];
    }

    ranges::sort(v);
    ranges::sort(d);
    set<int> st;
    for (int i = 0; i < m; i++)
    {
        st.insert(v[i]);
    }
    int ans = 0;
    for (int i = 0; i < n; i++)
    {
        auto a = st.lower_bound(d[i]);
        auto b = (a != st.begin()) ? prev(a) : a;

        int diff = INFLL;
        int a1 = 0, b1 = 0;
        if (a != st.end())
        {
            diff = min(diff, abs(*a - d[i]));
            a1 = 1;
        }
        if (b != a)
        {
            diff = min(diff, abs(*b - d[i]));
            if (diff == abs(*b - d[i]))
            {
                b1 = 1;
            }
        }

        ans += diff;

    }
    cout << ans;
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