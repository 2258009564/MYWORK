// #pragma GCC optimize(2)
#include <bits/stdc++.h>
using namespace std;
#define int long long
#define endl '\n'
#define all(x) (x).begin(), (x).end()

constexpr int MOD = 1e9 + 7;
// -9.2e18 ~ 9.2e18

int n, q;
const int N = 1e5 + 10;
vector<int> v(N), sum(N << 2), ch(N << 2), upd(N << 2);

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

void update(int jobl, int jobr, int v, int l, int r, int i)
{
    if (jobl <= l and jobr >= r)
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

int query(int jobl, int jobr, int l, int r, int i)
{
    if (jobl <= l and jobr >= r)
    {
        return sum[i];
    }
    auto mid = (l + r) >> 1;
    down(i, mid - l + 1, r - mid);

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
    upd[i] = 0;
    if (l == r)
    {
        sum[i] = 0;
        return;
    }
    auto mid = (l + r) >> 1;
    build(l, mid, i << 1);
    build(mid + 1, r, i << 1 | 1);
    up(i);
}

int findzero(int l, int r, int k) // 查询 l 开始 的 第k个0
{
    int ans = l;
    while (l <= r)
    {

        auto mid = (l + r) >> 1;
        auto lf = mid - l + 1 - query(l, mid, 1, n, 1);
        if (lf >= k)
        {
            ans = mid;
            r = mid - 1;
        }
        else
        {
            l = mid + 1;
            k -= lf;
        }
    }
    return ans;
}

pair<int, int> insert(int l, int k)
{
    int tot = n - l + 1 - query(l, n, 1, n, 1);
    pair<int, int> pr = {findzero(l, n, 1), findzero(l, n, min(k, tot))};

    auto [st, end] = pr;
    update(st, end, 1, 1, n, 1);
    return pr;
}

void solve()
{
    cin >> n >> q;

    build(1, n, 1);
    int op, l, r, k;
    while (q--)
    {
        cin >> op >> l;
        if (op == 1)
        {
            l++;
            // 操作1 从l开始 插k朵花
            cin >> k;
            auto tot = query(l, n, 1, n, 1);
            if (tot == n - l + 1)
            {
                cout << "Can not put any one." << endl;
                continue;
            }

            // 这个地方怎么插
            auto [ll, rr] = insert(l, k);
            cout << --ll << ' ' << --rr << endl;
        }
        else
        {
            // 操作2 拔出l到r的花 返回拔了多少朵
            cin >> r;
            l++, r++;
            cout << query(l, r, 1, n, 1) << endl;
            update(l, r, 0, 1, n, 1);
        }
    }
}

signed main()
{
    cin.tie(0)->ios::sync_with_stdio(0);
    cout << setiosflags(ios::fixed) << setprecision(2);
    int TT = 1;
    cin >> TT;
    while (TT--)
    {
        solve();
        cout << endl;
    }
}