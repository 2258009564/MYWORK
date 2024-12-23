#include <bits/stdc++.h>
using namespace std;
#define int long long

signed main()
{
    int x, n, total = 0;
    cin >> x >> n;
    for (int i = x; i < x + n; i++)
    {
        if (i % 7 != 6 && i % 7 != 0)
        {
            total++;
        }
    }
    cout << total * 250;
}
