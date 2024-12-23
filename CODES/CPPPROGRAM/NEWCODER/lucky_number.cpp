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

vi luckyNumbers;

void generateLuckyNumbers(int cur, int lastdigit)
{
    if (cur != 0)
    {
        luckyNumbers.push_back(cur);
    }

    for (int nextdigit = lastdigit + 1; nextdigit <= 9; ++nextdigit)
    {
        long long newnum = cur * 10 + nextdigit;
        if (newnum > 1000000)
        {
            break;
        }
        generateLuckyNumbers(newnum, nextdigit);
    }
}

void solve()
{
    int l, r;
    cin >> l >> r;
    auto it_low = lower_bound(all(luckyNumbers), l);
    auto it_up = upper_bound(all(luckyNumbers), r);

    long long count = distance(it_low, it_up);

    cout << count << endl;
}

signed main()
{
    ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
    generateLuckyNumbers(0, 0);

    sort(all(luckyNumbers));
    int TT = 1;
    // cin >> TT;
    while (TT--)
    {
        solve();
    }
}