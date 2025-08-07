// #pragma GCC optimize(2)
#include <bits/stdc++.h>
using namespace std;
#define int long long
#define endl '\n'
#define all(x) (x).begin(), (x).end()

// -9.2e18 ~ 9.2e18

int N = 1e5 + 10, MOD;

int add(int a, int b)
{
    return (a % MOD + b % MOD) % MOD;
}

int mul(int a, int b)
{
    return (a % MOD * b % MOD) % MOD;
}

vector<int> v(N), sum(N << 2), ad(N << 2), mu(N << 2);

void lazy(int i, int v, int n, int op) // 需要修改
{
    if (op == 1)
    {
        sum[i] = mul(sum[i], v);
        ad[i] = mul(ad[i], v);
        mu[i] = mul(mu[i], v); // 更新乘法标记
    }
    if (op == 2)
    {
        sum[i] = add(sum[i], mul(v, n));
        ad[i] = add(ad[i], v);
    }
}

void up(int i)
{
    sum[i] = add(sum[i << 1], sum[i << 1 | 1]);
}

void down(int i, int ln, int rn) // 需要修改
{
    // 先传播乘法标记
    if (mu[i] != 1)
    {
        lazy(i << 1, mu[i], ln, 1);
        lazy(i << 1 | 1, mu[i], rn, 1);
        mu[i] = 1;
    }

    // 再传播加法标记
    if (ad[i] != 0)
    {
        lazy(i << 1, ad[i], ln, 2);
        lazy(i << 1 | 1, ad[i], rn, 2);
        ad[i] = 0;
    }
}

void update(int jobl, int jobr, int jobv, int op, int l, int r, int i)
{
    if (jobl <= l and jobr >= r)
    {
        lazy(i, jobv, r - l + 1, op);
        return;
    }

    int mid = (l + r) >> 1;
    down(i, mid - l + 1, r - mid);

    if (jobl <= mid)
    {
        update(jobl, jobr, jobv, op, l, mid, i << 1);
    }
    if (jobr >= mid + 1)
    {
        update(jobl, jobr, jobv, op, mid + 1, r, i << 1 | 1);
    }

    up(i);
}

int getmax(int jobl, int jobr, int l, int r, int i)
{
    if (jobl <= l and jobr >= r)
    {
        return sum[i] % MOD;
    }

    int mid = (l + r) >> 1;
    down(i, mid - l + 1, r - mid);
    int ans = 0;
    if (jobl <= mid)
    {
        ans = add(ans, getmax(jobl, jobr, l, mid, i << 1));
    }
    if (jobr >= mid + 1)
    {
        ans = add(ans, getmax(jobl, jobr, mid + 1, r, i << 1 | 1));
    }

    return ans;
}

void build(int l, int r, int i) // 需要修改
{
    ad[i] = 0;
    mu[i] = 1; // 乘法标记初始为1

    if (l == r)
    {
        sum[i] = v[l];
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
    cin >> n >> q >> MOD;
    for (int i = 1; i <= n; i++)
    {
        cin >> v[i];
    }

    build(1, n, 1);

    int op, l, r, val;
    while (q--)
    {
        cin >> op >> l >> r;
        if (op == 3)
        {
            cout << getmax(l, r, 1, n, 1) << endl;
        }
        else
        {
            cin >> val;
            update(l, r, val, op, 1, n, 1);
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