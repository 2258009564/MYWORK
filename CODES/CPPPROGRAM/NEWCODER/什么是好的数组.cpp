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
    int n;
    cin >> n;
    vector<int> a(n);
    unordered_set<int> a_set;  
    for (auto &x : a)
    {
        cin >> x;
        a_set.insert(x);
    }

    int ai = *min_element(a.begin(), a.end());

    vector<int> S;
    for (auto x : a)
    {
        if (x % ai != 0)
        {
            S.push_back(x);
        }
    }

    if (S.empty())
    {
        cout << "Yes\n";
        return;
    }

    int g = S[0];
    for (int i = 1; i < S.size(); ++i)
    {
        g = gcd(g, S[i]);
        if (g == 1)
            break;  
    }

    if (a_set.find(g) != a_set.end())
    {
        cout << "Yes\n";
    }
    else
    {
        cout << "No\n";
    }
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