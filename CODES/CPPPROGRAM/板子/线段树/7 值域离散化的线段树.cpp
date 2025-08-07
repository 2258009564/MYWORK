// #pragma GCC optimize(2)
#include <bits/stdc++.h>
using namespace std;
#define int long long
#define endl '\n'
#define all(x) (x).begin(), (x).end()

constexpr int MOD = 1e9 + 7;
// -9.2e18 ~ 9.2e18

/*
俄罗斯方块游戏
q次询问 告诉你起点和边长
问最后整个游戏到达的最大高度
*/

/*
要让区间内的每一个数字都变成最大值
也就是 维护区间和 区间赋值
查询区间最大值
*/

int N = 1e5 + 10;
vector<int> v(N), mmax(N << 2), ch(N << 2), upd = ch;

void lazy(int i, int v, int n)
{
    upd[i] = 1;
    mmax[i] = v;
    ch[i] = v;
}

void up(int i)
{
    mmax[i] = max(mmax[i << 1], mmax[i << 1 | 1]);
}

void down(int i, int ln, int rn)
{
    if (upd[i])
    {
        lazy(i << 1, ch[i], ln);
        lazy(i << 1 | 1, ch[i], rn);
        upd[i] = 0;
    }
}

void update(int jobl, int jobr, int v, int l, int r, int i)
{
    if (jobl <= l && jobr >= r)
    {
        lazy(i, v, r - l + 1);
        return;
    }

    auto mid = (l + r) >> 1;
    down(i, mid - l + 1, r - mid);

    if (jobl <= mid)
    {
        update(jobl, jobr, v, l, mid, i << 1);
    }
    if (jobr >= mid + 1)
    {
        update(jobl, jobr, v, mid + 1, r, i << 1 | 1);
    }

    up(i);
}

int getmax(int jobl, int jobr, int l, int r, int i)
{
    if (jobl <= l && jobr >= r)
    {
        return mmax[i];
    }

    auto mid = (l + r) >> 1;
    down(i, mid - l + 1, r - mid);
    int ans = 0;
    if (jobl <= mid)
    {
        ans = max(ans, getmax(jobl, jobr, l, mid, i << 1));
    }
    if (jobr >= mid + 1)
    {
        ans = max(ans, getmax(jobl, jobr, mid + 1, r, i << 1 | 1));
    }
    return ans;
}

void build(int l, int r, int i)
{
    ch[i] = 0;
    upd[i] = 0;
    if (l == r)
    {
        mmax[i] = v[l];
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
    build(1, n, 1);
    while (q--)
    {
        int l, len;
        cin >> l >> len;
        update(l, l + len - 1, getmax(l, l + len - 1, 1, n, 1) + len, 1, n, 1);
    }

    cout << getmax(1, n, 1, n, 1);
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