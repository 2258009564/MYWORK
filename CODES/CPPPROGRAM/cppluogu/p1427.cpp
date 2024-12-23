#include <bits/stdc++.h>
using namespace std;
#define int long long

signed main()
{
    int n;
    vector<int> vec;
    while (cin >> n)
    {
        vec.push_back(n);
    }
    vec.pop_back();
    reverse(vec.begin(), vec.end());
    for (auto a : vec)
    {
        cout << a << ' ';
    }
}