#pragma GCC optimize("O3")
#include <bits/stdc++.h>
using namespace std;
#define BUFF ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
#define int unsigned int
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
int seed;
int rnd()
{
    unsigned ret = seed;
    seed ^= seed << 13;
    seed ^= seed >> 17;
    seed ^= seed << 5;
    return ret;
}

signed main()
{
    BUFF;
    int n, m, k;
    cin >> n >> m >> k >> seed;

    int garden[n + 1][m + 1] = {};

    for (int t = 1; t <= k; t++)
    {
        int op = (rnd() % 2) + 1;

        if (op == 1)
        {
            int i = (rnd() % m) + 1;
            int x = (rnd() % (n * m)) + 1;

            for (int j = 1; j <= n; j++)
            {
                if (garden[j][i] == 0)
                {
                    garden[j][i] = x;
                }
            }
        }
        else if (op == 2)
        {
            int a = (rnd() % n) + 1;
            int b = (rnd() % m) + 1;

            if (garden[a][b] != 0)
            {
                garden[a][b] = 0;
            }
        }
    }

    int result = 0;
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
        {
            int idx = (i - 1) * m + j;
            result ^= garden[i][j] * idx;
        }
    }

    cout << result << endl;
}
