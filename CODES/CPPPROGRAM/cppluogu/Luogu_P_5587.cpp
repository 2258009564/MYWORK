// #pragma GCC optimize(2)
#include <bits/stdc++.h>
using namespace std;
#define BUFF ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
#define int long long
typedef pair<int, int> pii;
typedef pair<double, double> pdd;
typedef vector<string> vs;
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
    string s;
    vs v;
    while (getline(cin, s))
    {
        v.pb(s);
    }
    int t = stoll(v.back());
    
    for (auto &&str : v)
    {
        if (str == v[v.size() - 1])
        {
            break;
        }
        string news;
        for (auto &&i : str)
        {
            if (i == '<' and !news.empty())
            {
                news.qb();
            }
            else
            {
                news.pb(i);
            }
        }
        str = news;
    }

    int mid = v.size() / 2;
    int total = 0;
    int slow = 0, fast = mid;
    while (fast != v.size())
    {
        string s_s = v[slow], s_f = v[fast];
        int minnum = min(s_s.size(), s_f.size());
        for (int i = 0; i < minnum; i++)
        {
            if (s_s == "EOF")
            {
                break;
            }
            if (s_s[i] == s_f[i])
            {
                total++;
            }
        }
        slow++, fast++;
    }
    cout << (int)(total * 60.0 / t + 0.5);
}