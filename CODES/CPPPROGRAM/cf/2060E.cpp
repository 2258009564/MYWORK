// #pragma GCC optimize(2)
#include <bits/stdc++.h>
using namespace std;
#define int long long
#define endl '\n'

const int INF = 1e9;     // 无穷大
const int INFLL = 1e18;  // 长整型无穷大
const int MOD = 1e9 + 7; // 模数
// -9.2e18 ~ 9.2e18

void solve()
{
    int n, m1, m2;
    cin >> n >> m1 >> m2;
    vector<vector<int>> adj1(n + 1), adj2(n + 1);
    int tot1 = n, tot2 = n;
    int v1, v2;
    while (m1--)
    {
        cin >> v1 >> v2;
        adj1[min(v1, v2)].emplace_back(max(v1, v2));
    }
    while (m2--)
    {
        cin >> v1 >> v2;
        adj2[min(v1, v2)].emplace_back(max(v1, v2));
    }

    // FUg
    vector<int> fag(n + 1);
    iota(fag.begin(), fag.end(), 0ll);

    function<int(int)> ffindg = [&](int i)
    {
        return i == fag[i] ? i : fag[i] = ffindg(fag[i]);
    };

    auto funiong = [&](int i, int j)
    {
        auto ri = ffindg(i), rj = ffindg(j);

        if (ri != rj)
        {
            fag[ri] = rj;
            tot2--;
        }
    };

    auto issameg = [&](int i, int j) -> bool
    {
        return ffindg(i) == ffindg(j);
    };
    // FUg end

    // FUf
    vector<int> faf(n + 1);
    iota(faf.begin(), faf.end(), 0ll);

    function<int(int)> ffindf = [&](int i)
    {
        return i == faf[i] ? i : faf[i] = ffindf(faf[i]);
    };

    auto funionf = [&](int i, int j)
    {
        auto ri = ffindf(i), rj = ffindf(j);

        if (ri != rj)
        {
            faf[ri] = rj;
            tot1--;
        }
    };

    auto issamef = [&](int i, int j) -> bool
    {
        return ffindf(i) == ffindf(j);
    };
    // FUf end

    int ans = 0;
    for (int v1 = 1; v1 <= n; v1++)
    {
        for (auto &&v2 : adj2[v1])
        {
            funiong(v1, v2); // 对所有g的都合并
        }
    }

    for (int v1 = 1; v1 <= n; v1++)
    {
        for (auto &&v2 : adj1[v1])
        {
            if (!issameg(v1, v2)) // 如果在g中没有 说明要删掉
            {
                ans++;
            }
            else
            {
                funionf(v1, v2); // 否则 就合并
            }
        }
    }

    ans += (tot1 - tot2);
    cout << ans;
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