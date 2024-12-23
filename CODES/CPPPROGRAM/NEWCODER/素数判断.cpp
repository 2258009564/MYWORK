#include <bits/stdc++.h>
using namespace std;
#define ll long long

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

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        bool found = 0;
        if (isPrime(n))
        {
            found = 1;
        }
        cout << (found ? "isprime" : "noprime") << endl;
        for (int i = 2; i <= n / i; i++)
        {
            bool Found = 0;
            while (n % i == 0)
            {
                n /= i;
                Found = 1;
            }
            if (Found)
            {
                cout << i << ' ';
            }
        }
        if(n > 1)
        {
            cout << n;
        }
        cout << endl;
    }
}