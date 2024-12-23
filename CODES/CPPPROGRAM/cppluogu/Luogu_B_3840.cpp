// #pragma GCC optimize(2)
#include <bits/stdc++.h>
using namespace std;
#define int long long
#define endl '\n'

vector<bool> isPrime(int n)
{
    vector<bool> isprime(n + 1, true);
    isprime[0] = isprime[1] = false; 
    for (int i = 2; i * i <= n; i++)
    {
        if (isprime[i])
        {
            for (int j = i * i; j <= n; j += i)
            {
                isprime[j] = false;
            }
        }
    }
    return isprime;
}

signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int n, m;
    cin >> n >> m;
    int total = 0;
    auto vec = isPrime(m);
    for (int i = n; i <= m; i++)
    {
        total += vec[i];
    }
    cout << total << endl;
}
