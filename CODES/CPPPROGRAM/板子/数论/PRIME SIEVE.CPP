// #pragma GCC optimize(2)
#include <bits/stdc++.h>
using namespace std;
#define int long long
#define endl '\n'
#define all(x) (x).begin(), (x).end()

constexpr int MOD = 1e9 + 7;
// -9.2e18 ~ 9.2e18

const int N = 1e7;

vector<int> primes, isprime(N + 1, 1);
void pre()
{
    isprime[0] = isprime[1] = 0;
    for (int i = 2; i <= N; i++)
    {
        if (isprime[i])
        {
            for (int j = i * i; j <= N; j += i)
            {
                isprime[j] = 0;
            }
        }
    }

    for (int i = 2; i <= N; i++)
    {
        if (isprime[i])
        {
            primes.emplace_back(i);
        }
    }
}

void solve()
{
}

signed main()
{
    cin.tie(0)->ios::sync_with_stdio(0);
    cout << setiosflags(ios::fixed) << setprecision(2);
    int TT = 1;
    pre();
    // cin >> TT;
    while (TT--)
    {
        solve();
        // cout << endl;
    }
}