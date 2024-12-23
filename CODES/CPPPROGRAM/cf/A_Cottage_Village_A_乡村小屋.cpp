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

void solve()
{
    int n, t;
    cin >> n >> t;
    vpdd x(n);
    for (int i = 0; i < n; i++)
    {
        cin >> x[i].first >> x[i].second;
        x[i].first -= x[i].second / 2;
    }
    sort(all(x), [](pdd a, pdd b)
         { return a.first + a.second <= b.first; });

    int ans = 2;
    for (int i = 1; i < n; i++)
    {
        if (x[i].first - x[i - 1].first - x[i - 1].second > t)
        {
            ans += 2;
        }
        else if (x[i].first - x[i - 1].first - x[i - 1].second == t)
        {
            ans++;
        }
    }
    cout << ans;
}

signed main()
{
    ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
    int TT = 1;
    // cin >> TT;
    while (TT--)
    {
        solve();
    }
}