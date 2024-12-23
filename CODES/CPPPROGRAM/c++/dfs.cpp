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
#define pb push_back
#define qb pop_back
#define pf push_front
#define qf pop_front

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

vvi result;
vi path;
void dfs(vvi graph, int startindex, int n)
{
    if (startindex == n)
    {
        result.push_back(path);
        return;
    }
    // fa:
    for (int i = 1; i <= n; i++)
    {
        if (graph[startindex][i])
        {
            path.push_back(i);
            dfs(graph, i, n);
            path.pop_back();
        }
    }
}

signed main()
{
    BUFF;
    int n, m, s, t;
    cin >> n;
    vvi graph(n + 1, vi(n + 1, 0));
    cin >> m;
    while (m--)
    {
        cin >> s >> t;
        graph[s][t] = 1;
    }

    /*
    vector<list<int>> graph(n + 1);
    while(m--)
    {
        cin >> s >> t;
        graph[s].push_back(t);
    }
    */
    // std::list 优势：插入和删除效率高，尤其是在容器中间进行操作时。
}