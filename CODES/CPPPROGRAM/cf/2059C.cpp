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
    int n;
    cin >> n;
    vector<int> v(n), rest;
    for (int i = 0; i < n; i++) // 做 n 次
    {
        for (int j = 0; j < n; j++)
        {
            cin >> v[j];
        }

        int tot = 0;

        for (int j = v.size() - 1; j >= 0; j--)
        {
            if (v[j] == 1)
            {
                tot++;
            }
            else
            {
                break;
            }
        }
        rest.emplace_back(tot);
    }
    ranges::sort(rest);

    rest[0] = 0;

    for (int i = 1; i < rest.size(); i++)
    {
        rest[i] = min(rest[i], rest[i - 1] + 1);
    }
    cout << ranges::max(rest) + 1;
}

signed main()
{
    cin.tie(nullptr)->sync_with_stdio(false);
    int TT = 1;
    cin >> TT;
    while (TT--)
    {
        solve();
        cout << endl;
    }
}
