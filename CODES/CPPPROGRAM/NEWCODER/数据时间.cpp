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
    string n, h, m;
    cin >> n >> h >> m;
    if (m.size() == 1)
    {
        m = '0' + m;
    }

    set<int> i1, i2, i3;

    int id;
    string s1, s2;
    while (cin >> id >> s1 >> s2)
    {
        if (s1.substr(0, 4) != h or s1.substr(5, 2) != m)
        {
            continue;
        }

        auto s3 = s2.substr(0, 2);

        if (s3 == "07" or s3 == "08" or s2 == "09:00:00" or s3 == "18" or s3 == "19" or s2 == "20:00:00")
        {
            i1.insert(id);
        }
        if (s3 == "11" or s3 == "12" or s2 == "13:00:00")
        {
            i2.insert(id);
        }
        if (s3 == "22" or s3 == "23" or s3 == "00" or s2 == "01:00:00")
        {
            i3.insert(id);
        }
    }
    cout << i1.size() << ' ' << i2.size() << ' ' << i3.size();
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