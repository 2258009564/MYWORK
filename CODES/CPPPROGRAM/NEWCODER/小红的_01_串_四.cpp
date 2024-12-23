// #pragma GCC optimize(2)
#include <bits/stdc++.h>
using namespace std;
#define BUFF ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
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
typedef vector<bool> vb;
typedef vector<vb> vvb;
typedef vector<vvb> vvvb;
typedef map<int, int> mii;
typedef map<char, int> mci;
#define endl '\n'
#define ts    \
    int T;    \
    cin >> T; \
    while (T--)
#define all(v) v.begin(), v.end()
#define sall(x) sort(all(x))
#define re(v) reverse(all(v))

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

/*
链接：https://ac.nowcoder.com/acm/contest/98256/D
来源：牛客网

题目描述
小红拿到了一个01串，她初始站在第一个字符。小红可以进行以下移动方式：
1. 花费
𝑥
x能量，移动到当前位置右边、离当前位置最近的，和当前字符相同的字符；
2. 花费
𝑦
y能量，移动到当前位置右边、离当前位置最近的，和当前字符不同的字符。

小红想知道，她移动到最右端的最小花费是多少？
输入描述:
第一行输入三个正整数
𝑛
,
𝑥
,
𝑦
n,x,y，用空格隔开，代表01串长度、第一种移动花费，第二种移动花费。
第二行输入一个长度为
𝑛
n的01串。
1
≤
𝑛
,
𝑥
,
𝑦
≤
1
0
5
1≤n,x,y≤10
5

输出描述:
一个整数，代表花费的最小总能量。
示例1
输入
复制
5 1 2
01011
输出
复制
4
说明
有两种方案均可：操作2+操作1+操作1 或者 操作1+操作2+操作1。
*/

signed main()
{
    BUFF;
    int n, x, y;
    cin >> n >> x >> y;
    string s;
    cin >> s;

    vector<int> dp(n, 1e9);
    dp[n - 1] = 0;

    unordered_map<char, int> last_seen;

    for (int i = n - 2; i >= 0; i--)
    {
        if (last_seen.count(s[i]))
        {
            dp[i] = min(dp[i], dp[last_seen[s[i]]] + x);
        }
        if (last_seen.count(s[i] == '0' ? '1' : '0'))
        {
            dp[i] = min(dp[i], dp[last_seen[s[i] == '0' ? '1' : '0']] + y);
        }

        last_seen[s[i]] = i;
    }

    cout << dp[0] << endl;
}