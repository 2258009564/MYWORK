// #pragma GCC optimize(2)
#include <bits/stdc++.h>
using namespace std;
#define int long long
#define endl '\n'
#define all(x) (x).begin(), (x).end()

constexpr int MOD = 1e9 + 7;
// -9.2e18 ~ 9.2e18

// COMB begin ----
const int N = 1e6;
vector<int> f(N), invf(N);
bool inited = 0;
int ksm(int base, int exp)
{
    int ans = 1;
    while (exp)
    {
        if (exp & 1)
        {
            ans = ans * base % MOD;
        }
        base = base * base % MOD;
        exp >>= 1;
    }
    return ans;
}

int inv(int x)
{
    return ksm(x, MOD - 2) % MOD;
}

void pre()
{
    if (inited)
    {
        return;
    }
    inited = 1;
    f[0] = 1;
    for (int i = 1; i < N; i++)
    {
        f[i] = f[i - 1] * i % MOD;
    }

    invf[N - 1] = inv(f[N - 1]);
    for (int i = N - 2; i >= 0; i--)
    {
        invf[i] = invf[i + 1] * (i + 1) % MOD;
    }
}

int comb(int n, int k)
{
    if (!inited)
    {
        pre();
    }
    if (k < 0 or k > n)
    {
        return 0;
    }

    return f[n] * invf[k] % MOD * invf[n - k] % MOD;
}
// comb end ----

void solve()
{
    
}

signed main()
{
    cin.tie(0)->ios::sync_with_stdio(0);
    cout << setiosflags(ios::fixed) << setprecision(2);
    int TT = 1;
    // cin >> TT;
    while (TT--)
    {
        solve();
        // cout << endl;
    }
}