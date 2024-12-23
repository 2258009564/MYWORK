// #pragma GCC optimize(2)
#include <bits/stdc++.h>
using namespace std;
#define int long long
#define endl '\n'

bool cmp(const string &s1, const string &s2)
{
    return stoll(s1 + s2) > stoll(s2 + s1);
}

signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int n;
    cin >> n;
    string arr[n];
    for (auto &&i : arr)
    {
        cin >> i;
    }
    sort(arr, arr + n, cmp);
    for (auto &&i : arr)
    {
        cout << i;
    }
}