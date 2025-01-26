//#pragma GCC optimize(2)
//#pragma GCC optimize("Ofast")
//#pragma GCC optimize("inline", "fast-math", "unroll-loops", "no-stack-protector")
//#pragma GCC diagnostic error "-fwhole-program"
//#pragma GCC diagnostic error "-fcse-skip-blocks"
//#pragma GCC diagnostic error "-funsafe-loop-optimizations"
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
    int n, k;
    cin >> n >> k;
    vector<vector<int>> datas;
    for (int i = 0; i < n; i++)
    {
        int a, b;
        cin >> a >> b;
        
        datas.push_back({i, a, b});
    }

    ranges::sort(datas, [](vector<int> &a, vector<int> &b)
                 { return a[1] < b[1]; });

    int index1, index2;
    for (int i = 0; i < n; i++)
    {
        if (datas[i][0] == 2 * k - 1)
        {
            index1 = i;
        }
        if (datas[i][0] == 2 * k)
        {
            index2 = i;
        }
    }

    if (abs(index1 - index2) != 1)
    {
        cout << "No";
        return;
    }
    int ans = -1;
    if (datas[index1][2] != datas[index2][2]) // 速度不同 可以直接撞
    {
        ans = (double)abs(datas[index1][1] - datas[index2][1]) / 2;
    }
    else
    {
        // 尝试在更小的左边找

        int left = min(index1, index2), right = max(index1, index2);

        double ans1 = 0, ans2 = 0;

        for (int i = left - 1; i >= 0; i--)
        {
            if (datas[i][2] != datas[left][2])
            {
                ans1 = (double)abs(datas[left][1] - datas[i][1]) / 2;
                break;
            }
        }

        for (int i = right + 1; i < n; i++)
        {
            if (datas[i][2] != datas[right][2])
            {
                ans2 = (double)abs(datas[right][1] - datas[i][1]) / 2;
                break;
            }
        }

        if (ans1 and ans2)
        {
            
        }
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