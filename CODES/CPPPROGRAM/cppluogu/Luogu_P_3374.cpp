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
    int n, m;
    cin >> n >> m;
    vector<int> v(n + 1, 0), c(n + 1, 0);
    // tv
    auto lowbit = [&](int i) -> int
    {
        return i & -i;
    };
    auto add = [&](int i, int val)
    {
        while (i <= n)
        {
            c[i] += val;
            i += lowbit(i);
        }
    };
    auto sum = [&](int i) -> int
    {
        int ans = 0;
        while (i)
        {
            ans += c[i];
            i -= lowbit(i);
        }
        return ans;
    };
    // tv end
    for (int i = 1; i <= n; i++)
    {
        cin >> v[i];
        add(i, v[i]);
    }

    int num, num1, num2;
    while (cin >> num >> num1 >> num2)
    {
        if (num == 1)
        {
            add(num1, num2);
        }
        else
        {
            cout << sum(num2) - sum(num1 - 1) << endl;
        }
    }
}

signed main()
{
    cin.tie(nullptr)->ios::sync_with_stdio(false);
    cout << setiosflags(ios::fixed) << setprecision(2);
    int TT = 1;
    // cin >> TT;
    while (TT--)
    {
        solve();
        cout << endl;
    }
}