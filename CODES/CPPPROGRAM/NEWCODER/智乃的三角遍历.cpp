//#pragma GCC optimize(2)
//#pragma GCC optimize("Ofast")
//#pragma GCC optimize("inline", "fast-math", "unroll-loops", "no-stack-protector")
//#pragma GCC diagnostic error "-fwhole-program"
//#pragma GCC diagnostic error "-fcse-skip-blocks"
//#pragma GCC diagnostic error "-funsafe-loop-optimizations"
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
    cout << "Yes" << endl;
    if (n == 1)
    {
        cout << "1 2 3 1";
    }
    else if(n == 2)
    {
        cout << "1 2 3 5 2 4 5 6 3 1";
    }
    else if (n == 3)
    {
        cout << "1 2 3 5 2 4 5 6 9 5 8 4 7 8 9 10 6 3 1";
    }
    else if (n == 4)
    {
        cout << "1 2 3 5 2 4 5 6 9 5 8 4 7 8 9 10 14 9 13 8 12 13 14 15 10 6 3 1";
    }
    else if (n == 5)
    {
        cout << "1 2 3 5 2 4 5 6 9 5 8 4 7 8 9 10 14 9 13 8 12 13 14 15 18 14 17 13 16 17 18 19 15 10 6 3 1";
    }
    else if (n == 6)
    {
        cout << "1 2 3 5 2 4 5 6 9 5 8 4 7 8 9 10 14 9 13 8 12 13 14 15 18 14 17 13 16 17 18 19 23 18 22 17 21 22 23 24 19 15 10 6 3 1";
    }
    else if (n == 7)
    {
        cout << "1 2 3 5 2 4 5 6 9 5 8 4 7 8 9 10 14 9 13 8 12 13 14 15 18 14 17 13 16 17 18 19 23 18 22 17 21 22 23 24 29 23 28 22 27 28 29 30 24 19 15 10 6 3 1";
    }
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