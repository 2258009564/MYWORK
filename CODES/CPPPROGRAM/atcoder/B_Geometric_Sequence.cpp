// #pragma GCC optimize(2)
#include <bits/stdc++.h>
using namespace std;
#define int long long
typedef pair<int, int> pii;
typedef pair<double, double> pdd;
typedef vector<string> vs;
typedef vector<vs> vvs;
typedef vector<vvs> vvvs;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<vvi> vvvi;
typedef vector<pii> vpii;
typedef vector<vpii> vvpii;
typedef vector<pdd> vpdd;
typedef vector<double> vd;
typedef vector<vd> vvd;
typedef vector<char> vc;
typedef vector<vc> vvc;
typedef vector<vvc> vvvc;
typedef map<int, int> mii;
typedef map<char, int> mci;
#define endl '\n'
#define all(v) v.begin(), v.end()
#define sall(v, x) sort(all(v), x)

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
const int INF_LL = 1e18; // 长整型无穷大
const int MOD = 1e9 + 7; // 模数

void solve()
{
    int n;
    cin >> n;
    vector<double> v(n);
    for (auto &&i : v)
    {
        cin >> i;
        if (!i)
        {
            cout << "No";
            return;
        }
    }
    if (n == 2)
    {
        cout << "Yes";
        return;
    }
    double x = v[1] / v[0];
    for (int i = 1; i + 1 < n; i++)
    {
        if (v[i+ 1] * x != v[i + 1])
        {
            // cout << v[i] << ' ' << x << ' ' << v[i + 1] << endl;
            cout << "No";
            return;
        }
    }
    cout << "Yes";
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