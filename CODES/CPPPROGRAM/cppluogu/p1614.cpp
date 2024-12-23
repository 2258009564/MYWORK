#include <bits/stdc++.h>
using namespace std;
#define int long long
#define endl '\n'

signed main()
{
    int n, m, result = INT_MAX;
    cin >> n >> m;
    vector<int> vec(n);
    for (auto &num : vec)
    {
        cin >> num;
    }
    int total = 0;
    for (int i = 0; i < m;i++)
    {
        total += vec[i];
    }
    int i = m;
    result = min(result, total);
    while(i < n)
    {
        total = total - vec[i - m] + vec[i++];
        result = min(result, total);
    }
    cout << result;
}