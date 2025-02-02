//#pragma GCC optimize(2)
#include <bits/stdc++.h>
using namespace std;
#define int long long
#define endl '\n'

const int INF = 1e9;     // 无穷大
const int INFLL = 1e18; // 长整型无穷大
const int MOD = 1e9 + 7; // 模数

void solve()
{
    int n, q;
    cin >> n >> q;
    vector<int> father(n + 1);
    iota(father.begin(), father.end(), 0ll);
    vector<int> sz(n + 1, 1);
    int tot = 0;

    while (q--)
    {
        int num, num1, num2;
        cin >> num;
        if (num == 2)
        {
            cout << tot << endl;
        }
        else
        {
            cin >> num1 >> num2;

            sz[father[num1]]--;
            if (sz[father[num1]] == 1)
            {
                tot--;
            }

            father[num1] = num2;
            sz[father[num1]]++;
            if (sz[father[num1]] == 2)
            {
                tot++;
            }
        }
    }
}

signed main()
{
    cin.tie(nullptr)->sync_with_stdio(false);
    int TT = 1;
    // cin >> TT;
    while (TT--)
    {
        solve();
        cout << endl;
    }
}