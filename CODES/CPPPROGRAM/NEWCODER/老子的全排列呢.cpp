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
    vector<bool> visited(9, 0);
    vector<vector<int>> result;
    vector<int> path;
    function<void(void)> dfs = [&]()
    {
        if (path.size() == 8)
        {
            result.push_back(path);
            return;
        }

        for (int i = 1; i <= 8; i++)
        {
            if (!visited[i])
            {
                visited[i] = 1;
                path.push_back(i);
                dfs();
                path.pop_back();
                visited[i] = 0;
            }
        }
    };
    dfs();
    for (auto &&v : result)
    {
        for (auto &&i : v)
        {
            cout << i << ' ';
        }
        cout << endl;
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