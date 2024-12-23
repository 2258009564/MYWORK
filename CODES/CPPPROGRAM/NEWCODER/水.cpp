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

signed main()
{
    BUFF;
    int n;
    cin >> n;
    int total = 0;
    vvi vec(n, vi(2));
    for (auto &&i : vec)
    {
        cin >> i;
    }
    map<pii, int> mp;
    for (auto &&i : vec)
    {
        if (i[0] > 0 and i[1] > 0)
        {
            mp[{1, 1}]++;
        }
        else if (i[0] < 0 and i[1] > 0)
        {
            mp[{-1, 1}]++;
        }
        else if (i[0] > 0 and i[1] < 0)
        {
            mp[{1, -1}]++;
        }
        else
        {
            mp[{-1, -1}]++;
        }
    }
    int a = min(mp[{1, 1}], mp[{-1, -1}]);
    total += 2 * a;
    mp[{1, 1}] -= a;
    mp[{-1, -1}] -= a;
    int b = min(mp[{-1, 1}], mp[{1, -1}]);
    total += 2 * b;
    mp[{-1, 1}] -= b;
    mp[{1, -1}] -= b;

    // 斜着的已经判断完了

    bool found = 0;
    int num = INT_MAX;
    for (auto &&[k, v] : mp)
    {
        if (v)
        {
            num = min(num, v);
        }
    }
    total += (num == INT_MAX ? 0 : num);
    cout << total;
}