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
    int total = 0;
    while (stoll(str) != 495)
    {
        total++;
        string maxstr = str;
        sort(maxstr.begin(), maxstr.end(), [](char a, char b)
             { return a > b; });
        string minstr = maxstr;
        reverse(minstr.begin(), minstr.end());

        str = to_string(stoll(maxstr) - stoll(minstr));

        while (str.length() < 3)
            str = "0" + str;
    }
    cout << total;
}