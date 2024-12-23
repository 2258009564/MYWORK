// #pragma GCC optimize(2)
#include <bits/stdc++.h>
using namespace std;
#define BUFF ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
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
typedef vector<bool> vb;
typedef vector<vb> vvb;
typedef vector<vvb> vvvb;
typedef map<int, int> mii;
typedef map<char, int> mci;
#define endl '\n'
#define ts    \
    int T;    \
    cin >> T; \
    while (T--)
#define all(v) v.begin(), v.end()
#define sall(x) sort(all(x))
#define re(v) reverse(all(v))

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

struct Item
{
    int weight;
    int value;
};

signed main()
{
    BUFF;
    int m, n;
    cin >> m >> n;

    // 使用 map 记录组号和对应的物品列表
    map<int, vector<Item>> groupItems;

    for (int i = 0; i < n; i++)
    {
        int a, b, c;
        cin >> a >> b >> c; // 输入物品重量、价值、组号
        groupItems[c].push_back({a, b});
    }

    vector<int> dp(m + 1, 0); // 初始化 dp 数组

    // 遍历每个组
    for (auto &group : groupItems)
    {
        // 从大到小遍历容量，以避免重复选择物品
        for (int j = m; j >= 0; j--)
        {
            // 在当前组中选择一个物品
            int max_value_in_group = dp[j]; // 初始化为当前 dp[j] 的值
            for (auto &item : group.second)
            {
                if (j >= item.weight)
                {
                    max_value_in_group = max(max_value_in_group, dp[j - item.weight] + item.value);
                }
            }
            dp[j] = max_value_in_group;
        }
    }
    cout << dp[m] << endl; // 输出最大利用价值
}