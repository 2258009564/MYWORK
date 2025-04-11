// #pragma GCC optimize(2)
#include <bits/stdc++.h>
using namespace std;
#define int long long
#define endl '\n'
#define all(x) (x).begin(), (x).end()

const int INF = 1e9;     // 无穷大
const int INFLL = 1e18;  // 长整型无穷大
const int MOD = 1e9 + 7; // 模数
const int N = 1e5 + 10;  // 数据范围

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

signed main()
{
    cin.tie(0)->ios::sync_with_stdio(0);
    cout << setiosflags(ios::fixed) << setprecision(2);
    int TT = 1;
    // cin >> TT;
    while (TT--)
    {
        solve();
    }
    return 0;
}