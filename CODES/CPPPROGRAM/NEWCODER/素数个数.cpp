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
vector<bool> isprime(1002, 1);
void isPrime(int n, vector<bool> &isprime)
{

    for (int i = 2; i <= n / i; i++)
    {
        if (isprime[i])
        {
            for (int j = i * i; j <= n; j += i)
            {
                isprime[j] = 0;
            }
        }
    }
}

signed main()
{
    ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
    isPrime(1002, isprime);
    T
    {
        int n;
        cin >> n;
        int total = 0;
        for (int i = 2; i <= n; i++)
        {
            total += isprime[i];
        }
        cout << total << endl;
    }
}