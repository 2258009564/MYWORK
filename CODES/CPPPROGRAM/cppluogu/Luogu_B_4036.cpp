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
    string str;
    while (cin >> str)
    {
        int total = 0;
        for (auto &&i : str)
        {
            total += i - '0';
        }
        cout << (total % 7 == 0 ? "Yes" : "No") << endl;
    }
}