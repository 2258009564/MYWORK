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
    int n, m;
    cin >> n >> m;
    vector<vector<char>> v1(n, vector<char>(n)), v2(m, vector<char>(m));
    for (auto &&i : v1)
    {
        for (auto &&v : i)
        {
            cin >> v;
        }
    }
    for (auto &&i : v2)
    {
        for (auto &&v : i)
        {
            cin >> v;
        }
    }

    for (int i = 0; i + m <= n; i++)
    {
        for (int j = 0; j + m <= n; j++)
        {
            bool found = 1;
            for (int k = 0; k < m; k++)
            {
                for (int l = 0; l < m; l++)
                {
                    // cout << i << ' ' << j << ' ' << k << ' ' << l << ' ' << v1[i + k][j + l] << ' ' << v2[k][l] << endl;
                    if (v1[i + k][j + l] != v2[k][l])
                    {
                        found = 0;
                        break;
                    }
                }
                if (!found)
                {
                    break;
                }
            }
            if (found)
            {
                cout << i + 1 << ' ' << j + 1;
                return;
            }
        }
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