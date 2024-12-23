// #pragma GCC optimize(2)
#include <bits/stdc++.h>
using namespace std;
#define BUFF ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
#define int long long
typedef pair<int, int> pii;
typedef pair<double, double> pdd;
typedef vector<string> vs;
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

int N = 100002;
vb isprime(N, 1);

void isPrime(vb &isprime)
{
    isprime[0] = isprime[1] = 0;
    for (int i = 2; i <= N / i; i++)
    {
        if (isprime[i])
        {
            for (int j = i * i; j <= N; j += i)
            {
                isprime[j] = 0;
            }
        }
    }
}

signed main()
{
    BUFF;
    isPrime(isprime);
    int a, b;
    cin >> a >> b;
    vi v;
    for (int i = 2; i <= N; i++)
    {
        if(isprime[i])
        {
            v.pb(isprime[i]);
        }
    }
    cout << v[0] << ' ';
    for (int i = 1; i < v.size();i++)
    {
        if(v[i])
    }
}