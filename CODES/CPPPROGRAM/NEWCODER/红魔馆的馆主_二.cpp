// #pragma GCC optimize(2)
#include <bits/stdc++.h>
using namespace std;
#define int long long
#define endl '\n'

int N = 485;

void solve()
{
    int n;
    cin >> n;
    vector<int> arr(n);
    map<int, int> mp;
    for (auto &&i : arr)
    {
        cin >> i;
    }
    for (auto &&i : arr)
    {
        if (find(arr.begin(), arr.end(), N / i) != arr.end())
        {
            mp[N / i]++;
        }
    }
    int total1 = 0, total2 = 0;
    bool found = 0;
    for (auto &&i : arr)
    {
        if (mp[i])
        {
            total1 += mp[i];
        }
        if (mp[i + 1] and !found)
        {
            total2 += mp[i + 1];
            found = 1;
        }
        if (mp[i - 1] and !found)
        {
            total2 += mp[i - 1];
            found = 1;
        }
    }
    cout << total1 / 2 + total2;
}

signed main()
{
    ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
    int T = 1;
    // cin >> T;
    while (T--)
    {
        solve();
    }
}