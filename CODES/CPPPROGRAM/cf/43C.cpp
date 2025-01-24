#include <bits/stdc++.h>
using namespace std;
#define int long long
#define endl '\n'

signed main()
{
    int n;
    cin >> n;
    map<int, int> mp;
    int num;
    while (n--)
    {
        cin >> num;
        num %= 3;
        mp[num]++;
    }

    cout << mp[0] / 2 + min(mp[1], mp[2]);
}