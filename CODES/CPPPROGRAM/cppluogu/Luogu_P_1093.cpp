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

signed main()
{
    BUFF;
    int n;
    cin >> n;
    vvi v(n, vi(5));
    int index = 1;
    for (auto &&i : v)
    {
        i[0] = index++;
        cin >> i[1] >> i[2] >> i[3];
        i[4] = i[1] + i[2] + i[3];
    }
    sort(all(v), [](vi v1, vi v2)
         {
        if (v1[4] != v2[4])
        {
            return v1[4] > v2[4];
        }
        else
        {
            if (v1[1] != v2[1])
            {
                return v1[1] > v2[1];
            }
            else
            {
                return v1[0] < v2[0];
            }
        } });

    if (n < 5)
    {
        for (auto &&i : v)
        {
            cout << i[0] << ' ' << i[4] << endl;
        }
    }
    else
    {
        for (int i = 0; i < 5; i++)
        {
            cout << v[i][0] << ' ' << v[i][4] << endl;
        }
    }
}