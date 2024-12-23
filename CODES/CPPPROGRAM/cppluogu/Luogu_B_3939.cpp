// #pragma GCC optimize(2)
#include <bits/stdc++.h>
using namespace std;
#define int long long
#define endl '\n'

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
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int n, m;
    cin >> n >> m;
    for (int i = n; i <= m; i++)
    {
        string s = to_string(i);
        reverse(s.begin(), s.end());
        int j = stoll(s);
        if (isPrime(i) and isPrime(j))
        {
            cout << i << endl;
        }
    }
}