// // #pragma GCC optimize(2)
// #include <bits/stdc++.h>
// using namespace std;
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
// typedef map<int, int> mii;
// typedef map<char, int> mci;
// #define endl '\n'
// #define all(v) v.begin(), v.end()

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

// void solve()
// {
//     int n;
//     cin >> n;

//     vi v;
//     bool found = 0;
//     int num;
//     for (int i = 0; i < n; i++)
//     {
//         cin >> num;
//         if (v.empty() and num == 0)
//         {
//             continue;
//         }
//         v.push_back(num);
//     }
//     if (v.empty())
//     {
//         cout << 0 << endl;
//         return;
//     }
//     auto it = find(all(v), 0);
//     for (auto i = it; i != v.end(); i++)
//     {
//         if (*i != 0)
//         {
//             cout << 2 << endl;
//             return;
//         }
//     }
//     cout << 1 << endl;
// }

// signed main()
// {
//     ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
//     int TT = 1;
//     cin >> TT;
//     while (TT--)
//     {
//         solve();
//     }
// }

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

    vi v(n);
    cin >> v;
    if (count(all(v), 0ll) == n)
    {
        cout << 0 << endl;
        return;
    }
    int l = 0, r = n - 1;

    while (!v[l])
    {
        l++;
    }
    while (!v[r])
    {
        r--;
    }

    for (int i = l; i <= r; i++)
    {
        if (!v[i])
        {
            cout << 2 << endl;
            return;
        }
    }
    cout << 1 << endl;
    return;
}

signed main()
{
    ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
    int TT = 1;
    cin >> TT;
    while (TT--)
    {
        solve();
    }
}