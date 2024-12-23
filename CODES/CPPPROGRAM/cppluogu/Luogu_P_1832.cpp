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

int N = 1e3 + 10;

vi sieve(int n)
{
    vi isprime(n + 1, 1);        // 假设所有数都是素数
    isprime[0] = isprime[1] = 0; // 0 和1 不是素数

    for (int i = 2; i * i <= n; i++)
    {
        if (isprime[i])
        {
            for (int j = i * i; j <= n; j += i)
            {
                isprime[j] = 0;
            }
        }
    }

    vi primes;
    for (int i = 2; i <= n; i++)
    {
        if (isprime[i])
            primes.push_back(i);
    }
    return primes;
}

signed main()
{
    BUFF;
    int n;
    cin >> n; 

    if (n < 2)
    {
        cout << 0;
        return 0;
    }

    auto primes = sieve(n);

    vi dp(n + 1, 0);
    dp[0] = 1; 

    for (auto &p : primes)
    {
        for (int i = p; i <= n; i++)
        {
            dp[i] += dp[i - p];
        }
    }

    cout << dp[n];
}