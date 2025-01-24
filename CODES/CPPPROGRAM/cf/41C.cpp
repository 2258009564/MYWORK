#include <bits/stdc++.h>
using namespace std;
#define int long long
#define endl '\n'

signed main()
{
    string s;
    cin >> s;

    for (int i = 1; i + 2 < s.size(); i++)
    {
        if (s.substr(i, 2) == "at")
        {
            s.replace(i, 2, "@");
            break;
        }
    }

    for (int i = 1; i + 2 + 1 < s.size(); i++)
    {
        if (s.substr(i, 3) == "dot")
        {
            s.replace(i, 3, ".");
        }
    }

    cout << s;
}