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
    cin >> n;
    vector<int> arr(n);
    for (auto &&i : arr)
    {
        cin >> i;
    }
    int total = 0;
    sort(arr.begin(), arr.end());
    while (arr[n - 1])
    {
        total++;
        for (auto &&i : arr)
        {
            i--;
        }
        for (int i = 0; i < arr.size() - 1; i++)
        {
            if (arr[i] and arr[i + 1])
            {
                arr[i]--;
                arr[i + 1]--;
                break;
            }
        }
        for (int i = 0; i < arr.size(); i++)
        {
            if (arr[i])
            {
                arr[i]--;
                break;
            }
        }
    }
    cout << total;
}