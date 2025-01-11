// #pragma GCC optimize(2)
#include <bits/stdc++.h>
using namespace std;
#define int long long
typedef pair<int, int> pii;
typedef pair<double, double> pdd;
typedef vector<string> vs;
typedef vector<vs> vvs;
typedef vector<vvs> vvvs;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<vvi> vvvi;
typedef vector<pii> vpii;
typedef vector<vpii> vvpii;
typedef vector<pdd> vpdd;
typedef vector<double> vd;
typedef vector<vd> vvd;
typedef vector<char> vc;
typedef vector<vc> vvc;
typedef vector<vvc> vvvc;
typedef map<int, int> mii;
typedef map<char, int> mci;
#define endl '\n'
#define all(v) v.begin(), v.end()
#define sall(v, x) sort(all(v), x)

// 通用版本的 >> 重载，用于任意类型的 std::vector<T>
template <typename T>
istream &operator>>(istream &in, vector<T> &v)
{
    for (auto &x : v)
    {
        in >> x;
    }
    return in;
}

// 通用版本的 << 重载，用于任意类型的 std::vector<T>
template <typename T>
ostream &operator<<(ostream &out, const vector<T> &v)
{
    for (const auto &x : v)
    {
        out << x << ' ';
    }
    return out;
}

// 快速幂取模运算
// @param a: 底数
// @param b: 指数
// @param mod: 模数
// @return: (a^b) % mod
int QuickPowMod(int a, int b, int mod)
{
    if (mod <= 0)
    {
        return -1; // 模数必须为正
    }
    if (b < 0)
    {
        return -1; // 指数必须非负
    }

    int result = 1;
    a %= mod;
    while (b)
    {
        if (b & 1)
        {
            result = (result * a) % mod;
        }
        a = (a * a) % mod;
        b >>= 1; // 使用位运算替代除法
    }
    return result;
}

const int INF = 1e9;     // 无穷大
const int INF_LL = 1e18; // 长整型无穷大
const int MOD = 1e9 + 7; // 模数

void solve()
{
    // 一本书共有n页 每k页可以组成一个章节 （页码，章节数量都从一开始） 现在给出第m页 求第m页的所在章节
    return (m - 1) / 3 + 1 -> (num - 初始值) / 周期 + 初始值
    123 456 789
    k = 3 

    m = 4

    /*
    简体中文、字母、数字、标点符号（不区分全角和半角），都按照1个字计算。
    短信长度不超过70个字，按照1条短信计费；超过70个字时为长短信，按照67字 / 条，拆分成多条计费。每条短信计费0.1。
    */

    letterlength = 71
    int total = 0
    if (letterlength <= 70) total = 1;
    else total = (letterlength - 1) / 67 + 1

    /* 小杨学习了加密技术移位，所有大写字母都向后按照一个固定数目进行偏移。偏移过程会将字母表视作首尾相接的环，例如，当移量是3的时候，大写字母 A会替换成 D，大写字母Z会替换成C，总体来看，大写字母表 ABCDEFGHIJKLMNOPQRSTUVWXYZ 会被替换成DEFGHIJKLMNOPQRSTUVWXYZABC.
    注:当偏移量是26的倍数时，每个大写字母经过偏移后会恰好回到来的位置，即大写字母表 ABCDEFGHIJKLMNOPQRSTUVWXYZ经过偏移后会保持不变。
    */

   k = 3 Z -> C

   (cur + add - 初始值) % T + 初始值
    char cur_alpha = 'C' 
    k = -3
    while(k < 0) k += 26
   new_alpha = (cur_alpha + k - 'A') % 26 + 'A'
}

signed main()
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int TT = 1;
    // cin >> TT;
    while (TT--)
    {
        solve();
        cout << endl;
    }
}