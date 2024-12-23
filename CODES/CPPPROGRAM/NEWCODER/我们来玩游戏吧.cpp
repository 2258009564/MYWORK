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
    int n, m;
    cin >> n >> m;
    vi v(n + 1);
    for (int i = 1; i <= n; i++)
    {
        cin >> v[i];
    }
    vi diff(n + 2);
    for (int i = 1; i <= n; i++)
    {
        diff[i] = v[i] - v[i - 1];
    }
    while (m--)
    {
        int num;
        cin >> num;
        if (num == 1)
        {
            int x, y, k;
            cin >> x >> y >> k;
            diff[x] += k;
            diff[y + 1] -= k;
        }
        else
        {
            int x, y;
            cin >> x >> y;
            // 计算区间 [x, y] 的和
            int result = 0;
            int current = 0;
            for (int i = 1; i <= y; i++)
            {
                current += diff[i]; // 更新当前位置的值
                if (i >= x)         // 当 i 在区间 [x, y] 时累加结果
                {
                    result += current;
                }
            }

            cout << result << endl;
        }
    }
}