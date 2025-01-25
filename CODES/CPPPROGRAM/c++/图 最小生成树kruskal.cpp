#pragma GCC optimize(2)
#pragma GCC optimize("Ofast")
#pragma GCC optimize("inline", "fast-math", "unroll-loops", "no-stack-protector")
#pragma GCC diagnostic error "-fwhole-program"
#pragma GCC diagnostic error "-fcse-skip-blocks"
#pragma GCC diagnostic error "-funsafe-loop-optimizations"
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
    // FU
    vector<int> father;

    auto init = [&](int n)
    {
        father.resize(n);
        iota(father.begin(), father.end(), 0);
    };

    function<int(int)> ffind = [&](int n)
    {
        return n == father[n] ? n : father[n] = ffind(father[n]);
    };

    auto funion = [&](int i, int j)
    {
        auto ri = ffind(i), rj = ffind(j);
        if (ri - rj)
        {
            father[ri] = rj;
        }
    };

    auto issame = [&](int i, int j) -> bool
    {
        return ffind(i) == ffind(j);
    };

    // FU end

    int v, e;
    int v1, v2, val;
    struct Edge
    {
        int l, r, val;
    };
    vector<Edge> edges;
    int ans = 0;
    cin >> v >> e;
    while (e--)
    {
        cin >> v1 >> v2 >> val;
        edges.push_back({v1, v2, val});
    }

    // 执行Kruskal算法
    // 按边的权值对边进行从小到大排序

    ranges::sort(edges, [](Edge &a, Edge &b)
                 { return a.val < b.val; });

    init(10001);

    for (auto &&[l, r, val] : edges)
    {
        // 并查集，搜出两个节点的祖先

        // 如果祖先不同 那么不在同一个集合
        if (!issame(l, r))
        {
            ans += val;
            funion(l, r);
        }
    }
    cout << ans;
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