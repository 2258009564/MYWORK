// #pragma GCC optimize(2)
#include <bits/stdc++.h>
using namespace std;
#define int long long
#define endl '\n'
#define all(x) (x).begin(), (x).end()

const int INF = 1e9;     // 无穷大
const int INFLL = 1e18;  // 长整型无穷大
const int MOD = 1e9 + 7; // 模数
// -9.2e18 ~ 9.2e18

// const int MAX_N = 1e6;
// int fact[MAX_N + 1], inv_fact[MAX_N + 1];

// int mod_pow(int a, int b, int mod)
// {
//     int res = 1;
//     while (b)
//     {
//         if (b % 2)
//             res = (res * a) % mod;
//         a = (a * a) % mod;
//         b /= 2;
//     }
//     return res;
// }

// void precompute()
// {
//     fact[0] = fact[1] = 1;
//     for (int i = 2; i <= MAX_N; i++)
//     {
//         fact[i] = fact[i - 1] * i % MOD;
//     }

//     inv_fact[MAX_N] = mod_pow(fact[MAX_N], MOD - 2, MOD);
//     for (int i = MAX_N - 1; i >= 0; i--)
//     {
//         inv_fact[i] = inv_fact[i + 1] * (i + 1) % MOD;
//     }
// }

// int comb(int n, int k)
// {
//     if (k < 0 or k > n)
//     {
//         return 0;
//     }
//     return fact[n] * inv_fact[k] % MOD * inv_fact[n - k] % MOD;
// }

void solve()
{
    // precompute();
    int n;
    cin >> n;
    string s;
    cin >> s;
    map<char, int> mp;
    for (auto &&c : s)
    {
        mp[c]++;
    }
    if (mp['-'] < 2 or mp['_'] < 1)
    {
        cout << 0;
        return;
    }
    int a = mp['-'];
    int b = a / 2;
    if (a & 1)
    {
        b++;
    }
    a /= 2;
    cout << mp['_'] * a * b;

    /*
    7
    ---_----
    */
}

signed main()
{
    cin.tie(0)->ios::sync_with_stdio(0);
    cout << setiosflags(ios::fixed) << setprecision(2);
    int TT = 1;
    cin >> TT;
    while (TT--)
    {
        solve();
        cout << endl;
    }
}