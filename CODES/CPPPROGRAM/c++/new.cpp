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

vector<vector<int>> result;
vector<int> path;

/*
组合 需要startindex 不需要used
对于 只有一个超集的题目 考虑使用startindex

排列 不需要startindex 需要used
*/

void backtracking(int startindex, int k, int n)
{
    // 到达底部 到达终止条件
    if (path.size() == k)
    {
        result.push_back(path);
        return;
    }

    // father : startindex ~ n
    // son : i
    for (int i = startindex; i <= n; i++)
    {
        path.push_back(i);
        backtracking(i + 1, k, n);
        path.pop_back();
    }
}

signed main()
{
    BUFF;
    int n, k;
    n = 5, k = 3;
    backtracking(1, k, n);

    for (auto &&i : result)
    {
        cout << i;
        cout << endl;
    }
}