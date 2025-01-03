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

    vvi result;
    vi v = {5, 2, 1};
    int count = 0;
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j * 2 + i <= n; j++)
        {
            for (int k = 1; k * 5 + j * 2 + i <= n; k++)
            {
                if (k * 5 + j * 2 + i == n)
                {
                    // cout << "fen5:" << k << ",fen2:" << j << ",fen1:" << i << ",total:" << i + j + k << endl;
                    // count++;
                    result.push_back({k, j, i});
                }
            }
        }
    }
    // cout << "count=" << count;

    sort(all(result), [](vi a, vi b)
         {
        if (a[0]!= b[0])
        {
            return a[0] > b[0];
        }
        if (a[1] != b[1])
        {
            return a[1] > b[1];
        }
        return a[2] > b[2]; });

    for (auto &&v1 : result)
    {
        cout << "fen5:" << v1[0] << ",fen2:" << v1[1] << ",fen1:" << v1[2] << ",total:" << v1[0] + v1[1] + v1[2] << endl;
    }

    cout << "count=" << result.size();
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