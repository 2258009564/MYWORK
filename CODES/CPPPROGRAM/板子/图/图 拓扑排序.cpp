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
    unordered_map<int, vector<int>> adj; // 邻接表
    vector<int> indegree(n, 0);          // 统计入度
    vector<int> result;                  // 结果集合
    int s, t;
    while (m--)
    {
        cin >> s >> t;
        indegree[t]++;
        adj[s].push_back(t);
    }

    queue<int> que;
    for (int i = 0; i < n; i++)
    {
        // 入度为0 可以作为开头 加入队列
        if (!indegree[i])
        {
            que.push(i);
        }
    }

    while (que.size())
    {
        auto cur = que.front();
        que.pop();
        result.push_back(cur);

        if (adj[cur].size())
        {
            for (auto &&i : adj[cur])
            {
                indegree[i]--;
                if (indegree[i] == 0)
                {
                    que.push(i);
                }
            }
        }
    }
    if (result.size() - n)
    {
        cout << -1;
    }
    else
    {
        cout << result;
    }
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