#include <bits/stdc++.h>
using namespace std;
#define int long long
#define endl '\n'

signed main()
{
    int n;
    cin >> n;
    vector<int> v;
    string s;
    cin >> s;

    for (int i = 0; i < s.size(); i++)
    {
        if (s[i] == '1')
        {
            v.push_back(i);
        }
    }
    int check = v[1] - v[0];
    for (int i = 2; i < v.size(); i++)
    {
        auto num1 = v[i] - v[i - 1];
        if (num1 != check)
        {
            cout << "NO";
            return 0;
        }
    }
    cout << "YES";
}