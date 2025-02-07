// #pragma GCC optimize(2)
#include <bits/stdc++.h>
using namespace std;
#define int long long
#define endl '\n'

const int INF = 1e9;     // 无穷大
const int INFLL = 1e18;  // 长整型无穷大
const int MOD = 1e9 + 7; // 模数

void solve() // d
{
    int n, m;
    cin >> n >> m;
    string a, b, sa, sb;
    cin >> a >> b;

    map<char, int> mp;
    for (auto &&i : a)
    {
        mp[i]++;
    }
    for (auto &&i : b)
    {
        if (mp[i])
        {
            mp[i]--;
        }
        else
        {
            sb += i;
        }
    }

    for (auto &&[k, v] : mp)
    {
        while (v--)
        {
            sa += k;
        }
    }

    // 现在 sa 记录的是a特有的 sb记录的是b特有的 我们交换 让比较小的永远在前面
    if (sa.size() > sb.size())
    {
        string sc = sa;
        sa = sb;
        sb = sc;
    }
    // cout << sa << ' ' << sb << endl;
    if (sa.size() == sb.size()) // 如果长度相等 说明其中一边必须全部替换
    {
        cout << sa.size();
        return;
    }

    // 剩下的都是长度不等 并且小的在前面
    int rest = sb.size() - sa.size();
    // cout << "rest =" << rest << endl;
    // rest 记录的是sb多出去的部分
    // 如果长度是奇数那可太好了 随便丢一个放到最中间就行
    // 放完之后长度一定会变成偶数 这时候要找sb有没有成双成对的
    map<char, int> mpb;
    for (auto &&i : sb)
    {
        mpb[i]++;
    }
    int even = 0;
    for (auto &&[k, v] : mpb)
    {
        even += v / 2; // even 记录sb有多少个成双成对的(乃至更多)
    }
    
    while (rest > 1 and even > 0)
    {
        rest -= 2;
        even--;
    }

    // 现在所有上面应该都被消除了————除非couple不够
    cout << sa.size() + rest / 2;
}

signed main()
{
    cin.tie(nullptr)->sync_with_stdio(false);
    cout << setiosflags(ios::fixed) << setprecision(2);
    int TT = 1;
    cin >> TT;
    while (TT--)
    {
        solve();
        cout << endl;
    }
}