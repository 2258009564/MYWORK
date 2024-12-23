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
    char a;
    cin >> n >> a;
    int total = 0;
    for (int i = 1; i <= n; i++)
    {
        string str = to_string(i);
        for (auto &&i : str)
        {
            if(i == a)
            {
                total++;
            }
        }
        
    }
    cout << total;
}