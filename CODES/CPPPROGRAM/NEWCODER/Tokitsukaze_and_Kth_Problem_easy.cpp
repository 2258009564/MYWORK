#include <bits/stdc++.h>
using namespace std;
#define int long long
#define endl '\n'

const int INF = 1e9;     // 无穷大
const int INFLL = 1e18;  // 长整型无穷大
const int MOD = 1e9 + 7; // 模数

void solve()
{
    int n, p, k;
    cin >> n >> p >> k;

    vector<int> a(n);
    for (auto &&x : a)
    {
        cin >> x;
    }

    vector<int> all_vals;

    for (int i = 0; i < n; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            all_vals.push_back((a[i] + a[j]) % p);
        }
    }

    partial_sort(all_vals.begin(), all_vals.begin() + min(k, (int)all_vals.size()), all_vals.end(), greater<int>());

    for (int i = 0; i < k; i++)
    {
        if (i < all_vals.size())
        {
            cout << all_vals[i] << " ";
        }
        else
        {
            cout << -1 << " ";
        }
    }
    cout << endl;
}

signed main()
{
    cin.tie(nullptr)->sync_with_stdio(false);
    cout << setiosflags(ios::fixed) << setprecision(2);

    int TT = 1;
    cin >> TT;
    while (TT--)
    {
        solve();
    }
    return 0;
}
