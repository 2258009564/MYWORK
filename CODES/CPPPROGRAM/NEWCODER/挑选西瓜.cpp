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

struct Watermelon
{
    double size, color, sound, score;
};

double computeScore(Watermelon *w)
{
    return w->size * w->color / w->sound;
}

double computeNormalizedScore(Watermelon *w, double maxV, double minV)
{
    return (w->score - minV) * 100 / (maxV - minV);
}

void solve()
{
    int n;
    cin >> n;
    vector<Watermelon> v(n);
    double maxV = INT_MIN, minV = INT_MAX;
    for (auto &&i : v)
    {
        cin >> i.size >> i.color >> i.sound;
        i.score = computeScore(&i);
        maxV = max(maxV, i.score);
        minV = min(minV, i.score);
    }
    for (auto &&i : v)
    {
        cout << fixed << setprecision(2) << computeNormalizedScore(&i, maxV, minV) << endl;
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