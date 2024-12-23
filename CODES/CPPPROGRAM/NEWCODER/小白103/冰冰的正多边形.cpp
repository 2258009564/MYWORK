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
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        map<int, int> mp;
        while (n--)
        {
            int num;
            cin >> num;
            mp[num]++;
        }
        int total = INT_MAX;
        bool found = 0;
        for (auto &&[k, v] : mp)
        {
            if(v>2)
            {
                found = 1;
                total = min(total, k * 3);
            }
        }
        cout << (found ? "yes" : "no") << endl;
        if(found)
        {
            cout << total << endl;
        }
    }
}