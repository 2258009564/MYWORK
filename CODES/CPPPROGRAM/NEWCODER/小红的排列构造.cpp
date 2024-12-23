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
    int n;
    cin >> n;
    string s;
    cin >> s;

    if (count(all(s), '0') == s.size() or s[s.size() - 1] == '0')
    {
        cout << -1;
        return;
    }

    vi result(n);
    vi used(n + 1);
    int next_small = 1;

    for (int i = 0; i < n; i++)
    {
        if (s[i] == '0')
        {
            bool found = 0;
            for (int j = i + 2; j <= n; j++)
            {
                if (!used[j])
                {
                    result[i] = j;
                    used[j] = 1;
                    found = true;
                    break;
                }
            }
            if (!found)
            {
                cout << -1;
                return;
            }
        }
        else
        {
            while (next_small <= n and used[next_small])
            {
                next_small++;
            }
            if (next_small > n)
            {
                cout << -1;
                return;
            }
            result[i] = next_small;
            used[next_small] = 1;
        }
    }

    for (int x : result)
    {
        cout << x << ' ';
    }
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