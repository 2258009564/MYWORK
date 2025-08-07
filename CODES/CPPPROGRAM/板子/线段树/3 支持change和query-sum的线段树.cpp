// #pragma GCC optimize(2)
#include <bits/stdc++.h>
using namespace std;
#define int long long
#define endl '\n'
#define all(x) (x).begin(), (x).end()

constexpr int MOD = 1e9 + 7;
// -9.2e18 ~ 9.2e18

vector<int> v, sum, ch, upd;

// 懒更新 所有需要更改的都在这里更新
void lazy(int i, int v, int n)
{
    sum[i] = n * v;
    ch[i] = v;
    upd[i] = 1;
}

void up(int i)
{
    sum[i] = sum[i << 1] + sum[i << 1 | 1];
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

void change(int jobl, int jobr, int jobv, int l, int r, int i)
{
    if (jobl <= l and jobr >= r)
    {
        lazy(i, jobv, r - l + 1);
        return;
    }

    int mid = (l + r) >> 1;
    down(i, mid - l + 1, r - mid);

    // [l, mid] [mid + 1, r]
    if (jobl <= mid)
    {
        change(jobl, jobr, jobv, l, mid, i << 1);
    }
    if (jobr >= mid + 1)
    {
        change(jobl, jobr, jobv, mid + 1, r, i << 1 | 1);
    }

    up(i);
}

int getmax(int jobl, int jobr, int l, int r, int i)
{
    if (jobl <= l and jobr >= r)
    {
        return sum[i];
    }

    int mid = (l + r) >> 1;
    down(i, mid - l + 1, r - mid);

    // [l, mid] [mid + 1, r]
    int ans = 0;
    if (jobl <= mid)
    {
        ans += getmax(jobl, jobr, l, mid, i << 1);
    }
    if (jobr >= mid + 1)
    {
        ans += getmax(jobl, jobr, mid + 1, r, i << 1 | 1);
    }

    return ans;
}

void build(int l, int r, int i)
{
    if (l == r)
    {
        sum[i] = v[l];
        return;
    }

    int mid = (l + r) >> 1;
    build(l, mid, i << 1);
    build(mid + 1, r, i << 1 | 1);

    up(i);
}

void solve()
{
    int n, q;
    cin >> n >> q;

    v.resize(n + 1);
    sum.resize(n << 2);
    ch = upd = sum;

    for (int i = 1; i <= n; i++)
    {
        cin >> v[i];
    }

    build(1, n, 1);

    int op, l, r, v;
    while (q--)
    {
        cin >> op >> l >> r;
        if (op == 1)
        {
            cin >> v;
            change(l, r, v, 1, n, 1);
        }
        else
        {
            cout << getmax(l, r, 1, n, 1) << endl;
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