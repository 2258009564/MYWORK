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
        int number;
        cin >> number;
        string str = to_string(number);
        int size_of_str = str.size();
        int total = 0;
        for (auto &&i : str)
        {
            int num = (i - '0');
            total += pow(num, size_of_str);
        }
        cout << (total == number ? 'T' : 'F') << endl;
    }
}