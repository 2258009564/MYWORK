// #pragma GCC optimize(2)
#include <bits/stdc++.h>
using namespace std;
#define int long long
#define endl '\n'

void xuanzhuan(vector<vector<int>> &vec, int x, int y, int r, int z)
{
    int x1 = x - 1, y1 = y - 1;
    
}

signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int n;
    cin >> n;
    int num = 1;
    vector<vector<int>> vec(n);
    for (auto &&v : vec)
    {
        for (auto &&i : v)
        {
            i = num++;
        }
    }
    int m;
    cin >> m;
    int x, y, r, z;

    while (m--)
    {
        cin >> x >> y >> r >> z;
    }
}