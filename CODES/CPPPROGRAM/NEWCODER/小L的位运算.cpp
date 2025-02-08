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
    int n, x, y;
    std::cin >> n >> x >> y;
    std::string a, b, c;
    std::cin >> a >> b >> c;

    std::map<std::pair<int, int>, int> mp;
    for (int i = 0; i < n; i++)
    {
        auto aa = a[i] ^ 48, bb = b[i] ^ 48, cc = c[i] ^ 48;

        mp[{aa, bb}] += (aa ^ bb != cc);
    }
    int cnt = 0;
    for (auto &&[k, v] : mp)
    {
        cnt += v;
    }
    // 现在分为了四组
    if (2 * x <= y)
    {
        std::cout << x * cnt;
        return;
    }

    auto maxnum = (*ranges::max_element(mp, [](auto &a, auto &b) {return a.second < b.second;})).second;
    // cnt 是全部的 maxnum 是最大的 cnt - maxnum - cnt 是剩下的
    if (cnt - maxnum >= 0)
    {
        std::cout << y * (cnt - maxnum) + x * (cnt - maxnum);
    }
    else
    {
        std::cout << cnt / 2 * y + cnt % 2 * x;
    }
}

signed main()
{
    cin.tie(nullptr)->sync_with_stdio(false);
    cout << setiosflags(ios::fixed) << setprecision(2);
    int TT = 1;
    // cin >> TT;
    while (TT--)
    {
        solve();
        cout << endl;
    }
}