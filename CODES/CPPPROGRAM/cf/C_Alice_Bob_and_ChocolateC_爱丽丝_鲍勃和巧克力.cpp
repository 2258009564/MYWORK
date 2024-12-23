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
    vi v(n);
    cin >> v;

    if (n == 1)
    {
        cout << 1 << ' ' << 0;
        return;
    }

    int indexa = 0, indexb = n - 1;
    int suma = v[indexa], sumb = v[indexb];
    
    while (indexa < indexb)
    {

        if (suma > sumb)
        {
            sumb += v[--indexb];
        }
        else if (indexb > indexa)
        {
            suma += v[++indexa];
        }
        else
        {
            sumb += v[--indexb];
            suma += v[++indexa];
        }
    }

    if (suma <= sumb)
    {
        indexa++;
    }
    else
    {
        indexb--;
    }
    cout << indexa << ' ' << n - 1 - indexb << endl;
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