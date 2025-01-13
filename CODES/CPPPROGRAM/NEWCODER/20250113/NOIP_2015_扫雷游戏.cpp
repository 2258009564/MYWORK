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

vvi d = {{1, 1}, {1, 0}, {1, -1}, {0, 1}, {0, -1}, {-1, 1}, {-1, 0}, {-1, -1}};

void solve()
{
    int n, m;
    cin >> n >> m;
    vector v(n + 2, vc(m + 2, 0));

    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
        {
            cin >> v[i][j];
        }
    }

    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
        {
            if (v[i][j] != '*')
            {
                auto tot = 0;
                for (auto &&dxy : d)
                {
                    auto x = dxy[0], y = dxy[1];
                    if (v[i + x][j + y] == '*')
                    {
                        tot++;
                    }
                }
                v[i][j] = tot + '0';
            }
        }
    }

    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
        {
            cout << v[i][j];
            if (j == m)
            {
                cout << endl;
            }
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