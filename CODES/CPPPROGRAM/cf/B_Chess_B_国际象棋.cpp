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
    string s1, s2;
    cin >> s1 >> s2;

    pair<int, int> d1, d2;
    d1.first = s1[0] - 'a', d1.second = s1[1] - '1';
    d2.first = s2[0] - 'a', d2.second = s2[1] - '1';
    vvi used(8, vi(8, 0));
    
    for (int i = 0; i < 8; i++)
    {
        used[d1.second][i] = 1;  
        used[i][d1.first] = 1;   
    }

    int knight_moves[8][2] = {
        {-2, -1}, {-2, 1}, {2, -1}, {2, 1}, {-1, -2}, {-1, 2}, {1, -2}, {1, 2}};

    for (auto &move : knight_moves)
    {
        int new_row = d2.second + move[0];
        int new_col = d2.first + move[1];
        if (new_row >= 0 && new_row < 8 && new_col >= 0 && new_col < 8)
        {
            used[new_row][new_col] = 1;  
        }
    }

    for (auto &move : knight_moves)
    {
        int new_row = d1.second + move[0];
        int new_col = d1.first + move[1];
        if (new_row >= 0 && new_row < 8 && new_col >= 0 && new_col < 8)
        {
            used[new_row][new_col] = 1; 
        }
    }

    int count = 0;
    for (int row = 0; row < 8; row++)
    {
        for (int col = 0; col < 8; col++)
        {
            if (!used[row][col] && (row != d1.second || col != d1.first) && (row != d2.second || col != d2.first))
            {
                count++;
            }
        }
    }

    cout << count << endl;
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