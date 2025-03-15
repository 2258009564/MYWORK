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
    int n, r;
    cin >> n >> r;
    vector<int> v(n, 0), path;
    iota(all(v), 1ll);

    function<void(int)> dfs = [&](int startindex)
    {
        if (startindex == n or path.size() == r) // 如果下标到达n 活着path合格了
        {
            if (path.size() == r) // 判断path是否合格
            {
                // 输出 path
            }
            return;
        }

        for (int i = startindex; i < n; i++) // 对于每一个数
        {
            path.push_back(v[i]); // 选择
            dfs(i + 1);
            path.pop_back(); // 不选
            dfs(i + 1);
        }
    };
    dfs(0);
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