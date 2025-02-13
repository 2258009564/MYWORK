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

    vector<int> a(n), b(m);
    for (auto &&i : a)
    {
        cin >> i;
    }
    for (auto &&i : b)
    {
        cin >> i;
    }

    if (n == 1 or ranges::count(a, a[0]) == n)
    {
        cout << "YES";
        return;
    }

    a[0] = min(a[0], b[0] - a[0]);
    a[n - 1] = max(a[n - 1], b[0] - a[n - 1]);

    for (int i = 1; i + 1 < n; i++)
    {
        if (a[i] >= a[i - 1]) // 满足条件
        {
            if (b[0] - a[i] >= a[i - 1]) // 可以换
            {
                a[i] = min(a[i], b[0] - a[i]); // 换最小值
            }
        }
        else // 不满足条件
        {
            if (b[0] - a[i] >= a[i - 1]) // 可以换
            {
                a[i] = b[0] - a[i]; // 换最小值
            }
            else
            {
                cout << "NO";
                return;
            }
        }
    }
    for (int i = 0; i + 1 < n; i++)
    {
        if (a[i + 1] - a[i] < 0)
        {
            cout << "NO";
            return;
        }
    }
    cout << "YES";
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