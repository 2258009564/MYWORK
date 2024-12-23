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
    string str;
    cin >> str;
    int man = 0, woman = 0;
    for (int i = 0; i + 2 < str.size(); i++)
    {
        if (str[i] == 'b' or str[i + 1] == 'o' or str[i + 2] == 'y')
        {
            man++;
        }
        else if (str[i] == 'g' or str[i + 1] == 'i' or str[i + 2] == 'r' or str[i + 3] == 'l')
        {
            woman++;
        }
    }
    cout << man << endl
         << woman;
}