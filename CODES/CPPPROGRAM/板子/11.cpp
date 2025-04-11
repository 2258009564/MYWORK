// COMB begin ----
const int N = 1e6;
vector<int> f(N), invf(N);
bool inited = 0;
int ksm(int base, int exp)
{
    int ans = 1;
    while (exp)
    {
        if (exp & 1)
        {
            ans = ans * base % MOD;
        }
        base = base * base % MOD;
        exp >>= 1;
    }
    return ans;
}

int inv(int x)
{
    return ksm(x, MOD - 2) % MOD;
}

void pre()
{
    if (inited)
    {
        return;
    }
    inited = 1;
    f[0] = 1;
    for (int i = 1; i < N; i++)
    {
        f[i] = f[i - 1] * i % MOD;
    }

    invf[N - 1] = inv(f[N - 1]);
    for (int i = N - 2; i >= 0; i--)
    {
        invf[i] = invf[i + 1] * (i + 1) % MOD;
    }
}

int comb(int n, int k)
{
    if (!inited)
    {
        pre();
    }
    if (k < 0 or k > n)
    {
        return 0;
    }

    return f[n] * invf[k] % MOD * invf[n - k] % MOD;
}
// comb end ----

const int N = 1e7;

vector<int> primes, isp(N + 1, 1);
void pre()
{
    isp[0] = isp[1] = 0;
    for (int i = 2; i <= N; i++)
    {
        if (isp[i])
        {
            for (int j = i; j <= N; j += i)
            {
                isp[j] = 0;
            }
        }
    }

    for (int i = 2; i <= N; i++)
    {
        if (isp[i])
        {
            primes.emplace_back(i);
        }
    }
}

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

class BIT
{
private:
    vector<int> c;
    int n;

    int lowbit(int x)
    {
        return x & -x;
    }

public:
    BIT(int size) : n(size)
    {
        c.resize(n + 1, 0);
    }

    BIT(vector<int> &arr) : n(arr.size())
    {
        c.resize(n + 1, 0);
        for (int i = 1; i <= n; i++)
        {
            add(i, arr[i - 1]);
        }
    }

    void add(int i, int val)
    {
        while (i <= n)
        {
            c[i] += val;
            i += lowbit(i);
        }
    }

    int sum(int i)
    {
        int ans = 0;
        while (i)
        {
            ans += c[i];
            i -= lowbit(i);
        }
        return ans;
    }

    int query(int l, int r)
    {
        return sum(r) - sum(l - 1);
    }

    int get(int i)
    {
        return query(i, i);
    }

    int update(int i, int val)
    {
        auto delta = val = get(i);
        add(i, delta);
    }

    void clear()
    {
        fill(all(c), 0);
    }

    // 获取树状数组的大小
    int size()
    {
        return n;
    }
};

void solve()
{
    int n, m;
    cin >> n >> m;
    struct Edge
    {
        int v1, v2, val;
        Edge(int v1, int v2, int val) : v1(v1), v2(v2), val(val) {};
    };
    vector<Edge> edges;

    int v1, v2, val;
    while (m--)
    {
        cin >> v1 >> v2 >> val;
        auto [a, b] = minmax(v1, v2);
        edges.emplace_back(a, b, val);
    }
    ranges::sort(edges, [](Edge &a, Edge &b)
                 { return a.val < b.val; });

    // FU begin
    vector<int> father;
    auto init = [&](int n)
    {
        father.resize(n + 1);
        iota(father.begin(), father.end(), 0ll);
    };
    function<int(int)> ffind = [&](int i)
    {
        return i == father[i] ? i : ffind(father[i]);
    };
    auto funion = [&](int i, int j)
    {
        auto ri = ffind(i), rj = ffind(j);
        if (ri != rj)
        {
            father[ri] = rj;
        }
    };

    auto issame = [&](int i, int j) -> bool
    {
        return ffind(i) == ffind(j);
    };
    // FU end
    init(n);

    int MSTweight = 0, MSTnode = 0;

    for (auto &&[v1, v2, val] : edges)
    {
        if (!issame(v1, v2))
        {
            funion(v1, v2);
            MSTweight += val;
            MSTnode++;
        }
        if (MSTnode == n - 1)
        {
            cout << MSTnode;
            return;
        }
    }
    cout << -1;
    return;
}

void solve()
{
    int v, e;
    cin >> v >> e;
    int vsz = v + 1;

    vector<vector<pair<int, int>>> adj(vsz + 1);
    int v1, v2, val;
    while (e--)
    {
        cin >> v1 >> v2 >> val;
        adj[v1].emplace_back(v2, val);
        adj[v2].emplace_back(v1, val);
    }

    // prim begin
    vector<int> visited(vsz, 0), minDist(vsz, INFLL);
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<>> pq;

    minDist[1] = 0;
    pq.push({0, 1});

    int totalweight = 0, nodeInMST = 0;

    while (pq.size())
    {
        auto [w, cur] = pq.top();
        pq.pop();

        if (visited[cur])
        {
            continue;
        }

        visited[cur] = 1;
        totalweight += w;
        nodeInMST++;

        for (auto &&[next, nextw] : adj[cur])
        {
            if (visited[next])
            {
                continue;
            }

            if (nextw < minDist[next])
            {
                minDist[next] = nextw;
                pq.push({minDist[next], next});
            }
        }
    }
    if (nodeInMST != v)
    {
        cout << -1;
        return;
    }
    cout << totalweight;
}

void solve()
{
    int n, m, s, t, v;
    cin >> n >> m;
    unordered_map<int, unordered_map<int, int>> adj;
    while (m--)
    {
        cin >> s >> t >> v;
        adj[s][t] = v;
    }

    vector<int> minDist(n + 1, INF);
    minDist[1] = 0;

    int _ = n - 1;
    while (_--) //
    {
        for (auto &&[v1, v] : adj)
        {
            for (auto &&[v2, val] : v)
            {
                if (minDist[v1] != INF)
                {
                    minDist[v2] = min(minDist[v2], minDist[v1] + val);
                }
            }
        }
    }

    if (minDist[n] == INF)
    {
        cout << "unconnected";
    }
    else
    {
        cout << minDist[n];
    }
}

void solve()
{
    int n, m;
    cin >> n >> m;
    vector<vector<pair<int, int>>> adj(n + 1); // 邻接表，pair<节点, 距离>
    int s, e, v;
    while (m--)
    {
        cin >> s >> e >> v;
        adj[s].push_back({e, v});
    }

    /*
    堆优化版Dijkstra算法:
    1. 使用优先队列维护当前所有可达但未访问的节点，按距离排序
    2. 每次取出队列中距离最小的节点，标记为已访问
    3. 更新该节点邻居的距离，并将新的可能路径加入队列
    */

    vector<int> minDist(n + 1, INT_MAX); // 每一个节点到源点的最小距离
    vector<bool> visited(n + 1, false);  // 记录节点是否已被访问

    int start = 1, en = n;
    minDist[start] = 0;

    // 优先队列，存储<距离, 节点编号>，按距离从小到大排序
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    pq.push({0, start});

    while (!pq.empty())
    {
        int dist = pq.top().first;
        int cur = pq.top().second;
        pq.pop();

        if (visited[cur])
            continue;        // 如果已经访问过，跳过
        visited[cur] = true; // 标记为已访问

        // 更新当前节点的所有邻居
        for (const auto &edge : adj[cur])
        {
            int next = edge.first;
            int weight = edge.second;

            if (!visited[next] && minDist[cur] + weight < minDist[next])
            {
                minDist[next] = minDist[cur] + weight;
                pq.push({minDist[next], next});
            }
        }
    }

    cout << (minDist[en] == INT_MAX ? -1 : minDist[en]);
}

void solve()
{
    int n;
    cin >> n;
    vector v(n + 1, vector<int>(n + 1, INT_MAX));
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            cin >> v[i][j];
        }
    }

    // floyd
    for (int k = 1; k <= n; k++)
    {
        for (int i = 1; i <= n; i++)
        {
            for (int j = 1; j <= n; j++)
            {
                v[i][j] = min(v[i][j], v[i][k] + v[k][j]);
            }
        }
    }
}

// bfs

vector<pair<int, int>> d = {{1, 0}, {0, 1}, {-1, 0}, {0, -1}};

auto bfs = [&](int i, int j)
{
    queue<pair<int, int>> q;
    q.push({i, j});
    vis[i][j] = 1;

    while (q.size())
    {
        auto [x, y] = q.front();
        q.pop();

        for (auto &&[dx, dy] : d)
        {
            auto xx = x + dx, yy = y + dy;

            if (xx < 0 or xx >= n or yy < 0 or yy >= m or v[xx][yy] == 1 or vis[xx][yy])
            {
                continue;
            }

            vis[xx][yy] = 1;
            q.push({xx, yy});
        }
    }
};
// bfs end

// dfs
vector<pair<int, int>> d = {{1, 0}, {0, 1}, {-1, 0}, {0, -1}};

function<void(int, int)> dfs = [&](int i, int j)
{
    if (i < 0 or i >= n or j < 0 or j >= m or vis[i][j] or v[i][j] == 0)
    {
        return;
    }

    vis[i][j] = 1;

    for (auto &&[dx, dy] : d)
    {
        dfs(i + dx, j + dy);
    }
};
// dfs end

class DSU
{
private:
    vector<int> parent, rank, size;
    int count;

public:
    DSU(int n) : parent(n + 1), rank(n + 1, 0), size(n + 1, 1), count(n)
    {
        iota(all(parent), 0ll);
    }

    int find(int x)
    {
        return parent[x] == x ? x : parent[x] = find(parent[x]);
    }

    void merge(int i, int j)
    {
        int ri = find(i), rj = find(j);
        if (ri == rj)
        {
            return;
        }

        if (rank[ri] < rank[rj])
        {
            swap(ri, rj);
        }
        parent[rj] = ri;
        size[ri] += size[rj];
        if (rank[ri] == rank[rj])
        {
            rank[ri]++;
        }
        count--;
    }

    bool issame(int i, int j)
    {
        return find(i) == find(j);
    }

    int getsize(int x)
    {
        return size[find(x)];
    }

    int getgroups()
    {
        return count;
    }
};

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
    int l = 0, r = INF, m, ans;
    while (l <= r)
    {
        m = l + (r - l) / 2;
        auto check = [&]() -> bool
        {
            // ...
        };
        if (check())
        {
            r = (ans = m) - 1;
        }
        else
        {
            l = m + 1;
        }
    }
    cout << ans;
}

signed main()
{
    cin.tie(0)->ios::sync_with_stdio(0);
    cout << setiosflags(ios::fixed) << setprecision(2);
    int TT = 1;
    // cin >> TT;
    while (TT--)
    {
        solve();
        cout << endl;
    }
}

// 线段树节点结构
struct Node
{
    int l, r;           // 节点覆盖的区间范围
    int sum;            // 区间和
    int max_val;        // 区间最大值
    int min_val;        // 区间最小值
    int lazy;           // 懒标记
    Node *left, *right; // 左右子节点指针

    // 初始化节点
    Node(int _l, int _r) : l(_l), r(_r), sum(0), max_val(-INF),
                           min_val(INF), lazy(0), left(NULL), right(NULL) {}

    // 更新节点信息（合并子节点信息）
    void pushUp()
    {
        if (left && right)
        {
            sum = left->sum + right->sum;
            max_val = max(left->max_val, right->max_val);
            min_val = min(left->min_val, right->min_val);
        }
    }

    // 下传懒标记
    void pushDown()
    {
        if (lazy == 0)
            return;

        // 如果子节点不存在，先创建
        if (!left)
            left = new Node(l, (l + r) / 2);
        if (!right)
            right = new Node((l + r) / 2 + 1, r);

        // 更新子节点的值和懒标记
        left->sum += lazy * (left->r - left->l + 1);
        right->sum += lazy * (right->r - right->l + 1);
        left->max_val += lazy;
        right->max_val += lazy;
        left->min_val += lazy;
        right->min_val += lazy;
        left->lazy += lazy;
        right->lazy += lazy;

        // 清除当前节点的懒标记
        lazy = 0;
    }
};

// 建立一棵空的线段树
Node *build(int l, int r)
{
    Node *root = new Node(l, r);
    if (l == r)
        return root;

    int mid = (l + r) / 2;
    root->left = build(l, mid);
    root->right = build(mid + 1, r);
    return root;
}

// 单点更新
void update(Node *root, int pos, int val)
{
    if (!root)
        return;

    // 到达叶子节点
    if (root->l == root->r && root->l == pos)
    {
        root->sum += val;
        root->max_val = root->min_val = root->sum;
        return;
    }

    root->pushDown(); // 下传懒标记

    int mid = (root->l + root->r) / 2;
    if (pos <= mid)
    {
        if (!root->left)
            root->left = new Node(root->l, mid);
        update(root->left, pos, val);
    }
    else
    {
        if (!root->right)
            root->right = new Node(mid + 1, root->r);
        update(root->right, pos, val);
    }

    root->pushUp(); // 更新当前节点信息
}

// 区间更新
void updateRange(Node *root, int l, int r, int val)
{
    if (!root)
        return;

    // 完全覆盖
    if (root->l >= l && root->r <= r)
    {
        root->sum += val * (root->r - root->l + 1);
        root->max_val += val;
        root->min_val += val;
        root->lazy += val;
        return;
    }

    root->pushDown(); // 下传懒标记

    int mid = (root->l + root->r) / 2;
    if (l <= mid)
    {
        if (!root->left)
            root->left = new Node(root->l, mid);
        updateRange(root->left, l, r, val);
    }
    if (r > mid)
    {
        if (!root->right)
            root->right = new Node(mid + 1, root->r);
        updateRange(root->right, l, r, val);
    }

    root->pushUp(); // 更新当前节点信息
}

// 查询区间和
int querySum(Node *root, int l, int r)
{
    if (!root)
        return 0;

    // 完全覆盖
    if (root->l >= l && root->r <= r)
    {
        return root->sum;
    }

    root->pushDown(); // 下传懒标记

    int mid = (root->l + root->r) / 2;
    int res = 0;
    if (l <= mid && root->left)
    {
        res += querySum(root->left, l, r);
    }
    if (r > mid && root->right)
    {
        res += querySum(root->right, l, r);
    }

    return res;
}

// 查询区间最大值
int queryMax(Node *root, int l, int r)
{
    if (!root)
        return -INF;

    // 完全覆盖
    if (root->l >= l && root->r <= r)
    {
        return root->max_val;
    }

    root->pushDown(); // 下传懒标记

    int mid = (root->l + root->r) / 2;
    int res = -INF;
    if (l <= mid && root->left)
    {
        res = max(res, queryMax(root->left, l, r));
    }
    if (r > mid && root->right)
    {
        res = max(res, queryMax(root->right, l, r));
    }

    return res;
}

// 查询区间最小值
int queryMin(Node *root, int l, int r)
{
    if (!root)
        return INF;

    // 完全覆盖
    if (root->l >= l && root->r <= r)
    {
        return root->min_val;
    }

    root->pushDown(); // 下传懒标记

    int mid = (root->l + root->r) / 2;
    int res = INF;
    if (l <= mid && root->left)
    {
        res = min(res, queryMin(root->left, l, r));
    }
    if (r > mid && root->right)
    {
        res = min(res, queryMin(root->right, l, r));
    }

    return res;
}

// 合并两棵线段树
Node *merge(Node *root1, Node *root2)
{
    if (!root1)
        return root2;
    if (!root2)
        return root1;

    // 确保区间一致
    if (root1->l != root2->l || root1->r != root2->r)
    {
        return NULL; // 错误，区间不一致
    }

    // 合并当前节点信息
    root1->sum += root2->sum;
    root1->max_val = max(root1->max_val, root2->max_val);
    root1->min_val = min(root1->min_val, root2->min_val);

    // 处理懒标记
    root1->pushDown();
    root2->pushDown();

    // 递归合并子树
    if (root1->left || root2->left)
    {
        root1->left = merge(root1->left, root2->left);
    }
    if (root1->right || root2->right)
    {
        root1->right = merge(root1->right, root2->right);
    }

    return root1;
}

// 释放线段树内存
void freeTree(Node *root)
{
    if (!root)
        return;
    freeTree(root->left);
    freeTree(root->right);
    delete root;
}

void solve()
{
    // 示例用法
    int n = 10;
    Node *segTree = build(1, n);

    // 单点更新
    update(segTree, 3, 5);
    update(segTree, 7, 10);

    // 区间更新
    updateRange(segTree, 2, 5, 3);

    // 查询
    cout << "Sum [1, 10]: " << querySum(segTree, 1, 10) << endl;
    cout << "Max [2, 8]: " << queryMax(segTree, 2, 8) << endl;
    cout << "Min [3, 6]: " << queryMin(segTree, 3, 6) << endl;

    // 创建另一棵线段树并合并
    Node *segTree2 = build(1, n);
    update(segTree2, 4, 8);
    update(segTree2, 6, 2);

    Node *mergedTree = merge(segTree, segTree2);
    cout << "Merged Sum [1, 10]: " << querySum(mergedTree, 1, 10) << endl;

    // 释放内存
    freeTree(mergedTree);
}

// 高精度整数类
class BigInteger
{
private:
    // 数字以十进制存储，个位在前
    vector<int> digits;
    // 符号位，true为负数
    bool negative;

    // 去除前导零
    void removeLeadingZeros()
    {
        while (digits.size() > 1 && digits.back() == 0)
        {
            digits.pop_back();
        }
        // 如果只剩0，确保符号为正
        if (digits.size() == 1 && digits[0] == 0)
        {
            negative = false;
        }
    }

    // 绝对值比较，不考虑符号
    static bool absLess(const BigInteger &a, const BigInteger &b)
    {
        if (a.digits.size() != b.digits.size())
        {
            return a.digits.size() < b.digits.size();
        }
        for (int i = a.digits.size() - 1; i >= 0; i--)
        {
            if (a.digits[i] != b.digits[i])
            {
                return a.digits[i] < b.digits[i];
            }
        }
        return false; // 相等
    }

    // 无符号加法
    static BigInteger absAdd(const BigInteger &a, const BigInteger &b)
    {
        BigInteger result;
        result.negative = false;

        const vector<int> &longer = a.digits.size() >= b.digits.size() ? a.digits : b.digits;
        const vector<int> &shorter = a.digits.size() < b.digits.size() ? a.digits : b.digits;

        result.digits.resize(longer.size() + 1, 0);

        for (size_t i = 0; i < shorter.size(); i++)
        {
            result.digits[i] += shorter[i];
        }

        for (size_t i = 0; i < longer.size(); i++)
        {
            result.digits[i] += longer[i];
        }

        // 处理进位
        for (size_t i = 0; i < result.digits.size() - 1; i++)
        {
            if (result.digits[i] >= 10)
            {
                result.digits[i + 1] += result.digits[i] / 10;
                result.digits[i] %= 10;
            }
        }

        result.removeLeadingZeros();
        return result;
    }

    // 无符号减法，假设a >= b
    static BigInteger absSub(const BigInteger &a, const BigInteger &b)
    {
        BigInteger result;
        result.negative = false;
        result.digits.resize(a.digits.size(), 0);

        for (size_t i = 0; i < a.digits.size(); i++)
        {
            result.digits[i] += a.digits[i];
        }

        for (size_t i = 0; i < b.digits.size(); i++)
        {
            result.digits[i] -= b.digits[i];
        }

        // 处理借位
        for (size_t i = 0; i < result.digits.size() - 1; i++)
        {
            if (result.digits[i] < 0)
            {
                result.digits[i] += 10;
                result.digits[i + 1]--;
            }
        }

        result.removeLeadingZeros();
        return result;
    }

public:
    // 默认构造函数
    BigInteger() : negative(false)
    {
        digits.push_back(0);
    }

    // 从整数构造
    BigInteger(long long num) : negative(false)
    {
        if (num < 0)
        {
            negative = true;
            num = -num;
        }

        if (num == 0)
        {
            digits.push_back(0);
        }
        else
        {
            while (num > 0)
            {
                digits.push_back(num % 10);
                num /= 10;
            }
        }
    }

    // 从字符串构造
    BigInteger(const string &str) : negative(false)
    {
        if (str.empty())
        {
            digits.push_back(0);
            return;
        }

        size_t start = 0;
        if (str[0] == '-')
        {
            negative = true;
            start = 1;
        }
        else if (str[0] == '+')
        {
            start = 1;
        }

        for (size_t i = str.size(); i > start; i--)
        {
            if (isdigit(str[i - 1]))
            {
                digits.push_back(str[i - 1] - '0');
            }
            else
            {
                throw invalid_argument("Invalid BigInteger string");
            }
        }

        removeLeadingZeros();
    }

    // 复制构造函数
    BigInteger(const BigInteger &other) : digits(other.digits), negative(other.negative) {}

    // 赋值运算符
    BigInteger &operator=(const BigInteger &other)
    {
        if (this != &other)
        {
            digits = other.digits;
            negative = other.negative;
        }
        return *this;
    }

    // 加法
    BigInteger operator+(const BigInteger &other) const
    {
        // 同号相加
        if (negative == other.negative)
        {
            BigInteger result = absAdd(*this, other);
            result.negative = negative;
            return result;
        }

        // 异号相加等于绝对值大的减去绝对值小的
        if (absLess(*this, other))
        {
            BigInteger result = absSub(other, *this);
            result.negative = other.negative;
            return result;
        }
        else
        {
            BigInteger result = absSub(*this, other);
            result.negative = negative;
            return result;
        }
    }

    // 减法
    BigInteger operator-(const BigInteger &other) const
    {
        // 相当于加上other的相反数
        BigInteger negOther = other;
        negOther.negative = !negOther.negative;
        return *this + negOther;
    }

    // 乘法
    BigInteger operator*(const BigInteger &other) const
    {
        if ((digits.size() == 1 && digits[0] == 0) ||
            (other.digits.size() == 1 && other.digits[0] == 0))
        {
            return BigInteger(); // 0乘以任何数都是0
        }

        // 结果的符号
        bool resultNegative = negative != other.negative;

        // 结果的位数最多是两个乘数位数之和
        vector<int> resultDigits(digits.size() + other.digits.size(), 0);

        // 逐位相乘
        for (size_t i = 0; i < digits.size(); i++)
        {
            for (size_t j = 0; j < other.digits.size(); j++)
            {
                resultDigits[i + j] += digits[i] * other.digits[j];
            }
        }

        // 处理进位
        for (size_t i = 0; i < resultDigits.size() - 1; i++)
        {
            resultDigits[i + 1] += resultDigits[i] / 10;
            resultDigits[i] %= 10;
        }

        BigInteger result;
        result.digits = resultDigits;
        result.negative = resultNegative;
        result.removeLeadingZeros();

        return result;
    }

    // 除法
    pair<BigInteger, BigInteger> divmod(const BigInteger &divisor) const
    {
        if (divisor.digits.size() == 1 && divisor.digits[0] == 0)
        {
            throw invalid_argument("Division by zero");
        }

        // 被除数是0，结果是0
        if (digits.size() == 1 && digits[0] == 0)
        {
            return make_pair(BigInteger(), BigInteger());
        }

        // 获取绝对值用于计算
        BigInteger absThis = *this;
        absThis.negative = false;
        BigInteger absDivisor = divisor;
        absDivisor.negative = false;

        // 如果被除数小于除数，商为0，余数为被除数
        if (absLess(absThis, absDivisor))
        {
            return make_pair(BigInteger(), *this);
        }

        // 结果的符号
        bool resultNegative = negative != divisor.negative;

        // 做除法计算
        BigInteger quotient;
        BigInteger remainder;

        // 从高位到低位做除法
        for (int i = absThis.digits.size() - 1; i >= 0; i--)
        {
            remainder = remainder * BigInteger(10) + BigInteger(absThis.digits[i]);

            // 寻找当前位的商
            int q = 0;
            BigInteger temp = absDivisor;
            while (!absLess(remainder, temp))
            {
                remainder = remainder - temp;
                q++;
            }

            quotient.digits.insert(quotient.digits.begin(), q);
        }

        quotient.negative = resultNegative;
        remainder.negative = negative; // 余数符号与被除数相同

        quotient.removeLeadingZeros();

        return make_pair(quotient, remainder);
    }

    // 除法运算符
    BigInteger operator/(const BigInteger &divisor) const
    {
        return divmod(divisor).first;
    }

    // 取模运算符
    BigInteger operator%(const BigInteger &divisor) const
    {
        return divmod(divisor).second;
    }

    // 求绝对值
    BigInteger abs() const
    {
        BigInteger result = *this;
        result.negative = false;
        return result;
    }

    // 比较运算符
    bool operator<(const BigInteger &other) const
    {
        if (negative != other.negative)
        {
            return negative;
        }

        if (negative)
        {
            return absLess(other, *this);
        }
        else
        {
            return absLess(*this, other);
        }
    }

    bool operator>(const BigInteger &other) const
    {
        return other < *this;
    }

    bool operator<=(const BigInteger &other) const
    {
        return !(other < *this);
    }

    bool operator>=(const BigInteger &other) const
    {
        return !(*this < other);
    }

    bool operator==(const BigInteger &other) const
    {
        return !(*this < other) && !(other < *this);
    }

    bool operator!=(const BigInteger &other) const
    {
        return *this < other || other < *this;
    }

    // 转换为字符串
    string toString() const
    {
        string result;
        if (negative)
        {
            result += "-";
        }

        for (int i = digits.size() - 1; i >= 0; i--)
        {
            result += digits[i] + '0';
        }

        return result;
    }

    // 重载输出运算符
    friend ostream &operator<<(ostream &os, const BigInteger &num)
    {
        os << num.toString();
        return os;
    }

    // 重载输入运算符
    friend istream &operator>>(istream &is, BigInteger &num)
    {
        string str;
        is >> str;
        num = BigInteger(str);
        return is;
    }
};

void solve()
{
    // 测试高精度计算
    string a, b;
    cin >> a >> b;

    BigInteger num1(a);
    BigInteger num2(b);

    cout << "加法: " << num1 + num2 << endl;
    cout << "减法: " << num1 - num2 << endl;
    cout << "乘法: " << num1 * num2 << endl;

    try
    {
        cout << "除法: " << num1 / num2 << endl;
        cout << "取模: " << num1 % num2 << endl;
    }
    catch (const invalid_argument &e)
    {
        cout << e.what() << endl;
    }

    cout << "num1的绝对值: " << num1.abs() << endl;
    cout << "num2的绝对值: " << num2.abs() << endl;

    cout << "比较结果: " << endl;
    cout << "num1 < num2: " << (num1 < num2) << endl;
    cout << "num1 > num2: " << (num1 > num2) << endl;
    cout << "num1 == num2: " << (num1 == num2) << endl;
}

// --------------------- 基础DP问题 ---------------------

// 01背包问题 - 每个物品最多选一次
int knapsack01(const vector<int> &weights, const vector<int> &values, int capacity)
{
    int n = weights.size();
    vector<int> dp(capacity + 1, 0);

    for (int i = 0; i < n; i++)
    {
        for (int j = capacity; j >= weights[i]; j--)
        {
            dp[j] = max(dp[j], dp[j - weights[i]] + values[i]);
        }
    }

    return dp[capacity];
}

// 完全背包问题 - 每个物品可以选无限次
int knapsackComplete(const vector<int> &weights, const vector<int> &values, int capacity)
{
    int n = weights.size();
    vector<int> dp(capacity + 1, 0);

    for (int i = 0; i < n; i++)
    {
        for (int j = weights[i]; j <= capacity; j++)
        {
            dp[j] = max(dp[j], dp[j - weights[i]] + values[i]);
        }
    }

    return dp[capacity];
}

// 多重背包问题 - 每个物品有特定数量限制
int knapsackMultiple(const vector<int> &weights, const vector<int> &values,
                     const vector<int> &counts, int capacity)
{
    int n = weights.size();
    vector<int> dp(capacity + 1, 0);

    for (int i = 0; i < n; i++)
    {
        // 二进制优化 - 将k个物品拆成二进制表示
        int w = weights[i], v = values[i], c = counts[i];
        for (int k = 1; k <= c; k *= 2)
        {
            for (int j = capacity; j >= k * w; j--)
            {
                dp[j] = max(dp[j], dp[j - k * w] + k * v);
            }
            c -= k;
        }

        if (c > 0)
        {
            for (int j = capacity; j >= c * w; j--)
            {
                dp[j] = max(dp[j], dp[j - c * w] + c * v);
            }
        }
    }

    return dp[capacity];
}

// 最长递增子序列 (LIS)
int longestIncreasingSubsequence(const vector<int> &nums)
{
    int n = nums.size();
    if (n == 0)
        return 0;

    vector<int> dp(n, 1);

    for (int i = 1; i < n; i++)
    {
        for (int j = 0; j < i; j++)
        {
            if (nums[i] > nums[j])
            {
                dp[i] = max(dp[i], dp[j] + 1);
            }
        }
    }

    return *max_element(dp.begin(), dp.end());
}

// 最长递增子序列优化版 (O(nlogn))
int longestIncreasingSubsequenceOptimized(const vector<int> &nums)
{
    int n = nums.size();
    if (n == 0)
        return 0;

    vector<int> tails;

    for (int num : nums)
    {
        auto it = lower_bound(tails.begin(), tails.end(), num);
        if (it == tails.end())
        {
            tails.push_back(num);
        }
        else
        {
            *it = num;
        }
    }

    return tails.size();
}

// 最长公共子序列 (LCS)
int longestCommonSubsequence(const string &text1, const string &text2)
{
    int m = text1.size(), n = text2.size();
    vector<vector<int>> dp(m + 1, vector<int>(n + 1, 0));

    for (int i = 1; i <= m; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            if (text1[i - 1] == text2[j - 1])
            {
                dp[i][j] = dp[i - 1][j - 1] + 1;
            }
            else
            {
                dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
            }
        }
    }

    return dp[m][n];
}

// 编辑距离
int editDistance(const string &word1, const string &word2)
{
    int m = word1.size(), n = word2.size();
    vector<vector<int>> dp(m + 1, vector<int>(n + 1, 0));

    for (int i = 0; i <= m; i++)
        dp[i][0] = i;
    for (int j = 0; j <= n; j++)
        dp[0][j] = j;

    for (int i = 1; i <= m; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            if (word1[i - 1] == word2[j - 1])
            {
                dp[i][j] = dp[i - 1][j - 1];
            }
            else
            {
                dp[i][j] = min({dp[i - 1][j - 1], dp[i - 1][j], dp[i][j - 1]}) + 1;
            }
        }
    }

    return dp[m][n];
}

// --------------------- 区间DP ---------------------

// 石子合并问题 - 求合并代价最小值
int mergeStones(const vector<int> &stones)
{
    int n = stones.size();
    if (n <= 1)
        return 0;

    // 前缀和加速区间求和
    vector<int> prefixSum(n + 1, 0);
    for (int i = 0; i < n; i++)
    {
        prefixSum[i + 1] = prefixSum[i] + stones[i];
    }

    // dp[i][j] 表示合并区间[i,j]的最小代价
    vector<vector<int>> dp(n, vector<int>(n, INF));

    // 初始化：单个石子无需合并
    for (int i = 0; i < n; i++)
    {
        dp[i][i] = 0;
    }

    // 按区间长度递推
    for (int len = 2; len <= n; len++)
    {
        for (int i = 0; i <= n - len; i++)
        {
            int j = i + len - 1;

            // 尝试在不同位置分割
            for (int k = i; k < j; k++)
            {
                dp[i][j] = min(dp[i][j], dp[i][k] + dp[k + 1][j] + prefixSum[j + 1] - prefixSum[i]);
            }
        }
    }

    return dp[0][n - 1];
}

// --------------------- 树形DP ---------------------

// 树的最大独立集 (在树上选择不相邻的节点使得权值和最大)
void dfsIndependentSet(int node, int parent, const vector<vector<int>> &tree,
                       const vector<int> &values, vector<vector<int>> &dp)
{
    for (int child : tree[node])
    {
        if (child != parent)
        {
            dfsIndependentSet(child, node, tree, values, dp);
            // dp[node][0] - 不选当前节点
            dp[node][0] += max(dp[child][0], dp[child][1]);
            // dp[node][1] - 选当前节点
            dp[node][1] += dp[child][0];
        }
    }
    dp[node][1] += values[node]; // 加上当前节点的权值
}

int maxIndependentSet(const vector<vector<int>> &tree, const vector<int> &values)
{
    int n = values.size();
    // dp[i][0] - 不选节点i的最大值, dp[i][1] - 选节点i的最大值
    vector<vector<int>> dp(n, vector<int>(2, 0));

    dfsIndependentSet(0, -1, tree, values, dp);
    return max(dp[0][0], dp[0][1]);
}

// --------------------- 状态压缩DP ---------------------

// 旅行商问题 (TSP)
int tsp(const vector<vector<int>> &dist)
{
    int n = dist.size();
    // dp[mask][i] 表示已经访问的城市集合为mask，当前在城市i的最短路径
    vector<vector<int>> dp(1 << n, vector<int>(n, INF));

    // 起点为城市0
    dp[1][0] = 0; // 只访问城市0的状态

    for (int mask = 1; mask < (1 << n); mask++)
    {
        for (int i = 0; i < n; i++)
        {
            if ((mask >> i) & 1)
            { // 城市i已访问
                for (int j = 0; j < n; j++)
                {
                    if ((mask >> j) & 1 && i != j)
                    { // 城市j也已访问
                        dp[mask][i] = min(dp[mask][i], dp[mask ^ (1 << i)][j] + dist[j][i]);
                    }
                }
            }
        }
    }

    // 所有城市都访问并回到起点
    int result = INF;
    for (int i = 1; i < n; i++)
    {
        if (dist[i][0] != INF)
        {
            result = min(result, dp[(1 << n) - 1][i] + dist[i][0]);
        }
    }

    return result;
}

// --------------------- 数位DP ---------------------

// 计算区间[l,r]中满足条件的数字个数
int digitDP(int l, int r)
{
    vector<int> digits;

    // 数位分解函数
    auto getDigits = [&](int num)
    {
        vector<int> result;
        while (num)
        {
            result.push_back(num % 10);
            num /= 10;
        }
        reverse(result.begin(), result.end());
        return result;
    };

    // DP函数，自行定义状态和转移方程
    function<int(int, bool, bool, int)> dp = [&](int pos, bool isLimit, bool isNum, int state)
    {
        // 实现特定问题的状态转移逻辑
        // pos: 当前处理到的位置
        // isLimit: 是否有上界限制
        // isNum: 前面是否已经有数字了
        // state: 问题相关的状态

        if (pos == digits.size())
        {
            return isNum ? 1 : 0; // 根据具体问题调整返回值
        }

        // 这里补充具体问题的状态转移逻辑

        return 0; // 占位返回
    };

    // 计算[0,r]的结果
    digits = getDigits(r);
    int right_result = dp(0, true, false, 0);

    // 计算[0,l-1]的结果
    digits = getDigits(l - 1);
    int left_result = dp(0, true, false, 0);

    // 返回区间结果
    return right_result - left_result;
}

// --------------------- 概率DP ---------------------

// 骰子问题 - 投掷n个骰子，点数和为target的概率
double diceProb(int n, int target)
{
    if (target < n || target > 6 * n)
        return 0.0;

    vector<vector<double>> dp(n + 1, vector<double>(6 * n + 1, 0.0));
    // 初始化：一个骰子
    for (int i = 1; i <= 6; i++)
    {
        dp[1][i] = 1.0 / 6.0;
    }

    for (int i = 2; i <= n; i++)
    {
        for (int j = i; j <= 6 * i; j++)
        {
            for (int k = 1; k <= 6 && k < j; k++)
            {
                dp[i][j] += dp[i - 1][j - k] * (1.0 / 6.0);
            }
        }
    }

    return dp[n][target];
}

// --------------------- 实用DP子问题 ---------------------

// 最大子序和 (Kadane算法)
int maxSubArray(const vector<int> &nums)
{
    int currMax = nums[0], globalMax = nums[0];

    for (int i = 1; i < nums.size(); i++)
    {
        currMax = max(nums[i], currMax + nums[i]);
        globalMax = max(globalMax, currMax);
    }

    return globalMax;
}

// 最大子矩阵和
int maxSubMatrix(const vector<vector<int>> &matrix)
{
    if (matrix.empty() || matrix[0].empty())
        return 0;

    int rows = matrix.size(), cols = matrix[0].size();
    int result = INT_MIN;

    for (int left = 0; left < cols; left++)
    {
        vector<int> tempSum(rows, 0);

        for (int right = left; right < cols; right++)
        {
            // 将二维问题转化为一维
            for (int i = 0; i < rows; i++)
            {
                tempSum[i] += matrix[i][right];
            }

            // 应用Kadane算法找一维最大子序和
            int kadaneMax = tempSum[0];
            int currMax = tempSum[0];

            for (int i = 1; i < rows; i++)
            {
                currMax = max(tempSum[i], currMax + tempSum[i]);
                kadaneMax = max(kadaneMax, currMax);
            }

            result = max(result, kadaneMax);
        }
    }

    return result;
}

// 最长回文子串
string longestPalindrome(const string &s)
{
    int n = s.size();
    if (n == 0)
        return "";

    vector<vector<bool>> dp(n, vector<bool>(n, false));
    int start = 0, maxLen = 1;

    // 所有长度为1的子串都是回文
    for (int i = 0; i < n; i++)
    {
        dp[i][i] = true;
    }

    // 检查长度为2的子串
    for (int i = 0; i < n - 1; i++)
    {
        if (s[i] == s[i + 1])
        {
            dp[i][i + 1] = true;
            start = i;
            maxLen = 2;
        }
    }

    // 检查长度大于2的子串
    for (int len = 3; len <= n; len++)
    {
        for (int i = 0; i <= n - len; i++)
        {
            int j = i + len - 1;
            if (s[i] == s[j] && dp[i + 1][j - 1])
            {
                dp[i][j] = true;
                start = i;
                maxLen = len;
            }
        }
    }

    return s.substr(start, maxLen);
}

// 矩阵链乘法
int matrixChainMultiplication(const vector<int> &dims)
{
    int n = dims.size() - 1;
    vector<vector<int>> dp(n, vector<int>(n, 0));

    for (int len = 2; len <= n; len++)
    {
        for (int i = 0; i <= n - len; i++)
        {
            int j = i + len - 1;
            dp[i][j] = INT_MAX;

            for (int k = i; k < j; k++)
            {
                dp[i][j] = min(dp[i][j], dp[i][k] + dp[k + 1][j] + dims[i] * dims[k + 1] * dims[j + 1]);
            }
        }
    }

    return dp[0][n - 1];
}