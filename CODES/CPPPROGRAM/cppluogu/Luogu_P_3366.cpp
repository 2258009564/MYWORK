// #pragma GCC optimize(2)
// #pragma GCC optimize("Ofast")
// #pragma GCC optimize("inline", "fast-math", "unroll-loops", "no-stack-protector")
// #pragma GCC diagnostic error "-fwhole-program"
// #pragma GCC diagnostic error "-fcse-skip-blocks"
// #pragma GCC diagnostic error "-funsafe-loop-optimizations"
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

const int INF = 1e9;     // 无穷大
const int INF_LL = 1e18; // 长整型无穷大
const int MOD = 1e9 + 7; // 模数

void solve()
{
    int n, m, v1, v2, val;
    cin >> n >> m;

    struct Data
    {
        int v1, v2, val;
    };
    vector<Data> datas;
    while (m--)
    {
        cin >> v1 >> v2 >> val;
        v1--, v2--;
        if (v1 != v2)
        {
            datas.push_back({v1, v2, val});
        }
    }

    // kruskal

    // FU begin
    vector<int> father;
    auto init = [&](int n)
    {
        father.resize(n);
        iota(all(father), 0);
    };

    function<int(int)> ffind = [&](int i)
    {
        return i == father[i] ? i : father[i] = ffind(father[i]);
    };

    auto funion = [&](int i, int j)
    {
        auto ri = ffind(i), rj = ffind(j);
        if (ri - rj)
        {
            father[ri] = rj;
        }
    };

    auto issame = [&](int i, int j) -> bool
    {
        return ffind(i) == ffind(j);
    };

    // FU end

    ranges::sort(datas, [](Data &a, Data &b)
                 { return a.val < b.val; });

    init(5001);
    int ans = 0, count = 0;

    vector<bool> visited(n, 0);
    for (auto &&[v1, v2, val] : datas)
    {
        if (!issame(v1, v2))
        {
            visited[v1] = visited[v2] = 1;
            ans += val;
            funion(v1, v2);
            count++;
        }
    }

    if (count == n - 1)
    {
        cout << ans;
    }
    else
    {
        cout << "orz";
    }
}

signed main()
{
    cin.tie(nullptr)->sync_with_stdio(false);
    int TT = 1;
    // cin >> TT;
    while (TT--)
    {
        solve();
        cout << endl;
    }
}