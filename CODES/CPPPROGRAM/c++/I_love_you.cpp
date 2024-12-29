// #pragma GCC optimize(2)
#include <bits/stdc++.h>
using namespace std;
#define int long long
typedef pair<int, int> pii;
typedef pair<double, double> pdd;
typedef vector<string> vs;
typedef vector<vs> vvs;
typedef vector<vvs> vvvs;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<vvi> vvvi;
typedef vector<pii> vpii;
typedef vector<vpii> vvpii;
typedef vector<pdd> vpdd;
typedef vector<double> vd;
typedef vector<vd> vvd;
typedef vector<char> vc;
typedef vector<vc> vvc;
typedef vector<vvc> vvvc;
typedef map<int, int> mii;
typedef map<char, int> mci;
#define endl '\n'
#define all(v) v.begin(), v.end()
#define sall(v, x) sort(all(v), x)

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

const int mod = 1e9 + 7;

map<int, mii> result;
vi path;

void backtracking(int startindex, map<int, vvi> mp, int sum, int n)
{
    if (startindex == n)
    {
        for (auto &&i : path)
        {
            result[sum][i] = 1; // 标记总和为sum的时候 最短路径包含了i
        }
        return;
    }

    for (auto &&v : mp[startindex])
    {
        auto money = v[1], cur = v[0], index = v.back();

        path.push_back(index);
        backtracking(cur, mp, sum + money, n);
        path.pop_back();
    }
}

void solve()
{
    result.clear();
    path.clear();
    int n, m;
    cin >> n >> m;

    map<int, vvi> mp;
    int u, v, w;

    for (int i = 1; i <= m; i++)
    {
        cin >> u >> v >> w;
        mp[u].push_back({v, w, i}); // 另一个节点， 价格， 第i条路
    }

    backtracking(1, mp, 0, n);

    int minsum = 0;

    for (auto &&[k, v] : result)
    {
        if (!v.empty())
        {
            minsum = k;
            break;
        }
    }

    for (int i = 1; i <= m; i++)
    {
        cout << result[minsum][i];
    }
}

signed main()
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int TT = 1;
    cin >> TT;
    while (TT--)
    {
        solve();
        cout << endl;
    }
}