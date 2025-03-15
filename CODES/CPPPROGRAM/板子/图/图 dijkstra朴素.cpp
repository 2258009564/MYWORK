// #pragma GCC optimize(2)
// #pragma GCC optimize("Ofast")
// #pragma GCC optimize("inline", "fast-math", "unroll-loops", "no-stack-protector")
// #pragma GCC diagnostic error "-fwhole-program"
// #pragma GCC diagnostic error "-fcse-skip-blocks"
// #pragma GCC diagnostic error "-funsafe-loop-optimizations"
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

const int INF = 1e9;     // 无穷大
const int INF_LL = 1e18; // 长整型无穷大
const int MOD = 1e9 + 7; // 模数

void solve()
{
    int n, m;
    cin >> n >> m;
    unordered_map<int, unordered_map<int, int>> adj; // 邻接表
    int s, e, v;
    while (m--)
    {
        cin >> s >> e >> v;
        adj[s][e] = v;
    }

    /*
    第一步，选源点到哪个节点近且该节点未被访问过
    第二步，该最近节点被标记访问过
    第三步，更新非访问节点到源点的距离（即更新minDist数组）
    */

    vector<int> minDist(n + 1, INT_MAX); // 每一个节点到源点的最小距离

    vector<bool> visited(n + 1, false);

    int start = 1, en = n;
    minDist[start] = 0;

  for (int i = 1; i <= n; i++) // 遍历所有节点
    {
        int cur = 1, minval = INT_MAX;
        for (int v = 1; v <= n; v++) // 选择距离源点最近而且未被访问的点
        {
            if (!visited[v] and minDist[v] < minval)
            {
                minval = minDist[v], cur = v;
            }
        }

        visited[cur] = 1; // 标记该节点已经被访问

        for (auto &&[next, val] : adj[cur])
        {
            if (!visited[next])
            {
                minDist[next] = min(minDist[next], minDist[cur] + val);
            }
        }
    }

    cout << (minDist[en] == INT_MAX ? -1 : minDist[en]);
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