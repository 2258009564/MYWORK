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

const int INF = 1e9;     // 无穷大
const int INF_LL = 1e18; // 长整型无穷大
const int MOD = 1e9 + 7; // 模数

void solve()
{
    // 最小生成树之 Prim 算法
    /*
    三部曲：
    第一步，选距离生成树最近节点
    第二步，最近节点加入生成树
    第三步，更新非生成树节点到生成树的距离（即更新minDist数组）
    */
    int v, e; // v 个顶点，e 条边
    cin >> v >> e;

    unordered_map<int, unordered_map<int, int>> grid;
    while (e--)
    {
        int a, b, w;
        std::cin >> a >> b >> w;
        a--, b--;
        grid[a][b] = w;
        grid[b][a] = w;
    }

    vector<int> minDist(v, INF);     // 记录每个节点到最小生成树的最小距离
    vector<bool> isInTree(v, false); // 记录每个节点是否在最小生成树中
    vi parent(v, -1);                // 记录每个节点的父节点
    int _ = v - 1;
    while (_--) // 我们只需要循环 n - 1 次，建立 n - 1 条边，就可以把 n 个节点的图连在一起
    {
        int cur, minval = INF_LL;
        for (int i = 0; i < v; i++)
        {
            //  选取最小生成树节点的条件：
            //  （1）不在最小生成树里
            //  （2）距离最小生成树最近的节点
            if (!isInTree[i] and minDist[i] < minval)
            {
                minval = minDist[i], cur = i;
            }
        }

        // 2、prim三部曲，第二步：最近节点（cur）加入生成树
        isInTree[cur] = true;

        // 3、prim三部曲，第三步：更新非生成树节点到生成树的距离（即更新minDist数组）
        // cur节点加入之后， 最小生成树加入了新的节点，那么所有节点到 最小生成树的距离（即minDist数组）需要更新一下
        // 由于cur节点是新加入到最小生成树，那么只需要关心与 cur 相连的 非生成树节点 的距离 是否比 原来 非生成树节点到生成树节点的距离更小了呢
        for (auto &&[dot, w] : grid[cur])
        {
            // 更新条件：
            // (1) 节点 dot 还不在最小生成树中
            // (2) 从当前节点 cur 到节点 dot 的边权值 w 小于节点 dot 当前记录的最小距离
            // 如果满足这两个条件，就更新节点 dot 到最小生成树的最小距离
            if (!isInTree[dot] && w < minDist[dot])
            {
                minDist[dot] = w;
                parent[dot] = cur;
            }
        }
    }

    for (int i = 0; i < parent.size(); i++)
    {
        cout << i << "->" << parent[i] << "->" << minDist[i] << endl;
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