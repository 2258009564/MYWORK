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

signed main()
{
    BUFF;
    stack<int> stk; // uesd to store the index of "v";
    /*
    stk 存储的是当前状态下所有等待比较的元素的索引。
    更具体地说，栈中存储的是那些尚未找到其右边第一个更大元素的元素的索引。通过这些索引，我们可以回到原数组 v 中，获取对应的值，以便在未来的比较中找到第一个比它大的元素。
    */
    vi v = {1, 9, 5, 3, 4, 6, 7, 2, 8, 0};
    vi result(v.size(), -1); // result[i]: 第i个元素向右看齐
    /*
    初始化：
    大小设置成跟原数组一样， value 全部初始化为-1
    */
    for (int i = 0; i < v.size(); i++) // 遍历数组 v 中的每一个元素
    {
        // 当栈不为空，并且栈顶元素小于或等于当前元素时
        while (!stk.empty() && v[stk.top()] <= v[i])
        {
            // 将栈顶索引的对应元素更新为当前元素
            result[stk.top()] = v[i]; // 当前元素 v[i] 是栈顶元素的右边第一个更大元素
            stk.pop();                // 弹出栈顶元素，因为它已经找到了右边更大的元素
        }
        stk.push(i); // 将当前元素的索引入栈，等待将来找到比它大的元素
    }
    for (auto &&i : result)
    {
        cout << i << ' ';
    }
}
