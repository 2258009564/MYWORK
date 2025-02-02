// #pragma GCC optimize(2)
#include <bits/stdc++.h>
using namespace std;
#define int long long
#define endl '\n'

const int INF = 1e9;     // 无穷大
const int INFLL = 1e18;  // 长整型无穷大
const int MOD = 1e9 + 7; // 模数

void solve()
{
    int n;
    cin >> n;
    vector<int> v(n);
    bool found = 0;
    for (auto &&i : v)
    {
        cin >> i;
        if (i <= 0)
        {
            found = 1;
        }
    }

    if (n == 1)
    {
        cout << v[0];
        return;
    }

    if (!found)
    {
        cout << accumulate(v.begin(), v.end(), 0ll);
        return;
    }

    int maxans = accumulate(v.begin(), v.end(), 0ll);
    while (v.size() > 1)
    {
        vector<int> diff;
        int ans = 0;

        for (int i = 1; i < v.size(); i++)
        {
            diff.push_back(v[i] - v[i - 1]);
            ans += diff[i - 1];
        }

        if (ans < 0)
        {
            for (auto &&i : diff)
            {
                i = -i;
            }
            ans = -ans;
            reverse(diff.begin(), diff.end());
        }

        maxans = max(maxans, ans);
        
        v = diff;
    }

    cout << maxans;
}

signed main()
{
    cin.tie(nullptr)->sync_with_stdio(false);
    int TT = 1;
    cin >> TT;
    while (TT--)
    {
        solve();
        cout << endl;
    }
}