// #pragma GCC optimize(2)
#include <bits/stdc++.h>
using namespace std;
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
typedef map<int, int> mii;
typedef map<char, int> mci;
#define endl '\n'
#define T     \
    int T;    \
    cin >> T; \
    while (T--)
#define all(v) v.begin(), v.end()
#define sall(x) sort(all(x))
#define pb push_back
#define qb pop_back
#define pf push_front
#define qf pop_front

struct chengji
{
    string id, name;
    int a, b, c, d, e, f;
};

signed main()
{
    ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
    int n;
    cin >> n;
    vector<chengji> v(n);
    for (auto &&i : v)
    {
        cin >> i.id >> i.name >> i.a >> i.b >> i.c >> i.d >> i.e >> i.f;
    }
    string s;
    cin >> s;
    for (auto &&i : v)
    {
        if (i.id == s)
        {
            cout << i.name << ' ' << i.a + i.b + i.c + i.d + i.e + i.f << ' ' << fixed << setprecision(2) << 1.0 * (i.a + i.b + i.c + i.d + i.e + i.f) / 6;
        }
    }
}