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

vi father, siz;
stack<int> stk;

void init(int n)
{
    siz.resize(n, 1);
    father.resize(n);
    iota(father.begin(), father.end(), 0);
}

int ffind(int n)
{
    while (n != father[n])
    {
        stk.push(n);
        n = father[n];
    }

    while (!stk.empty())
    {
        father[stk.top()] = n;
        stk.pop();
    }
    return n;
}

void funion(int i, int j)
{
    int fai = ffind(i), faj = ffind(j);
    if (fai - faj)
    {
        // 需要合并
        if (siz[fai] > siz[faj])
        {
            swap(fai, faj);
        }

        father[fai] = faj;
        siz[faj] += siz[fai];
    }
}

bool issame(int i, int j)
{
    return ffind(i) == ffind(j);
}

void solve()
{
    int n, m;
    cin >> n >> m;
    init(n);

    int z, x, y;
    while (m--)
    {
        cin >> z >> x >> y;
        if (z == 1)
        {
            funion(x, y);
        }
        else
        {
            cout << (issame(x, y) ? "Y" : "N") << endl;
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