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
    int num = 0;
    string str;
    while (cin >> str)
    {
        if (str[1] == '+')
        {
            num++;
        }
        else
        {
            num--;
        }
    }
    cout << num;
}