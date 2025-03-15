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
    /*
    有N组物品和一个容量是V的背包。
    每组物品有若干个，同一组内的物品最多只能选一个。
    每件物品的体积是v,价值是w,其中i是组号，j是组内编号。
    求解将哪些物品装入背包，可使物品总体积不超过背包容量，且总价值最大。
    输出最大价值。
    */

    int n, m;
    cin >> n >> m;

    vector<int> dp(m + 1, 0);

    vector<vector<pair<int, int>>> v;
    for (int i = 0; i < n; i++)
    {
        int num;
        cin >> num;
        vector<pair<int, int>> vv(num);
        for (int j = 0; j < num; j++)
        {
            cin >> vv[j].first >> vv[j].second;
        }
        v.push_back(vv);
    }

    for (int i = 0; i < n; i++)
    {
        for (int j = )
    }
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