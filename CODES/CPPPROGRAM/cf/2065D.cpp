// #pragma GCC optimize(2)
#include <bits/stdc++.h>
using namespace std;
#define int long long
#define endl '\n'

const int INF = 1e9;     // 无穷大
const int INFLL = 1e18;  // 长整型无穷大
const int MOD = 1e9 + 7; // 模数
// -9.2e18 ~ 9.2e18

void solve()
{
    int n, m;
    cin >> n >> m;
    vector v(n, vector<int>(m));
    for (auto &&vec : v)
    {
        for (auto &&i : vec)
        {
            cin >> i;
        }
    }
    ranges::sort(v, [](auto &v1, auto &v2)
                 { return accumulate(v1.begin(), v1.end(), 0ll) > accumulate(v2.begin(), v2.end(), 0ll); });

    vector<int> ans;
    for (auto &&vec : v)
    {
        for (auto &&i : vec)
        {
            ans.emplace_back(i);
        }
    }
    vector<int> ans1(ans.size());
    partial_sum(ans.begin(), ans.end(), ans1.begin());
    cout << accumulate(ans1.begin(), ans1.end(), 0ll);
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