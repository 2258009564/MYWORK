// #pragma GCC optimize(2)
#include <bits/stdc++.h>
using namespace std;
#define int long long
#define endl '\n'

const int INF = 1e9;     // 无穷大
const int INFLL = 1e18;  // 长整型无穷大
const int MOD = 1e9 + 7; // 模数

void solve()
{
    int n, k;
    cin >> n >> k;
    vector<int> v(n);
    for (auto &&i : v)
    {
        cin >> i;
    }
    // 5 3
    // 1 1  0 0 0
    // 1  1 1  0 0 -- 2
    // 1 1  2 0  0 -- 1
    // 1 1  3  0 0 -- 1
    if (n != k)
    {
        int num = n - k;
        for (int i = 0; i <= num; i++)
        {
            if (v[i] != 1)
            {
                cout << 1;
                return;
            }
        }
        if (v[num] == 1)
        {
            cout << 2;
        }
        else{cout << 1;}
    }
    else
    {
        int index = 1;
        for (int i = 1; i < v.size(); i += 2)
        {
            if (v[i] != index)
            {
                cout << index;
                return;
            }
            index++;
        }
        cout << index;
        return;
    }
}

signed main()
{
    cin.tie(nullptr)->sync_with_stdio(false);
    int TT = 1;
    cin >> TT;
    while (TT--)
    {
        solve();
        cout << endl;
    }
}