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
    vector v(3, vector<char>(3));
    map<pair<int, int>, int> mp, mp1;
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            cin >> v[i][j];
            if (v[i][j] == 'X')
            {
                mp[{i, j}] = 1;
            }
        }
    }
    if (mp.size() == 0)
    {
        cout << "Yes";
        return;
    }
    for (int i = 0; i < 3; i++)
    {
        if (v[i][0] != 'O' && v[i][1] != 'O' && v[i][2] != 'O' and mp[{i, 0}] + mp[{i, 1}] + mp[{i, 2}] >= 1)
        {
            cout << "Yes";
            return;
        }
        if (v[0][i] != 'O' && v[1][i] != 'O' && v[2][i] != 'O' and mp[{0, i}] + mp[{1, i}] + mp[{2, i}] >= 1)
        {
            cout << "Yes";
            return;
        }
    }
    if ((v[0][0] != 'O' && v[1][1] != 'O' && v[2][2] != 'O') and (mp[{0, 0}] + mp[{1, 1}] + mp[{2, 2}] >= 1))
    {
        cout << "Yes";
        return;
    }

    if ((v[0][2] != 'O' && v[1][1] != 'O' && v[2][0] != 'O') and (mp[{0, 2}] + mp[{1, 1}] + mp[{2, 0}] >= 1))
    {
        cout << "Yes";
        return;
    }

    cout << "No";
}

signed main()
{
    cin.tie(nullptr)->sync_with_stdio(false);
    cout << setiosflags(ios::fixed) << setprecision(2);
    int TT = 1;
    cin >> TT;
    while (TT--)
    {
        solve();
        cout << endl;
    }
}