// #pragma GCC optimize(2)
#include <bits/stdc++.h>
using namespace std;
#define int long long
#define endl '\n'

signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int n;
    int total = 0;
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        for (int j = i; j <= n; j++)
        {
            int k_sq = i * i + j * j;
            int k = sqrt(k_sq);
            if (k * k == k_sq && k <= n)
            {
                total++;
            }
        }
    }
    cout << total << endl;
}
