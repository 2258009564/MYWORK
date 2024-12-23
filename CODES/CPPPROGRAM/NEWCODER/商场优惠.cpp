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

double computePay(int n, double a[], double sv)
{
    double result = 0;
    sort(a, a + n);
    for (int i = 0; i < n; i++)
    {
        result += a[i];
    }
    if (n > 4 and result >= sv)
    {
        result -= a[0];
    }
    return result;
}

signed main()
{
    ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
    int n;
    double sv;
    cin >> n >> sv;
    double a[n];
    for (auto &&i : a)
    {
        cin >> i;
    }
    cout << fixed << setprecision(2) << computePay(n, a, sv);
}