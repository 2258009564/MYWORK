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
    string s;
    cin >> s;

    mii mp;
    stringstream ss(s);
    string s1;

    while (getline(ss, s1, ','))
    {
        if (!s1.empty())
        {
            mp[stoll(s1)]++;
        }
    }

    vvi result;
    vi path;

    int past = -1, cur;
    for (auto &&[k, v] : mp)
    {
        cur = k;
        if (past != -1 and cur - past != 1 and !path.empty())
        {
            result.push_back(path);
            path.clear();
        }
        path.push_back(cur);
        past = cur;
    }
    if (past != -1 and cur - past != 1 and !path.empty())
    {
        result.push_back(path);
    }

    for (int i = 0; i < result.size(); i++)
    {
        if (result[i].size() == 1)
        {
            cout << result[i].back();
        }
        else
        {
            cout << result[i].front() << '-' << result[i].back();
        }
        cout << ",\n"[i == result.size() - 1];
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