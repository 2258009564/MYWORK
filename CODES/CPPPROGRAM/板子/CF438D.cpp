/*
包含取模操作的线段树
给定一个长度为n的数组arr，实现如下三种操作，一共调用m次
操作 1 l r ：查询arr[l..r]的累加和
操作 2 l r x ：把arr[l..r]上每个数字对x取模
操作 3 k x ：把arr[k]上的数字设置为x
1<= n,m <= 10^5，操作1得到的结果，有可能超过int范围
*/

// #pragma GCC optimize(2)
#include <bits/stdc++.h>
using namespace std;
#define int long long
#define endl '\n'
#define all(x) (x).begin(), (x).end()

constexpr int MOD = 1e9 + 7;
// -9.2e18 ~ 9.2e18

const int N = 1e5 + 10;
vector<int> v(N), sum(N << 2), ch(N << 2), upd(N << 2), mmax(N << 2);

void lazy_upd(int i, int v, int n)
{
    ch[i] = v;
    upd[i] = 1;
    sum[i] = v * n;
    mmax[i] = v;
}

void up(int i)
{
    sum[i] = sum[i << 1] + sum[i << 1 | 1];
    mmax[i] = max(mmax[i << 1], mmax[i << 1 | 1]);
}

void down(int i, int ln, int rn)
{
    if (upd[i])
    {
        lazy_upd(i << 1, ch[i], ln);
        lazy_upd(i << 1 | 1, ch[i], rn);
        upd[i] = 0;
    }
}

void update_upd(int jobl, int jobr, int v, int l, int r, int i)
{
    if (jobl <= l and jobr >= r)
    {
        lazy_upd(i, v, r - l + 1);
        return;
    }

    auto mid = (l + r) >> 1;
    down(i, mid - l + 1, r - mid);
    if (jobl <= mid)
    {
        update_upd(jobl, jobr, v, l, mid, i << 1);
    }
    if (jobr >= mid + 1)
    {
        update_upd(jobl, jobr, v, mid + 1, r, i << 1 | 1);
    }

    up(i);
}

void update_mod(int jobl, int jobr, int mod, int l, int r, int i)
{
    // 是否完全包裹
    if (jobl <= l and jobr >= r)
    {
        // 是否不需要取模
        if (mmax[i] < mod)
        {
            return;
        }
    }

    // 现在的任务是 找到叶子节点 然后取模 取模之前是不是要先down下去

    // 如果本身是叶子节点
    if (l == r)
    {
        if (upd[i])
        {
            sum[i] = ch[i];
            mmax[i] = ch[i];
            upd[i] = 0;
        }

        // 取模
        sum[i] %= mod;
        mmax[i] %= mod;

        return;
    }

    // 现在不是叶子节点 所以正常递归
    auto mid = (l + r) >> 1;
    down(i, mid - l + 1, r - mid);

    if (jobl <= mid)
    {
        update_mod(jobl, jobr, mod, l, mid, i << 1);
    }
    if (jobr >= mid + 1)
    {
        update_mod(jobl, jobr, mod, mid + 1, r, i << 1 | 1);
    }

    up(i);
}

int query(int jobl, int jobr, int l, int r, int i)
{
    if (jobl <= l and jobr >= r)
    {
        return sum[i];
    }

    int ans = 0;
    auto mid = (l + r) >> 1;
    down(i, mid - l + 1, r - mid);

    if (jobl <= mid)
    {
        ans += query(jobl, jobr, l, mid, i << 1);
    }
    if (jobr >= mid + 1)
    {
        ans += query(jobl, jobr, mid + 1, r, i << 1 | 1);
    }
    return ans;
}

void build(int l, int r, int i)
{
    upd[i] = 0;
    if (l == r)
    {
        sum[i] = mmax[i] = v[l];
        return;
    }
    auto mid = (l + r) >> 1;
    build(l, mid, i << 1);
    build(mid + 1, r, i << 1 | 1);

    up(i);
}

void solve()
{
    int n, q;
    cin >> n >> q;
    for (int i = 1; i <= n; i++)
    {
        cin >> v[i];
    }

    build(1, n, 1);
    int op, l, r, k, x;
    while (q--)
    {
        cin >> op;
        if (op == 1)
        {
            cin >> l >> r;
            cout << query(l, r, 1, n, 1) << endl;
        }
        else if (op == 2)
        {
            cin >> l >> r >> x;
            update_mod(l, r, x, 1, n, 1);
        }
        else if (op == 3)
        {
            cin >> k >> x;
            update_upd(k, k, x, 1, n, 1);
        }
    }
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
        // cout << endl;
    }
}