// #pragma GCC optimize(2)
#include <bits/stdc++.h>
using namespace std;
#define int long long
#define endl '\n'

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
const int INFLL = 1e18;  // 长整型无穷大
const int MOD = 1e9 + 7; // 模数

void solve()
{
    int n;
    cin >> n;

    unordered_map<int, int> count;
    int num;
    while (cin >> num)
    {
        count[num]++;
    }

    int ans = 0;

    for (auto &&[i, fi] : count)
    {
        for (int k = 1; k <= i / k; k++)
        {
            if (i % k == 0)
            {
                // k 是 可能的gcd
                int j = i ^ k;
                // check if k is real gcd
                if (count.count(j) and gcd(i, j) == k)
                {
                    ans += count[i] * count[j];
                }

                auto k1 = i / k;
                if (k1 != k)
                {
                    int j = i ^ k1;
                    // check if k1 is real gcd
                    if (count.count(j) and gcd(i, j) == k1)
                    {
                        ans += count[i] * count[j];
                    }
                }
            }
        }
    }
    cout << ans / 2;
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