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
    int n;
    cin >> n;
    vector<int> v(n + 1, 0);
    int maxnum = -1;
    for (int i = 1; i <= n; i++)
    {
        cin >> v[i];
    }
    int 最大差距 = 0;
    pair<int, int> pr = {1, 1};
    for (int i = 1; i + 1 <= n; i++)
    {
        int bigger = 0, lowwer = 0;
        for (int j = i + 1; j <= n; j++)
        {
            if (v[i] > v[j])
            {
                lowwer++;
            }
            if (v[i] < v[j])
            {
                bigger++;
            }
            if (lowwer - bigger > 最大差距)
            {
                最大差距 = lowwer - bigger;
                pr = {i, j};
            }
        }
    }
    cout << pr.first << ' ' << pr.second;
}

signed main()
{
    cin.tie(0)->ios::sync_with_stdio(0);
    cout << setiosflags(ios::fixed) << setprecision(2);
    int TT = 1;
    cin >> TT;
    while (TT--)
    {
        solve();
        cout << endl;
    }
}