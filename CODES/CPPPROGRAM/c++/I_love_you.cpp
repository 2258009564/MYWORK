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

string s1 = "0iloveyou";

int mod = 20010905;

signed main()
{
    // BUFF;
    // int total = 0;
    // string s;
    // cin >> s;
    // int sz = s.size();
    // vi dp(sz, 0);

    // // dp[i]: 以s[i]为末尾的 子序列总数
    // unordered_map<char, int> mp;
    // for (int i = 0; i < s1.size(); i++)
    // {
    //     mp[s1[i]] = i;
    // }

    // for (int i = 0; i < sz; i++)
    // {
    //     if (isalpha(s[i]))
    //     {
    //         s[i] = tolower(s[i]);
    //     }

    //     char cur = s[i];

    //     if (mp[cur])
    //     {
    //         if (mp[cur] == 1)
    //         {
    //             dp[i] = 1;
    //         }
    //         else
    //         {
    //             for (int j = 0; j < i; j++)
    //             {
    //                 if (mp[s[j]] == mp[cur] - 1)
    //                 {
    //                     dp[i] += dp[j];
    //                 }
    //             }
    //         }
    //         if (mp[cur] == 8)
    //         {
    //             total += dp[i];
    //             total %= mod;
    //         }
    //     }
    // }
    // cout << total;

    BUFF;
    string s;
    cin >> s;
    int sz = s.size();
    vi dp(9, 0);
    dp[0] = 1; // 初始化
    // dp[i]: s[i]为末尾的 子序列的 个数
    for (int i = 0; i < sz; i++)
    {
        if (isalpha(s[i]))
        {
            s[i] = tolower(s[i]);
        }
        for (int k = 8; k >= 1; k--)
        {
            if (s[i] == s1[k])
            {
                dp[k] = (dp[k] + dp[k - 1]) % mod;
            }
        }
    }

    cout << dp[8];
}