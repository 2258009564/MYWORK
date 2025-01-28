// #pragma GCC optimize(2)
#include <bits/stdc++.h>
using namespace std;
#define int long long
#define endl '\n'

// 通用版本的 >> 重载，用于任意类型的 std::vector<T>
template <typename T>
istream &operator>>(istream &in, vector<T> &v)
{
    for (auto &x : v)
    {
        in >> x;
    }
    return in;
}

// 通用版本的 << 重载，用于任意类型的 std::vector<T>
template <typename T>
ostream &operator<<(ostream &out, const vector<T> &v)
{
    for (const auto &x : v)
    {
        out << x << ' ';
    }
    return out;
}

const int INF = 1e9;     // 无穷大
const int INFLL = 1e18;  // 长整型无穷大
const int MOD = 1e9 + 7; // 模数

void solve()
{
    int n;
    cin >> n;

    unordered_map<int, vector<pair<int, int>>> mp;

    for (int i = 1; i <= n; i++)
    {
        int l, r;
        cin >> l >> r;
        mp[l].push_back({r, i});
    }
    vector<int> ans(n + 1);
    // use priority_queue to store the r and id of the datas
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;

    for (int i = 1; i <= n; i++) // 遍历每个 l
    {
        for (auto &&[r, id] : mp[i])
        {
            pq.push({r, id});
        }

        if (pq.empty())
        {
            cout << -1;
            return;
        }

        auto [r, id] = pq.top();
        pq.pop();

        if (r < i)
        {
            cout << -1;
            return;
        }

        ans[id] = i;
    }

    for (int i = 1; i <= n; i++)
    {
        cout << ans[i] << ' ';
    }

    // -- 以下是使用 set 的版本 --

    // vector<vector<int>> v;
    // for (int i = 1; i <= n; i++)
    // {
    //     int l, r;
    //     cin >> l >> r;
    //     v.push_back({r, l, i});
    // }

    // set<int> s;
    // for (int i = 1; i <= n; i++)
    // {
    //     s.insert(i);
    // }

    // vector<int> ans(n + 1);
    // ranges::sort(v);

    // // 遍历 v 即可

    // for (auto &vec : v)
    // {
    //     auto r = vec[0], l = vec[1], id = vec[2];
    //     if (auto it = s.lower_bound(l); it != s.end() and *it <= r)
    //     {
    //         ans[id] = *it;
    //         s.erase(it);
    //     }
    //     else
    //     {
    //         cout << -1;
    //         return;
    //     }
    // }

    // for (int i = 1; i <= n; i++)
    // {
    //     cout << ans[i] << ' ';
    // }
}

signed main()
{
    cin.tie(nullptr)->sync_with_stdio(false);
    int TT = 1;
    // cin >> TT;
    while (TT--)
    {
        solve();
        cout << endl;
    }
}