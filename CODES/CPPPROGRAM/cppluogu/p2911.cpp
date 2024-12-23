#include <bits/stdc++.h>
using namespace std;
#define int long long
#define endl '\n'

signed main()
{
    map<int, int> mp;
    int a, b, c;
    cin >> a >> b >> c;
    for (int i = 1; i <= a; i++)
    {
        for (int j = 1; j <= b; j++)
        {
            for (int k = 1; k <= c; k++)
            {
                mp[i + j + k]++;
            }
        }
    }
    int max_num = 0;
    for (const auto & pr : mp)
    {
        // max_num = max(max_num, value);
    }
    for (auto [key, value] : mp)
    {
        if (value == max_num)
        {
            cout << key;
            return 0;
        }
    }
}