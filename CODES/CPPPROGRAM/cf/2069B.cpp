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
    cin >> n >> m;
    vector<vector<int>> v(n + 2, vector<int>(m + 2, 0));
    set<int> st;
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
        {
            cin >> v[i][j];
            st.insert(v[i][j]);
        }
    }
    if (n == 1 and m == 1)
    {
        cout << 0;
        return;
    }

    int maxColorVal = n * m;
    vector<int> cost(maxColorVal + 1, 1);

    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
        {
            int cur = v[i][j];
            if (j + 1 <= m && v[i][j + 1] == cur)
            {
                cost[cur] = 2;
            }
            if (i + 1 <= n && v[i + 1][j] == cur)
            {
                cost[cur] = 2;
            }
        }
    }

    int S = 0, maxi = 0;
    for (auto &&c : st)
    {
        S += cost[c];
        maxi = max(maxi, cost[c]);
    }
    cout << S - maxi;
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