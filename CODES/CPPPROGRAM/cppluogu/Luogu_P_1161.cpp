#include <bits/stdc++.h>
using namespace std;
#define int long long
#define endl '\n'

int returnint(double num)
{
    return (num - (num - (int)num));
}

signed main()
{
    vector<bool> vec(2000000, 0);
    int n, t;
    double a;
    cin >> n;
    while (n--)
    {
        cin >> a >> t;
        for (int i = 1; i <= t; i++)
        {
            int num = floor(i * a);
            vec[num] = !vec[num];
        }
    }
    for (int i = 0; i < vec.size(); i++)
    {
        if (vec[i])
        {
            cout << i;
            return 0;
        }
    }
}