// #pragma GCC optimize(2)
#include <bits/stdc++.h>
using namespace std;
#define int long long
typedef pair<int, int> pii;
typedef pair<double, double> pdd;
typedef vector<int> vi;
typedef vector<double> vd;
typedef vector<string> vs;
typedef vector<vi> vvi;
typedef vector<vvi> vvvi;
typedef vector<pii> vpii;
typedef vector<vpii> vvpii;
typedef vector<pdd> vpdd;
typedef vector<vd> vvd;
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

int N = 6;

struct chaxun
{
    string id, name;
    vi v1 = vi(N);
};

signed main()
{
    ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
    int n;
    cin >> n;
    vector<chaxun> v(n);
    for (auto &&i : v)
    {
        cin >> i.id >> i.name;
        for (auto &&j : i.v1)
        {
            cin >> j;
        }
    }
    string s;
    cin >> s;
    for (auto &&i : v)
    {
        if (i.id == s)
        {
            cout << i.name << ' ';
            int total = 0;
            for (auto &&j : i.v1)
            {
                total += j;
            }
            cout << total << ' ' << fixed << setprecision(2) << total * 1.0 / 6;
        }
    }
}
