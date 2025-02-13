#pragma GCC optimize(2)
#include <bits/stdc++.h>
using namespace std;
#define int long long
#define endl '\n'

const int MAX_N = 1e5 + 5;
const int INF = 1e9;

vector<int> tree[4 * MAX_N]; // 线段树

// 构建线段树，每个节点存储一个排序后的区间元素
void build(int node, int start, int end, const vector<int> &arr)
{
    if (start == end)
    {
        tree[node].push_back(arr[start]);
    }
    else
    {
        int mid = (start + end) / 2;
        build(2 * node, start, mid, arr);
        build(2 * node + 1, mid + 1, end, arr);
        tree[node].resize(end - start + 1);
        merge(tree[2 * node].begin(), tree[2 * node].end(),
              tree[2 * node + 1].begin(), tree[2 * node + 1].end(),
              tree[node].begin());
    }
}

// 查询区间 [L, R] 内的所有元素
vector<int> query(int node, int start, int end, int L, int R)
{
    if (R < start || end < L)
    {
        return {}; // 不在区间内
    }
    if (L <= start && end <= R)
    {
        return tree[node]; // 直接返回当前节点的元素
    }

    int mid = (start + end) / 2;
    vector<int> leftResult = query(2 * node, start, mid, L, R);
    vector<int> rightResult = query(2 * node + 1, mid + 1, end, L, R);

    // 合并左右区间
    vector<int> result;
    merge(leftResult.begin(), leftResult.end(), rightResult.begin(), rightResult.end(), back_inserter(result));
    return result;
}

void solve()
{
    int n, m;
    cin >> n >> m;
    vector<int> p(n);
    for (int i = 0; i < n; ++i)
    {
        cin >> p[i];
    }

    build(1, 0, n - 1, p);

    // 处理每个查询
    while (m--)
    {
        int l, r, c;
        cin >> l >> r >> c;
        --l, --r, --c; // 转换为 0-based 索引

        // 获取区间 [l, r] 内的元素
        vector<int> sorted_subarray = query(1, 0, n - 1, l, r);

        // 找到 p[c] 在排序后的子数组中的位置
        int pos = lower_bound(sorted_subarray.begin(), sorted_subarray.end(), p[c]) - sorted_subarray.begin() + 1;

        // 输出查询结果
        cout << pos << endl;
    }
}

signed main()
{
    cin.tie(nullptr)->ios::sync_with_stdio(false);
    cout << setiosflags(ios::fixed) << setprecision(2);

    int TT = 1;
    cin >> TT;
    while (TT--)
    {
        solve();
        cout << endl;
    }
}
