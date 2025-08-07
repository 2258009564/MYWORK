// #pragma GCC optimize(2)
#include <bits/stdc++.h>
using namespace std;
#define int long long
#define endl '\n'
#define all(x) (x).begin(), (x).end()

constexpr int MOD = 1e9 + 7;
// -9.2e18 ~ 9.2e18

const int N = 1e5;
vector<int> v(N), mmax(N << 2), ad = mmax;

void lazy(int i, int v, int n) 
{
    mmax[i] += v;
    ad[i] += v;
}

void up(int i)
{
    mmax[i] = max(mmax[i << 1], mmax[i << 1 | 1]);
}

void down(int i, int ln, int rn)
{
    if (ad[i])
    {
        lazy(i << 1, ad[i], ln);
        lazy(i << 1 | 1, ad[i], rn);
        ad[i] = 0;
    }
}

void update(int jobl, int jobr, int jobv, int l, int r, int i)
{
    if (jobl <= l and jobr >= r)
    {
        lazy(i, jobv, r - l + 1);
        return;
    }

    auto mid = (l + r) >> 1;
    down(i, mid - l + 1, r - mid);

    if (jobl <= mid)
    {
        update(jobl, jobr, jobv, l, mid, i << 1);
    }
    if (jobr >= mid + 1)
    {
        update(jobl, jobr, jobv, mid + 1, r, i << 1 | 1);
    }

    up(i);
}

int getmax(int jobl, int jobr, int l, int r, int i)
{
    if (jobl <= l and jobr >= r)
    {
        return mmax[i];
    }

    auto mid = (l + r) >> 1;
    down(i, mid - l + 1, r - mid);
    int ans = LLONG_MIN;
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
    if (l == r)
    {
        mmax[i] = v[l];
        return;
    }

    auto mid = (l + r) >> 1;
    build(l, mid, i << 1);
    build(mid + 1, r, i << 1 | 1);

    up(i);
    ad[i] = 0;
}

void solve()
{
    int n;
    cin >> n;

    for (int i = 1; i <= n; i++)
    {
        cin >> v[i];
    }

    build(1, n, 1);

    int op, l, r, val;
    int q;
    cin >> q;
    while (q--)
    {
        cin >> op >> l >> r;
        if (op == 1)
        {
            cin >> val;
            update(l, r, val, 1, n, 1);
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