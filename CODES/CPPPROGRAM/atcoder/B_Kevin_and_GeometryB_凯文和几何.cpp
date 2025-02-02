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
    map<int, int> mp;
    set<int> st;
    int num;
    while (n--)
    {
        cin >> num;
        mp[num]++;
        if (mp[num] == 2)
        {
            st.insert(num);
        }
    }
    if (st.empty())
    {
        cout << -1;
        return;
    }
    int num1 = *st.rbegin();

    mp[num1] -= 2;
    vector<int> v1;
    for (auto &&[k, v] : mp)
    {
        for (int i = 0; i < v; i++)
        {
            v1.emplace_back(k);
        }
    }

    if (v1.empty())
    {
        cout << -1;
        return;
    }
    ranges::sort(v1);
    for (int i = 1; i < v1.size(); i++)
    {
        if (v1[i] < v1[i - 1] + 2 * num1)
        {
            cout << num1 << ' ' << num1 << ' ' << v1[i - 1] << ' ' << v1[i];
            return;
        }
    }
    cout << -1;
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