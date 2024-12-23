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

bool isrun(int n)
{
    if ((n % 4 != 0 and n % 100 == 0) or (n % 400 == 0))
    {
        return 1;
    }
    return 0;
}

signed main()
{
    ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
    int n;
    cin >> n;
    cout << (isrun(n) ? "It is a leap year" : "It is not a leap year") << endl;
}