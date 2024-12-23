// #pragma GCC optimize(2)
#include <bits/stdc++.h>
using namespace std;
#define int long long
typedef pair<int, int> pii;
typedef pair<double, double> pdd;
typedef vector<int> vi;
typedef vector<double> vd;
typedef vector<string> vs;
typedef vector<vi> vvi;
typedef vector<vvi> vvvi;
typedef vector<pii> vpii;
typedef vector<vpii> vvpii;
typedef vector<pdd> vpdd;
typedef vector<vd> vvd;
#define endl '\n'
#define T     \
    int T;    \
    cin >> T; \
    while (T--)
#define all(v) v.begin(), v.end()
#define sall(x) sort(all(x))
#define pb push_back
#define qb pop_back
#define pf push_front
#define qf pop_front

signed main()
{
    ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
    vector<vector<char>> v(3, vector<char>(3));
    for (auto &&i : v)
    {
        for (auto &&i1 : i)
        {
            cin >> i1;
        }
    }
    int found = 0;
    for (auto &&i : v)
    {
        if (i[0] == i[1] and i[1] == i[2])
        {
            if (i[0] == 'K')
            {
                found = 1;
                break;
            }
            else if (i[0] == 'B')
            {
                found = 2;
                break;
            }
        }
    }
    for (int i = 0; i < 3; i++)
    {
        if (v[0][i] == v[1][i] and v[0][i] == v[2][i])
        {
            if (v[0][i] == 'K')
            {
                found = 1;
                break;
            }
            else if (v[0][i] == 'B')
            {
                found = 2;
                break;
            }
        }
    }
    if ((v[0][0] == v[1][1] and v[0][0] == v[2][2]) or (v[2][0] == v[1][1] and v[2][0] == v[0][2]))
    {
        if (v[1][1] == 'K')
        {
            found = 1;
        }
        else if (v[1][1] == 'B')
        {
            found = 2;
        }
    }
    if (found)
    {
        if (found == 1)
        {
            cout << "KiKi wins!";
        }
        else
        {
            cout << "BoBo wins!";
        }
    }
    else
    {
        cout << "No winner!";
    }
}