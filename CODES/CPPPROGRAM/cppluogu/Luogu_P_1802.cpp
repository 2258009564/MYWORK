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

struct data1
{
    int lose, win, use;
};

signed main()
{
    BUFF;
    int n, x;
    cin >> n >> x;

    vector<data1> v(n);
    for (auto &&i : v)
    {
        cin >> i.lose >> i.win >> i.use;
    }

    vvi dp(n, vi(x + 1, 0)); // 任选前i个元素 可用j个药物 的最大经验值

    for (int i = 0; i <= x; i++)
    {
        dp[0][i] = (i >= v[0].use ? v[0].win : v[0].lose);
    }

    for (int i = 1; i < n; i++)
    {
        for (int j = 0; j <= x; j++)
        {
            dp[i][j] = dp[i - 1][j] + v[i].lose;
            if (j >= v[i].use)
            {
                dp[i][j] = max(dp[i][j], dp[i - 1][j - v[i].use] + v[i].win);
            }
        }
    }
    cout << dp[n - 1][x] * 5;
}