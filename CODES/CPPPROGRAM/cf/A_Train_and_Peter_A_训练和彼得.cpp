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

bool Find(const string &str, const string &a, const string &b)
{
    auto A = str.find(a);
    if (A == string::npos)
    {
        return false;
    }
    auto B = str.find(b, A + a.size());
    return (B != string::npos);
};

void solve()
{
    string s, s1, s2;
    cin >> s >> s1 >> s2;

    bool forwardok = Find(s, s1, s2);
    string rs = s;
    reverse(all(rs));
    bool backwardok = Find(rs, s1, s2);

    if (backwardok and forwardok)
    {
        cout << "both";
    }
    else if (backwardok)
    {
        cout << "backward";
    }
    else if (forwardok)
    {
        cout << "forward";
    }
    else
    {
        cout << "fantasy";
    }
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