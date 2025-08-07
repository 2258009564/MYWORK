/*
操作任务：给定区间 [l, r] 把区间内所有数字开方
询问任务：给定区间 [l, r] 统计sum
数字num <= 1e12

注意到1e12 变成1 最多也只需要6次
一共有n个节点 那么需要的操作总代价是 6 * n * logn
操作次数 * 节点总数 * 树高
假设一共操作 q 次 复杂度是 均摊 logn

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
vector<int> v(N), sum(N << 2), mmax(N << 2);

void up(int i)
{
    mmax[i] = max(mmax[i << 1], mmax[i << 1 | 1]);
    sum[i] = sum[i << 1] + sum[i << 1 | 1];
}

void update(int jobl, int jobr, int l, int r, int i)
{
    if (jobl <= l and jobr >= r and mmax[i] == 1)
    {
        return;
    }

    if (l == r)
    {
        mmax[i] = sqrt(mmax[i]);
        sum[i] = sqrt(sum[i]);
        return;
    }

    auto mid = (l + r) >> 1;
    // [l, mid] [mid + 1, r]
    if (jobl <= mid)
    {
        update(jobl, jobr, l, mid, i << 1);
    }
    if (jobr >= mid + 1)
    {
        update(jobl, jobr, mid + 1, r, i << 1 | 1);
    }

    up(i);
}

int query(int jobl, int jobr, int l, int r, int i)
{
    if (jobl <= l and jobr >= r)
    {
        return sum[i];
    }

    auto mid = (l + r) >> 1;
    int ans = 0;
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
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        cin >> v[i];
    }
    build(1, n, 1);
    cin >> q;
    int op, l, r, k;
    while (q--)
    {
        cin >> op >> l >> r;
        if (l > r)
        {
            swap(l, r);
        }
        if (op == 0)
        {
            update(l, r, 1, n, 1);
        }
        else
        {
            cout << query(l, r, 1, n, 1) << endl;
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