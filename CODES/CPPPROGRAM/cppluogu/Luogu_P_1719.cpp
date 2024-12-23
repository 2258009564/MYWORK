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
    int n;
    cin >> n;
    vvi vec(n + 1, vi(n + 1));
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            cin >> vec[i][j];
        }
    }
    vvi pf(n + 1, vi(n + 1));
    pf[1][1] = vec[1][1];
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            pf[i][j] = vec[i][j] + pf[i - 1][j] + pf[i][j - 1] - pf[i - 1][j - 1];
        }
    }
    int maxnum = INT_MIN;
    for (int x1 = 1; x1 <= n; x1++)
    {
        for (int x2 = x1; x2 <= n; x2++)
        {
            for (int y1 = 1; y1 <= n; y1++)
            {
                for (int y2 = y1; y2 <= n; y2++)
                {
                    int k = pf[x2][y2] - pf[x1 - 1][y2] - pf[x2][y1 - 1] + pf[x1 - 1][y1 - 1];
                    maxnum = max(maxnum, k);
                }
            }
        }
    }
    cout << maxnum;
}