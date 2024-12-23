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
    int n, m, k;
    cin >> n >> m >> k;
    
    vi a(m);
    cin >> a;
    
    vector<bool> known(n + 1);
    for (int i = 0; i < k; i++) {
        int x;
        cin >> x;
        known[x] = true;
    }

    if (n - k > 1) {
        cout << string(m, '0') << endl;
        return;
    }

    if (n == k) {
        cout << string(m, '1') << endl;
        return;
    }

    int unknown = 0;
    for (int i = 1; i <= n; i++) {
        if (!known[i]) {
            unknown = i;
            break;
        }
    }

    for (int x : a) {
        cout << (x == unknown ? '1' : '0');
    }
    cout << endl;
}

signed main()
{
    ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
    int TT = 1;
    cin >> TT;
    while (TT--)
    {
        solve();
    }
}