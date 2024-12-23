#include <bits/stdc++.h>
using namespace std;
#define int long long

void sieve(int n){
    vector<bool> isPrime(n + 1, 1);
    isPrime[0] = isPrime[1] = 0;
    for (int i = 2; i <= n / i;i++)
    {
        if(isPrime[i])
        {
            {
            for (int j = i * i; j <= n; j += i)
                isPrime[j] = 0;
            }
        }
    }

    //cout
    for (int i = 2; i <= n;i++)
    {
        if(isPrime[i])
        {
            cout << i << ' ';
        }
    }
}

signed main() {
    int n;
    cin >> n;
    sieve(n);
}