// #pragma GCC optimize(2)
#include <bits/stdc++.h>
using namespace std;
#define int long long
#define endl '\n'
#define all(x) (x).begin(), (x).end()

constexpr int MOD = 1e9 + 7;
// -9.2e18 ~ 9.2e18

int maxi(int l, int r, int i)
{
    if (l == r)
    {
        return i;
    }

    auto m = l + (r - l) / 2;
    return max(maxi(l, m, i << 1), maxi(m + 1, r, i << 1 | 1));
}

vector<int> v;
// 线段树 begin

vector<int> sum; // 范围累加和（查询信息）
vector<int> ad;  // 范围上每个数字增加值（懒信息）

// 懒更新
void lazy(int i, int v, int tot)
{
    sum[i] += tot * v;
    ad[i] += v;
}

// 往上更新sum
void up(int i)
{
    sum[i] = sum[i << 1] + sum[i << 1 | 1];
}

// 往下分发懒标记
void down(int i, int ltot, int rtot)
{
    if (ad[i])
    {
        lazy(i << 1, ad[i], ltot);
        lazy(i << 1 | 1, ad[i], rtot);
        ad[i] = 0;
    }
}

// build
void build(int l, int r, int i)
{
    if (l == r)
    {
        sum[i] = v[l];
    }
    else
    {
        auto m = l + (r - l) / 2;
        build(l, m, i << 1);
        build(m + 1, r, i << 1 | 1);
        up(i);
    }
}

int getmax(int jobl, int jobr, int l, int r, int i)
{
    // 如果完全包含
    if (jobl <= l and jobr >= r)
    {
        return sum[i];
    }

    // 并非完全包含 判断一下哪部分需要
    int ans = 0;
    auto mid = (l + r) >> 1;

    down(i, mid - l + 1, r - mid);

    if (jobl <= mid)
    {
        ans += getmax(jobl, jobr, l, mid, i << 1); // 递归查询左子树
    }
    if (jobr >= mid + 1)
    {
        ans += getmax(jobl, jobr, mid + 1, r, i << 1 | 1);
    }

    return ans;
}

void add(int jobl, int jobr, int jobv, int l, int r, int i)
{
    if (jobl <= l and jobr >= r)
    {
        lazy(i, jobv, r - l + 1);
        return;
    }

    // 划分成两个区间 [l, mid] [mid + 1, r]
    int mid = l + (r - l) >> 1;

    // 下发懒标记
    down(i, mid - l + 1, r - mid);

    if (jobl <= mid)
    {
        add(jobl, jobr, jobv, l, mid, i << 1);
    }
    if (jobr >= mid + 1)
    {
        add(jobl, jobr, jobv, mid + 1, r, i << 1 | 1);
    }

    // 汇总自己的信息
    up(i);
}

void solve()
{
    int n;
    cin >> n;
    sum.resize(n << 2);
    ad.resize(n << 2);
    v.resize(n + 1);
    for (int i = 1; i <= n; i++)
    {
        cin >> v[i];
    }
    build(1, n, 1);
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