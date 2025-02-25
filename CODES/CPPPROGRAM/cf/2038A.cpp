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
    int n, k;
    cin >> n >> k;
    vector<int> a(n), b(n), c(n);
    for (auto &&i : a) // a 奖金
    {
        cin >> i;
    }
    for (auto &&i : b) // b 工作单位成本
    {
        cin >> i;
    }

    // si = ai − c * bi
    // ai − c * bi > 0
    // ai > c * bi

    // 每个工程师都会尝试让这个数字最大化
    // si = 0  ai / bi = c

    for (int i = n - 1; i >= 0; i--)
    {
        int w = min(k, a[i] / b[i]);
        k -= w;
        c[i] = w;
    }

    for (auto &&i : c)
    {
        cout << (k ? 0 : i) << ' ';
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