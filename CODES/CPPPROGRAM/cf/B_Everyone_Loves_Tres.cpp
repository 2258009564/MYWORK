// // #pragma GCC optimize(2)
// #include <bits/stdc++.h>
// using namespace std;
// #define BUFF ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
// #define int long long
// typedef pair<int, int> pii;
// typedef pair<double, double> pdd;
// typedef vector<string> vs;
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
// #define pb push_back
// #define qb pop_back
// #define pf push_front
// #define qf pop_front

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

// vvi result;
// vi path;
// int choice[] = {3, 6};
// void backtracking(int n)
// {
//     if (n == 0)
//     {
//         result.pb(path);
//         return;
//     }
//     // fa choice
//     //  son choice[0] / choice[1]

//     for (int i = 0; i <= 1; i++)
//     {
//         path.pb(choice[i]);
//         n -= 1;
//         backtracking(n);
//         n += 1;
//         path.qb();
//     }
// }

// signed main()
// {
//     BUFF;
//     ts
//     {
//         int n;
//         result.clear();
//         path.clear();
//         cin >> n;
//         bool found = 0;
//         backtracking(n);
//         vi ans;
//         for (auto &&v : result)
//         {
//             string s;
//             for (auto &&i : v)
//             {
//                 s += i + '0';
//             }
//             int num = stoll(s);
//             if (num % 33 == 0 and num % 66 == 0)
//             {
//                 ans.pb(num);
//                 found = 1;
//             }
//         }
//         if (found)
//         {
//             sall(ans);
//             cout << ans[0] << endl;
//         }
//         else
//         {
//             cout << -1 << endl;
//         }
//     }
// }

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
    ts
    {
        int n;
        cin >> n;
        if (n == 1 or n == 3)
        {
            cout << -1 << endl;
            continue;
        }
        if (n == 2)
        {
            cout << 66 << endl;
            continue;
        }
        if (n % 2 == 0)
        {
            for (int i = 0; i + 2 < n; i++)
            {
                cout << 3;
            }
            cout << 66 << endl;
        }
        else
        {
            for (int i = 0; i + 4 < n; i++)
            {
                cout << 3;
            }
            cout << 6366 << endl;
        }
    }
}