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
    int n, num1, num2;
    cin >> n >> num1 >> num2;
    vector<int> v(n + 1, 0);
    for (int i = num1 + 1; i <= n; i++)
    {
        v[i] = !v[i - 1];
    }
    for (int i = num1 - 1; i >= 0; i--)
    {
        v[i] = !v[i + 1];
    }
    if (n % 2 == 1 or abs(num2 - num1) % 2 == 0)
    {
        v[num1] = 2;
    }
    cout << v[n] << ' ';
    for (int i = 1; i <= n - 1; i++)
    {
        cout << v[i] << ' ';
    }
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