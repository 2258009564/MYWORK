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
    string s;
    cin >> s;
    vector v(n, vector<int>(m));
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cin >> v[i][j];
        }
    }
    int x = 0, y = 0;
    for (auto &&c : s)
    {
        if (c == 'D') // 往下走 计算一行的和 x确定 计算y
        {
            int temp = 0;
            for (int i = 0; i < m; i++)
            {
                temp += v[x][i];
            }
            v[x++][y] = -temp;
        }
        else
        {
            int temp = 0;
            for (int i = 0; i < n; i++)
            {
                temp += v[i][y];
            }
            v[x][y++] = -temp;
        }
    }

    int temp = 0;
    for (int i = 0; i < m; i++)
    {
        temp += v[n - 1][i];
    }
    v[n - 1][m - 1] = -temp;

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cout << v[i][j] << ' ';
        }
        cout << endl;
    }
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
        // cout << endl;
    }
}