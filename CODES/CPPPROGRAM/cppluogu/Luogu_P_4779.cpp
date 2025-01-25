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
    // 单源最短路 with dijkstra

    int n, m, s, v1, v2, val;
    cin >> n >> m >> s;
    s--;
    unordered_map<int, unordered_map<int, int>> adj;

    while (m--)
    {
        cin >> v1 >> v2 >> val;
        v1--, v2--;
        adj[v1][v2] = val;
    }

    vector<int> minDist(n, INF);
    vector<int> visited(n, 0);
    minDist[s] = 0;

    auto _ = n;
    while (_--)
    {
        int cur, minval = INT_MAX;
        for (int i = 0; i < n; i++)
        {
            if (!visited[i] and minval > minDist[i])
            {
                minval = minDist[i], cur = i;
            }
        }

        visited[cur] = 1;

        for (auto &&[next, w] : adj[cur])
        {
            if (!visited[next])
            {
                minDist[next] = min(minDist[next], minDist[cur] + w);
            }
        }
    }

    for (int i = 0; i < n; i++)
    {
        cout << minDist[i] << ' ';
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