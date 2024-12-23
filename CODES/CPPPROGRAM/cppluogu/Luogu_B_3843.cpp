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

bool longer_than_6_and_shorter_than_12(string str)
{
    return (str.size() >= 6 and str.size() <= 12);
}

bool three(string s)
{
    int A = 0, a = 0, num = 0;
    bool found = 0;
    for (auto &&i : s)
    {
        if (isupper(i))
        {
            A = 1;
        }
        else if (islower(i))
        {
            a = 1;
        }
        else if (isdigit(i))
        {
            num = 1;
        }
        else if (i == '!' or i == '@' or i == '#' or i == '$')
        {
            found = 1;
        }
        else
        {
            return 0;
        }
    }
    return ((A + a + num > 1) and found);
}

bool judge(string s)
{
    return three(s) and longer_than_6_and_shorter_than_12(s);
}

signed main()
{
    BUFF;
    vs v;
    char c;
    string s;
    while (cin >> c)
    {
        if (c == ',')
        {
            v.push_back(s);
            s.clear();
        }
        else
        {
            s += c;
        }
    }
    for (auto &&i : v)
    {
        if (judge(i))
        {
            cout << i << endl;
        }
    }
}