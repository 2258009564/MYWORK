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

void solve()
{
    string s1, s2;
    cin >> s1 >> s2;

    pii d1, d2;
    d1.first = s1[0] - 'a', d1.second = s1[1] - '1';
    d2.first = s2[0] - 'a', d2.second = s2[1] - '1';

    vvi used(8, vi(8, 0)); // 8x8 的棋盘

    used[d1.first][d1.second] = 1; // 标记 d1 的位置
    used[d2.first][d2.second] = 1; // 标记 d2 的位置

    // 标记 d1 的行列
    for (int i = 0; i < 8; i++)
    {
        used[d1.first][i] = 1; // 标记同行所有格子
        used[i][d1.second] = 1;  // 标记同列所有格子
    }

    // 马的移动方式
    vpii xy = {{-2, -1}, {-2, 1}, {2, -1}, {2, 1}, {-1, -2}, {-1, 2}, {1, -2}, {1, 2}};

    // 马能打到车 那么把车想象成马 它能到达的地方马就去不了

    // 标记马1的攻击范围
    for (auto &&[x, y] : xy)
    {
        int curx = d1.first + x, cury = d1.second + y;
        if (curx >= 0 and curx < 8 and cury >= 0 and cury < 8)
        {
            used[curx][cury] = 1;
        }
    }

    // 标记马2的攻击范围
    for (auto &&[x, y] : xy)
    {
        int curx = d2.first + x, cury = d2.second + y;
        if (curx >= 0 and curx < 8 and cury >= 0 and cury < 8)
        {
            used[curx][cury] = 1;
        }
    }

    int N = 64;

    // 计算未被标记的格子数
    for (auto &&v : used)
    {
        N -= accumulate(all(v), 0ll); // 对每一行进行累加
    }

    cout << N; // 输出结果
}

signed main()
{
    ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
    int TT = 1;
    // cin >> TT;
    while (TT--)
    {
        solve();
    }
}