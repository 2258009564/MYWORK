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

bool isPrime(int n)
{
    if (n < 2)
    {
        return 0;
    }
    for (int i = 2; i <= n / i; i++)
    {
        if (n % i == 0)
        {
            return 0;
        }
    }
    return 1;
}

signed main()
{
    ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
    int t;
    cin >> t;
    string s = to_string(t);
    string s1;
    for (int i = s.size() - 2; i >= 0; i--)
    {
        s1 += s[i];
    }
    s += s1;
    int n = stoll(s);
    if (isPrime(n))
    {
        cout << "prime";
        return 0;
    }
    cout << "noprime";
}