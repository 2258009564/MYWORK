// #pragma GCC optimize(2)
#include <bits/stdc++.h>
using namespace std;
#define int long long
#define endl '\n'

bool issq(int n)
{
    int sq = sqrt(n);
    return sq * sq == n;
}

signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int n;
    cin >> n;
    int num;
    while (cin >> num)
    {
        bool found = 0;
        for (int i = 1; i * 2 <= num; i++)
        {
            int j = num - i;
            if (issq(i) and issq(j))
            {
                cout << "Yes" << endl;
                found = 1;
                break;
            }
        }
        if (!found)
        {
            cout << "No" << endl;
        }
    }
}