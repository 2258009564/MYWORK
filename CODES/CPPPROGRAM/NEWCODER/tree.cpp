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
    // 问题：给你n个数字 不相同的可以花费 y 两两抵消
    // 或者花费x消去任意一个数字
    // 求最小花费

    int n, x, y;
    cin >> n >> x >> y;
    // 消去两个数字可以是 y 也可以是 2 * x 
    if (2 * x <= y) // 直接消去最便宜
    {
        cout << x * n;
    }
    else // 需要成对匹配
    {
        // 假设已经获得了一个map  key 是数字 value是出现次数
        map<int, int> mp;
        // 找到最大的那个出现次数
        int maxnum = -1;
        for (auto &&[_, i]: mp)
        {
            maxnum = max(maxnum, i);
        }

        int rest = n - maxnum;
        if (maxnum > rest) // 必定不能成对匹配 有rest对和maxnum - rest 个
        {
            cout << y * rest + x * (maxnum - rest);
        }
        else // 有可能可以成对匹配 但是需要考虑是不是奇数
        {
            // n / 2 对可以匹配 还剩下 n % 2 个
            cout << y * n / 2 + n % 2 * x;
        }
    }
}

signed main()
{
    cin.tie(nullptr)->ios::sync_with_stdio(false);
    cout << setiosflags(ios::fixed) << setprecision(2);
    int TT = 1;
    // cin >> TT;
    while (TT--)
    {
        solve();
        cout << endl;
    }
}