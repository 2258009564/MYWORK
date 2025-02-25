// #pragma GCC optimize(2)
#include <bits/stdc++.h>
using namespace std;
#define int long long
#define endl '\n'
#define all(x) (x).begin(), (x).end()

const int INF = 1e9;     // 无穷大
const int INFLL = 1e18;  // 长整型无穷大
const int MOD = 1e9 + 7; // 模数
// -9.2e18 ~ 9.2e18

void solve()
{
    int n;
    cin >> n;
    vector<int> v(n);
    map<int, int> mp;
    vector<int> a;
    for (int i = 0; i < n; i++)
    {
        cin >> v[i];
        mp[v[i]]++;
    }
    int check = 0;
    for (auto &&[k, v] : mp)
    {
        check += (v / 2);
        if (v / 2)
        {
            for (int i = 0; i < v / 2; i++)
            {
                a.push_back(k);
            }
        }
    }
    if (check < 4)
    {
        cout << "NO";
        return;
    }
    else
    {
        cout << "YES" << endl;
    }

    // 需要四对
    // 要让面积最大 我们需要尽可能挑选
    ranges::sort(a);
    // x1, x2 <=> y1, y2
    auto x1 = a[0], x2 = a[a.size() - 1], y1 = a[1], y2 = a[a.size() - 2];

    if ((x2 - x1) * (y2 - y1) < (y2 - x1) * (x2 - y1))
    {
        swap(x2, y2);
    }

    cout << x1 << ' ' << y1 << ' ' << x1 << ' ' << y2 << ' ' << x2 << ' ' << y1 << ' ' << x2 << ' ' << y2;
}

signed main()
{
    cin.tie(nullptr)->ios::sync_with_stdio(false);
    cout << setiosflags(ios::fixed) << setprecision(2);
    int TT = 1;
    cin >> TT;
    while (TT--)
    {
        solve();
        cout << endl;
    }
}