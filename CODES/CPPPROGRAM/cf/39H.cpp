#include <bits/stdc++.h>
using namespace std;
#define int long long
#define endl '\n'

vector<char> lettermap = {'0', '1', '2', '3', '4', '5', '6', '7', '8', '9'};

signed main()
{
    int n;
    cin >> n;

    for (int i = 1; i < n; i++)
    {
        for (int j = 1; j < n; j++)
        {
            int num = i * j;
            string s = "";
            while (num)
            {
                s += lettermap[num % n];
                num /= n;
            }
            ranges::reverse(s);
            cout << s << ' ';
        }
        cout << endl;
    }
}