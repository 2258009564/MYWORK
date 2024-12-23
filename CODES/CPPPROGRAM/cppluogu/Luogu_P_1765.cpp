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
    string line;
    getline(cin, line);
    int total = 0;
    for (auto c : line)
    {
        if (c == ' ' or c == 'a' or c == 'd' or c == 'g' or c == 'j' or c == 'm' or c == 'p' or c == 't' or c == 'w')
        {
            total++;
        }
        else if (c == 'b' or c == 'e' or c == 'h' or c == 'k' or c == 'n' or c == 'q' or c == 'u' or c == 'x')
        {
            total += 2;
        }
        else if (c == 'c' or c == 'f' or c == 'i' or c == 'l' or c == 'o' or c == 'r' or c == 'v' or c == 'y')
        {
            total += 3;
        }
        else
        {
            total += 4;
        }
    }
    cout << total;
}