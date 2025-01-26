// #pragma GCC optimize(2)
#include <bits/stdc++.h>
using namespace std;
#define int long long
#define endl '\n'

// 通用版本的 >> 重载，用于任意类型的 std::vector<T>
template <typename T>
istream &operator>>(istream &in, vector<T> &v)
{
    for (auto &x : v)
    {
        in >> x;
    }
    return in;
}

// 通用版本的 << 重载，用于任意类型的 std::vector<T>
template <typename T>
ostream &operator<<(ostream &out, const vector<T> &v)
{
    for (const auto &x : v)
    {
        out << x << ' ';
    }
    return out;
}

const int INF = 1e9;     // 无穷大
const int INFLL = 1e18;  // 长整型无穷大
const int MOD = 1e9 + 7; // 模数

void solve()
{
    int n;
    cin >> n;

    vector<double> v(n);
    for (int i = 0; i < n; i++)
    {
        cin >> v[i];
    }
    ranges::sort(v);
    double mid;
    if (n & 1)
    {
        mid = v[n / 2];
    }
    else
    {
        mid = (v[n / 2] + v[n / 2 - 1]) / 2;
    }

    int ans = 0;
    for (int i = 0; i < n; i++)
    {
        ans += abs(v[i] - mid);
    }
    cout << ans;
}

signed main()
{
    cin.tie(nullptr)->sync_with_stdio(false);
    int TT = 1;
    // cin >> TT;
    while (TT--)
    {
        solve();
        cout << endl;
    }
}