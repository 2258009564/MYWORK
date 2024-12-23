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

void solve() {
    // 读取数组长度
    int n;
    cin >> n;
    // 声明并读取长度为n的数组
    vi v(n);
    cin >> v;

    // 存储符合条件年份的数组
    vi years;
    // startindex用于追踪当前需要匹配的值
    int startindex = 1;
    
    // 遍历输入数组
    for (int i = 0; i < v.size(); i++) {
        // 如果当前值等于startindex，说明找到了一个符合条件的年份
        if (v[i] == startindex) {
            // 将对应年份(2001+i)加入结果数组
            years.push_back(2001 + i);
            // 更新下一个需要匹配的值
            startindex++;
        }
    }

    // 如果没有找到符合条件的年份
    if (years.empty()) {
        cout << 0;
        return;
    }
    
    // 输出符合条件的年份数量
    cout << years.size() << endl;
    // 输出所有符合条件的年份
    cout << years;
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