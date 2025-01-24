#include <bits/stdc++.h>
using namespace std;
#define int long long
#define endl '\n'

signed main()
{
    int n;
    cin >> n;
    vector<int> v(n), ans(n);
    for (auto &&i : v)
    {
        cin >> i;
    }
    int k;
    cin >> k;
    while (k--)
    {
        for (auto &&i : ans)
        {
            cin >> i;
        }
        bool ye = 0, no = 0, all = 0;
        if (ranges::count(ans, 0) == ans.size())
        {
            all = 1;
        }
        for (int i = 0; i < n; i++)
        {
            if (v[i] == ans[i])
            {
                ye = 1;
            }
            else
            {
                if (ans[i] != 0)
                {
                    no = 1;
                }
            }
        }
        cout << (all or no ? "Ai Ya" : "Da Jiang!!!") << endl;
    }
}