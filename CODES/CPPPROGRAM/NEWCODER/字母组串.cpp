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

int solve(int a, int b, int c, int n)
{
    int result = 0;
    if(!n)
    {
        return 1;
    }
    if(a)
    {
        result += solve(a - 1, b, c, n - 1);
    }if(b)
    {
        result += solve(a, b - 1, c, n - 1);
    }
    if(c)
    {
        result += solve(a, b, c - 1, n - 1);
    }
    return result;
}

signed main()
{
    ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
    int a, b, c, n;
    cin >> a >> b >> c >> n;
    cout << solve(a, b, c, n);
}