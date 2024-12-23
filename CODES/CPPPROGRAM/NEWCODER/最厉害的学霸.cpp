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

struct 最厉害的学霸
{
    string s;
    int a, b, c, i;
};

signed main()
{
    ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
    int n;
    cin >> n;
    vector<最厉害的学霸> v(n);
    int index = 1;
    for (auto &&i : v)
    {
        cin >> i.s >> i.a >> i.b >> i.c;
        i.i = index++;
    }
    sort(all(v), [](最厉害的学霸 j, 最厉害的学霸 k)
         {
        if(j.a+j.b+j.c != k.a+k.b+k.c)
        {
            return j.a + j.b + j.c > k.a + k.b + k.c;
        }else{
            if(j.a != k.a)
            {
                return j.a > k.a;
            }else{
                return j.i < k.i;
            }
        } });

    cout << v[0].s << ' ' << v[0].a << ' ' << v[0].b << ' ' << v[0].c << endl;
}