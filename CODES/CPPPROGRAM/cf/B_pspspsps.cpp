#include <bits/stdc++.h>
using namespace std;
// #define int long long
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

    vi min_p(n, 1), max_p(n, n);
    for (int i = 0; i < n; i++)
    {
        if (s[i] == 'p')
        {
            for (int j = 0; j <= i; j++)
            {
                max_p[j] = min(max_p[j], i + 1);
            }
        }
        else if (s[i] == 's')
        {
            for (int j = i; j < n; j++)
            {
                max_p[j] = min(max_p[j], n - i);
            }
        }
    }
    
    int N = n;
    vvi adj(N);
    for (int i = 0; i < n; i++)
    {
        for (int v = min_p[i]; v <= max_p[i]; v++)
        {
            adj[i].push_back(v - 1); 
        }
    }

    vi match_to_value(N, -1);   
    vi match_to_position(N, -1); 

    function<bool(int, vc &)> bpm = [&](int u, vc &vis)
    {
        for (int v : adj[u])
        {
            if (!vis[v])
            {
                vis[v] = true;
                if (match_to_value[v] == -1 || bpm(match_to_value[v], vis))
                {
                    match_to_value[v] = u;
                    match_to_position[u] = v;
                    return true;
                }
            }
        }
        return false;
    };

    int result = 0;
    for (int u = 0; u < N; u++)
    {
        vc vis(N, false);
        if (bpm(u, vis))
        {
            result++;
        }
    }

    if (result == N)
    {
        cout << "YES" << endl;
    }
    else
    {
        cout << "NO" << endl;
    }
}

signed main()
{
    ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
    int TT = 1;
    cin >> TT;
    while (TT--)
    {
        solve();
    }
}