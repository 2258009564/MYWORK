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
    int l, n;
    cin >> l >> n;

    int ans = 0;
    vector<int> row(n), col(n);

    function<void(int)> dfs = [&](int pos) -> void
    {
        if (pos == n * n)
        {
            ans++;
            return;
        }

        int x = pos / n;
        int y = pos % n;

        for (int i = 0; i <= l; i++)
        {
            row[x] += i;
            col[y] += i;
            if (row[x] <= l && col[y] <= l)
            {
                if ((x == n - 1 && col[y] != l) or (y == n - 1 && row[x] != l))
                {
                }
                else
                {
                    dfs(pos + 1);
                }
            }
            row[x] -= i;
            col[y] -= i;
        }
    };

    dfs(0);

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