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
    int n, w;
    cin >> n >> w;

    set<int> st;
    vector<vector<int>> v(w + 1, vector<int>(1e9 + 1));
    unordered_map<int, int> mp;

    for (int i = 1; i <= n; i++)
    {
        int x, y;
        cin >> x >> y;

        st.insert(i);
        v[x - 1][y - 1] = i;
    }

    int q;
    cin >> q;
    while (q--)
    {
        
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