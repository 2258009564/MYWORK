// #pragma GCC optimize(2)
#include <bits/stdc++.h>
using namespace std;
#define BUFF ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
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
typedef vector<bool> vb;
typedef vector<vb> vvb;
typedef vector<vvb> vvvb;
typedef map<int, int> mii;
typedef map<char, int> mci;
#define endl '\n'
#define ts    \
    int T;    \
    cin >> T; \
    while (T--)
#define all(v) v.begin(), v.end()
#define sall(x) sort(all(x))
#define re(v) reverse(all(v))
#define pb push_back
#define qb pop_back
#define pf push_front
#define qf pop_front

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

int N = 1e9 + 10;

vi f(N);

void solve()
{
    f[0] = 0, f[1] = 1;
    for (int i = 2; i < N; i++)
    {
        f[i] = f[i / 2] + f[i % 2];
    }
}

signed main()
{
    BUFF;
    solve();

    mii mp;
    for (int i = 0; i < N; i++)
    {
        mp[i] = -1;
    }
    /*
    [k, v]
    k = 每一个数字
    v = 该数字第一次出现的索引
    */
    for (int i = 0; i < N; i++)
    {
        int k = f[i];
        if (mp[k] == -1)
        {
            mp[k] = i;
        }
    }
    cout << f[0] << ' ' << mp[f[0]] << endl
         << f[1] << ' ' << mp[f[1]];
}