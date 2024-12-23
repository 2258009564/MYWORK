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
    // 读入小岛数量n, 选择的青蛙数量m, 蚊子数量k
    int n, m, k;
    cin >> n >> m >> k;

    // 读入m个青蛙的数值
    vi frogs(m);
    cin >> frogs;

    // 用map记录每个蚊子出现的位置
    mii mosks;
    int num;
    for (int i = 1; i <= k; i++)
    {
        cin >> num;
        mosks[num]++;
    }

    // mp用于统计每个青蛙能吃到的蚊子数量，key是蚊子数量，value是青蛙的编号
    map<int, vi> mp;
    for (int i = 0; i < frogs.size(); i++)
    {
        auto frog = frogs[i];
        int total = 0;
        // 遍历每个蚊子，如果蚊子的数值能被青蛙整除，说明这个青蛙能吃到这个蚊子
        for (auto &&[mosk, v] : mosks)
        {
            if (mosk % frog == 0)
            {
                total++;
            }
        }

        // 记录能吃到相同数量蚊子的青蛙编号
        mp[total].push_back(i + 1);
    }

    // 输出能吃到最少蚊子的青蛙数量和编号
    // mp是按key升序的，所以第一个元素就是最少的
    cout << (*mp.begin()).second.size() << endl;
    cout << (*mp.begin()).second;
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