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

// 快速幂取模运算
// @param a: 底数
// @param b: 指数
// @param mod: 模数
// @return: (a^b) % mod
int QuickPowMod(int a, int b, int mod)
{
    if (mod <= 0)
    {
        return -1; // 模数必须为正
    }
    if (b < 0)
    {
        return -1; // 指数必须非负
    }

    int result = 1;
    a %= mod;
    while (b)
    {
        if (b & 1)
        {
            result = (result * a) % mod;
        }
        a = (a * a) % mod;
        b >>= 1; // 使用位运算替代除法
    }
    return result;
}

const int INF = 1e9;     // 无穷大
const int INF_LL = 1e18; // 长整型无穷大
const int MOD = 1e9 + 7; // 模数

void solve()
{
    int n, l, r;
    cin >> n >> l >> r;

    string s;
    cin >> s;

    vi c0(n + 1, 0), c1 = c0, dp = c1;

    // c0:前i个元素中有几个0
    // c1:前i个元素中有几个1
    // dp:前i个元素有几对

    for (int i = 0; i < n; i++)
    {
        c0[i + 1] = c0[i] + (s[i] == '0');
        c1[i + 1] = c1[i] + (s[i] == '1');
    }

    for (int i = 1; i < n; i++)
    {
        for (int j = i + 1; j <= n; j++)
        {
            auto C0 = c0[j], C1 = c1[n + 1] - c1[j];
            
        }
    }
}

signed main()
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int TT = 1;
    // cin >> TT;
    while (TT--)
    {
        solve();
        cout << endl;
    }
}