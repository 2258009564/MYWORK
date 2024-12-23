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

signed main()
{
    BUFF;
    string s;
    int l, r;
    int total = 0;
    ts
    {
        int sum = 0;
        cin >> l >> r;

        for (int i = l; i <= r; i++)
        {
            s = to_string(i);
            bool found = 0;
            for (int i = 0; i + 2 < s.size(); i++)
            {
                if (s[i] == '0')
                {
                    for (int j = i + 1; j + 1 < s.size(); j++)
                    {
                        if (s[j] == '0')
                        {
                            for (int k = j + 1; k < s.size(); k++)
                            {
                                if (s[k] == '7')
                                {
                                    found = 1;
                                    break;
                                }
                            }
                        }
                        if(found)
                        {
                            break;
                        }
                    }
                }
                if(found)
                {
                    break;
                }
            }
            if(found)
            {
                sum++;
            }
        }
        total ^= sum;
    }
    cout << total;
}