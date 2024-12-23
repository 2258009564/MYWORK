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

string transform(int n, int r)
{
    string result;
    string digits = "0123456789ABCDEF";
    while (n > 0)
    {
        result += digits[n % r];
        n /= r;
    }
    reverse(all(result));
    return result;
}

signed main()
{
    ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
    int n, r;
    cin >> n >> r;
    cout << transform(n, r);
}