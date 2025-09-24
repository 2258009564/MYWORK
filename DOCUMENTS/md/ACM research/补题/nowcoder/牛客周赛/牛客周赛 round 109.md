alisa为了督促自己学习所以写点题解，如果能帮到补题的你就再好不过了。
### 头文件参考
```cpp
#include <bits/stdc++.h>
using namespace std;
#define int long long
#define endl '\n'
#define all(x) (x).begin(), (x).end()
```

> pbds
```cpp
// #pragma GCC optimize(2)
#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

using namespace std;
using namespace __gnu_pbds;

#define int long long
#define endl '\n'
#define all(x) (x).begin(), (x).end()

// 支持重复元素的 multiset
typedef tree<int, null_type, less_equal<int>, rb_tree_tag, tree_order_statistics_node_update> ordered_multiset;
```
### A
给两对坐标（第三对是 $(0, 0)$ ）判断能否构成直角三角形。
三条边算出来，应用勾股定理判断即可。
```cpp
void solve()
{
    int x1, y1, x2, y2;
    cin >> x1 >> y1 >> x2 >> y2;
    vector<int> v;
    v.emplace_back(x1 * x1 + y1 * y1);
    v.emplace_back(x2 * x2 + y2 * y2);
    v.emplace_back((x1 - x2) * (x1 - x2) + (y1 - y2) * (y1 - y2));
    sort(all(v));
    cout << ((v[0] + v[1] == v[2]) ? "Yes" : "No");
}
```

### B
给一串在x轴的点，一串在y轴的点，问有多少对点满足**欧几里得距离**=1。
数据范围太小了，直接记录下所有的点，排序后枚举比较就行。
```cpp
void solve()
{
    int n;
    cin >> n;
    vector<int> X, Y;
    for (int i = 1; i <= n; i++)
    {
        int x, y;
        cin >> x >> y;
        if (x == 0)
        {
            Y.emplace_back(y);
        }
        if (y == 0)
        {
            X.emplace_back(x);
        }
        // 为什么不是 if else 的结构？因为可能存在(0, 0)
    }

    sort(all(X));
    sort(all(Y));
    int ans = 0;
    for (int i = 0; i + 1 < X.size(); i++)
    {
        ans += (X[i + 1] - X[i] == 1);
    }
    for (int i = 0; i + 1 < Y.size(); i++)
    {
        ans += (Y[i + 1] - Y[i] == 1);
    }
    cout << ans;
}
```

### C
给定两个不重合的整点，要求构造一个新的点C 使得面积为正整数。
如果两个点的x坐标相等（在一条竖线上） 那新的点取$(x1 + 2, y1)$ 即可；
如果两个点的y坐标相等，新的点取$(x1, y1 + 2)$即可；
如果都不相等，以上两种方式任选即可。
```cpp
void solve()
{
    int x1, y1, x2, y2;
    cin >> x1 >> y1 >> x2 >> y2;

    int dx = x2 - x1;
    if (dx == 0)
    {
        cout << x1 + 2 << ' ' << y1;
    }
    else
    {
        cout << x1 << ' ' << y1 + 2;
    }
}
```

### D
由于x, y的范围太大，考虑使用离散化，本题中直接使用map即可。
对每一个棋盘格子判断马能打到几个兵太复杂，一种常见的优化策略是：对每一个小兵，判断什么位置的马 能够一步打到他 对应 $mp[x][y]++;$ 
最后遍历mp找出最大值即可。
```cpp
void solve()
{
    int n;
    cin >> n;
    map<int, map<int, int>> mp;
    map<int, map<int, int>> used;
    for (int i = 1; i <= n; i++)
    {
        int x, y;
        cin >> x >> y;
        used[x][y]++;
        for (auto [dx, dy] : vector<pair<int, int>>{{2, 1}, {1, 2}, {-1, 2}, {2, -1}, {-1, -2}, {-2, -1}, {1, -2}, {-2, 1}})
        {
            if (x + dx > 0 and y + dy > 0)
            {
                mp[x + dx][y + dy]++;
            }
        }
    }

    int ans = -1;
    int x, y;
    for (auto [curx, mmp] : mp)
    {
        for (auto [cury, val] : mmp)
        {
            if (used[curx][cury])
            {
                continue;
            }
            if (val > ans)
            {
                ans = val;
                x = curx, y = cury;
            }
        }
    }
    cout << x << ' ' << y;
}
```

### E
> 如果已经知道有四条边，两两组合可以形成一个矩形，应该怎么统计答案呢

我们可以使用组合数 $C(4, 2)$ 即从四条边随便选两条，选出的两条有可能重复，所以对应的计算为 $ans += 4*(4-1)/2$ 

现在问题就转变成了，对于给定的这些点，如何高效的统计合法边的数量？
首先，我们通过上题类似的离散化过程 用map记录每一个点 $mp[x][y]$ 
对于每一个横坐标x 我们事先统计位于该横坐标x下的所有y 判断是否存在 $mp[x+1][y]$ 
如果存在，那么就建立了一条 $\{x, x+1\}$  的连边 我们把连边数量记录下来，应用上面的公式统计即可。

在实现上，还存在一个问题，正方形会被记录两次。对于这个问题 我们枚举所有点进行暴力统计，通过容斥原理可以知道，每存在一个这样的点，我们的答案对应减一

```cpp
void solve()
{
    int n;
    cin >> n;
    vector<pair<int, int>> v(n);
    map<int, map<int, int>> mp;
    map<int, vector<int>> X, Y;

    for (int i = 0; i < n; i++)
    {
        int x, y;
        cin >> x >> y;
        v[i] = {x, y};
        mp[x][y] = 1;
        X[x].emplace_back(y);
        Y[y].emplace_back(x);
    }

    map<int, int> cnt1, cnt2;
    for (auto [u, v] : X)
    {
        for (auto vv : v)
        {
            if (mp[u + 1][vv])
            {
                cnt1[u]++;
            }
        }
    }
    for (auto [u, v] : Y)
    {
        for (auto vv : v)
        {
            if (mp[vv][u + 1])
            {
                cnt2[u]++;
            }
        }
    }

    int ans = 0;
    for (auto [_, c] : cnt1)
    {
        ans += c * (c - 1) / 2;
    }
    for (auto [_, c] : cnt2)
    {
        ans += c * (c - 1) / 2;
    }

    sort(all(v));
    for (auto [x, y] : v)
    {
        if (mp[x + 1][y] and mp[x + 1][y + 1] and mp[x][y + 1])
        {
            ans--;
        }
    }
    cout << ans;
}
```

### F
一个好点需要同时满足 $y-x<k_1, y+x<k_2$ ，对于这样的问题，一个经典的trick是对一个权重排序，比较另一个权重。
在本题中，不妨记录 $y-x=A, y+x=B$ 。我们可以采用排序并遍历 $A$ 和 $k_1$ ，在遍历 $k_{1}$ 的过程中，动态往一个数据结构中加入所有满足 $A<k_1$ 的 $B$ ，等到这个步骤执行完，实际上 $y-x<k_1$ 的条件已经得到满足，我们在该结构中查询所有满足 $B<k_2$ 的 $B$  的数量即可。这样两个条件都能得到满足，所以答案是合理的。
在实现上，我们需要一个高效的单点更新值，区间查询和的数据结构，可以考虑gnu提供的平衡树 或者树状数组/线段树。需要注意的是，由于$B, k_2$ 的值太多，我们需要首先统计所有的 $B, k_2$ 然后离散化处理。
下面分别给出线段树版本和 $pbds::ordered_{}multiset$ 版本
> 线段树版本
```cpp
// #pragma GCC optimize(2)
#include <bits/stdc++.h>
using namespace std;
#define int long long
#define endl '\n'
#define all(x) (x).begin(), (x).end()

constexpr int MOD = 1e9 + 7;
// -9.2e18 ~ 9.2e18

const int N = 1e6;
vector<int> sum(N << 2), ad(N << 2);
#define mid ((l + r) >> 1)

void lazy(int i, int v, int n)
{
    sum[i] += v * n;
    ad[i] += v;
}

void up(int i)
{
    sum[i] = sum[i << 1] + sum[i << 1 | 1];
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

void update(int jobl, int jobr, int v, int l, int r, int i)
{
    if (jobl <= l and jobr >= r)
    {
        lazy(i, v, r - l + 1);
        return;
    }
    down(i, mid - l + 1, r - mid);
    if (jobl <= mid)
    {
        update(jobl, jobr, v, l, mid, i << 1);
    }
    if (jobr > mid)
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

    down(i, mid - l + 1, r - mid);
    int ans = 0;
    if (jobl <= mid)
    {
        ans += query(jobl, jobr, l, mid, i << 1);
    }
    if (jobr > mid)
    {
        ans += query(jobl, jobr, mid + 1, r, i << 1 | 1);
    }
    return ans;
}

void build(int l, int r, int i)
{
    ad[i] = 0;
    if (l == r)
    {
        sum[i] = 0;
        return;
    }

    build(l, mid, i << 1);
    build(mid + 1, r, i << 1 | 1);
    up(i);
}

void solve()
{
    int n, q;
    cin >> n >> q;

    /*
    记y-x=A, y+x=B
    我们要让 A<k1的同时B<k2
    这是一个很典的偏序查找问题
    我们可以对k1和A排序 遍历k1 对所有满足A<k1的{A,B} 加入B到线段树中
    然后logn查找满足k2>B的所有B 记录答案
    */

    vector<pair<int, int>> v(n);
    for (int i = 0; i < n; i++)
    {
        cin >> v[i].first >> v[i].second;
    }

    struct datas
    {
        int k1, k2, idx;
    };

    vector<datas> d(q);
    for (int i = 0; i < q; i++)
    {
        cin >> d[i].k1 >> d[i].k2;
        d[i].idx = i + 1;
    }

    vector<pair<int, int>> vv;
    for (auto [x, y] : v)
    {
        vv.emplace_back(y - x, y + x);
    }

    sort(all(vv));
    sort(all(d), [](auto a, auto b)
         { return a.k1 < b.k1; });

    // 需要先收集所有的B
    vector<int> itob;
    itob.emplace_back(LLONG_MIN);
    for (auto [_, B] : vv)
    {
        itob.emplace_back(B);
    }
    for (int i = 0; i < q; i++)
    {
        itob.emplace_back(d[i].k2);
    }
    sort(all(itob));
    itob.erase(unique(all(itob)), itob.end());

    // itob是1-based
    auto nn = itob.size() + 10;
    build(1, nn, 1);

    int idx = 0;
    vector<int> ans(q + 1);
    for (int i = 0; i < q; i++)
    {
        auto [k1, k2, id] = d[i];

        while (idx < vv.size() and vv[idx].first < k1)
        {
            auto [A, B] = vv[idx];
            auto it = lower_bound(all(itob), B);
            auto dist = it - begin(itob);
            update(dist, dist, 1, 1, nn, 1);
            idx++;
        }

        auto pos = lower_bound(all(itob), k2) - begin(itob);
        if (pos <= 1)
        {
            ans[id] = 0;
        }
        else
        {
            ans[id] = query(1, pos - 1, 1, nn, 1);
        }
    }
    for (int i = 1; i <= q; i++)
    {
        cout << ans[i] << endl;
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
```

>  $pbds::ordered_multiset$ 版本
```cpp
// #pragma GCC optimize(2)
#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

using namespace std;
using namespace __gnu_pbds;

#define int long long
#define endl '\n'
#define all(x) (x).begin(), (x).end()

// 支持重复元素的 multiset
typedef tree<int, null_type, less_equal<int>, rb_tree_tag, tree_order_statistics_node_update> ordered_multiset;

constexpr int MOD = 1e9 + 7;
// -9.2e18 ~ 9.2e18

void solve()
{
    int n, q;
    cin >> n >> q;

    /*
    记y-x=A, y+x=B
    我们要让 A<k1的同时B<k2
    这是一个很典的偏序查找问题
    我们可以对k1和A排序 遍历k1 对所有满足A<k1的{A,B} 加入B到线段树中
    然后logn查找满足k2>B的所有B 记录答案
    */

    vector<pair<int, int>> v(n);
    for (int i = 0; i < n; i++)
    {
        cin >> v[i].first >> v[i].second;
    }

    struct datas
    {
        int k1, k2, idx;
    };

    vector<datas> d(q);
    for (int i = 0; i < q; i++)
    {
        cin >> d[i].k1 >> d[i].k2;
        d[i].idx = i + 1;
    }

    vector<pair<int, int>> vv;
    for (auto [x, y] : v)
    {
        vv.emplace_back(y - x, y + x);
    }

    sort(all(vv));
    sort(all(d), [](auto a, auto b)
         { return a.k1 < b.k1; });

    // 需要先收集所有的B
    vector<int> itob;
    itob.emplace_back(LLONG_MIN);
    for (auto [_, B] : vv)
    {
        itob.emplace_back(B);
    }
    for (int i = 0; i < q; i++)
    {
        itob.emplace_back(d[i].k2);
    }
    sort(all(itob));
    itob.erase(unique(all(itob)), itob.end());

    ordered_multiset s;

    int idx = 0;
    vector<int> ans(q + 1);
    for (int i = 0; i < q; i++)
    {
        auto [k1, k2, id] = d[i];

        while (idx < vv.size() and vv[idx].first < k1)
        {
            auto [A, B] = vv[idx];
            s.insert(B);
            idx++;
        }

        ans[id] = s.order_of_key(k2);
    }
    for (int i = 1; i <= q; i++)
    {
        cout << ans[i] << endl;
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
```