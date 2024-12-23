// // #pragma GCC optimize(2)
// #include <bits/stdc++.h>
// using namespace std;
// #define BUFF ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
// #define int long long
// typedef pair<int, int> pii;
// typedef pair<double, double> pdd;
// typedef vector<string> vs;
// typedef vector<vs> vvs;
// typedef vector<vvs> vvvs;
// typedef vector<int> vi;
// typedef vector<vi> vvi;
// typedef vector<vvi> vvvi;
// typedef vector<pii> vpii;
// typedef vector<vpii> vvpii;
// typedef vector<pdd> vpdd;
// typedef vector<double> vd;
// typedef vector<vd> vvd;
// typedef vector<char> vc;
// typedef vector<vc> vvc;
// typedef vector<vvc> vvvc;
// typedef vector<bool> vb;
// typedef vector<vb> vvb;
// typedef vector<vvb> vvvb;
// typedef map<int, int> mii;
// typedef map<char, int> mci;
// #define endl '\n'
// #define ts    \
//     int T;    \
//     cin >> T; \
//     while (T--)
// #define all(v) v.begin(), v.end()
// #define sall(x) sort(all(x))
// #define re(v) reverse(all(v))

// // 通用版本的 >> 重载，用于任意类型的 std::vector<T>
// template <typename T>
// istream &operator>>(istream &in, vector<T> &v)
// {
//     for (auto &x : v)
//     {
//         in >> x;
//     }
//     return in;
// }

// // 通用版本的 << 重载，用于任意类型的 std::vector<T>
// template <typename T>
// ostream &operator<<(ostream &out, const vector<T> &v)
// {
//     for (const auto &x : v)
//     {
//         out << x << ' ';
//     }
//     return out;
// }

// signed main()
// {
//     BUFF;
//     string s;
//     cin >> s;
//     int total = 0;
//     int cur_len = 1;
//     for (int i = 1; i < s.length(); i++)
//     {
//         if (s[i] != s[i - 1])
//         {
//             cur_len++;
//         }
//         else
//         {
//             total += (cur_len - 1) * cur_len / 2;
//             cur_len = 1;
//         }
//     }
//     total += (cur_len - 1) * cur_len / 2;
//     cout << total << endl;
// }

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
    string s;
    cin >> s;

    int sz = s.size();
    if (sz < 2)
    {
        cout << 0;
        return 0;
    }
    vi dp(sz, 0);

    int result = 0;

    for (int i = 1; i < sz; i++)
    {
        if (s[i] != s[i - 1])
        {
            dp[i] = 1 + dp[i - 1];
            result += dp[i];
        }
    }
    cout << result;
}