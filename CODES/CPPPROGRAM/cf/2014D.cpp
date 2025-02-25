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
    int n, d, k;
    cin >> n >> d >> k;

    vector<int> beg(n + 1, 0), en = beg;
    for (int i = 0; i < k; i++)
    {
        int l, r;
        cin >> l >> r;
        beg[l]++, en[r]++;
    }

    for (int i = 1; i <= n; i++)
    {
        beg[i] += beg[i - 1];
        en[i] += en[i - 1];
    }
    int maxn = -1, minn = INT_MAX, maxnum = -1, minnum = INT_MAX;
    for (int i = d; i <= n; i++)
    {
        int cur = beg[i] - en[i - d];
        if (cur < minnum)
        {
            minnum = cur;
            minn = i - d;
        }
        if (cur > maxnum)
        {
            maxnum = cur;
            maxn = i - d;
        }
    }
    cout << maxn + 1 << ' ' << minn + 1 << endl;
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