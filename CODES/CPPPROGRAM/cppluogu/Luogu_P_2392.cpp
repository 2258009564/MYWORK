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

int result = 0;

void backtracking(vi &v, int half, int startindex, int sumnumber, int &total)
{
    if (sumnumber <= half)
    {
        total = max(total, sumnumber);
    }
    if (startindex == v.size())
    {
        return;
    }
    for (int i = startindex; i < v.size(); i++)
    {
        backtracking(v, half, i + 1, sumnumber + v[i], total);
    }
}

void solve(vi &v)
{
    int sum = accumulate(all(v), 0);
    int half = sum / 2;
    int total = 0;
    backtracking(v, half, 0, 0, total);
    result += sum - total;
}

signed main()
{
    BUFF;
    int a, b, c, d;
    cin >> a >> b >> c >> d;
    vi v1(a), v2(b), v3(c), v4(d);
    cin >> v1 >> v2 >> v3 >> v4;
    solve(v1);
    solve(v2);
    solve(v3);
    solve(v4);
    cout << result;
}