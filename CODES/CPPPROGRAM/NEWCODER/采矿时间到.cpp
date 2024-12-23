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
    int n, h;
    cin >> n >> h;
    vs v(5);
    cin >> v;
    int total = 0;
    string s1 = v[0], s2 = v[1], s4 = v[3], s5 = v[4];
    for (int i = 0; i < n; i++)
    {

        if (s2[i] == '*' and h)
        {
            total++, h--;
            if (!h)
            {
                break;
            }
            if (s1[i] == '*' and h)
            {
                total++, h--;
                if (!h)
                {
                    break;
                }
            }
        }

        if (s4[i] == '*' and h)
        {
            total++, h--;
            if (!h)
            {
                break;
            }
            if (s5[i] == '*' and h)
            {
                total++, h--;
                if (!h)
                {
                    break;
                }
            }
        }
    }

    for (int i = 0; i < n; i++)
    {
        if (s1[i] == '*' and h >= 2)
        {
            total++, h -= 2;
            if (h < 2)
            {
                break;
            }
        }
        if (s5[i] == '*' and h >= 2)
        {
            total++, h -= 2;
            if (h < 2)
            {
                break;
            }
        }
    }

    cout << total;
}