// #pragma GCC optimize(2)
#include <bits/stdc++.h>
using namespace std;
#define int long long
#define endl '\n'
#define all(x) (x).begin(), (x).end()

const int INF = 1e9;     // 无穷大
const int INFLL = 1e18;  // 长整型无穷大
const int MOD = 1e9 + 7; // 模数
// -9.2e18 ~ 9.2e18

void solve()
{
    int n;
    cin >> n;
    string s;
    cin >> s;

    // 初始化前缀和数组
    vector<vector<int>> preeven(n + 1, vector<int>(26, 0));
    vector<vector<int>> preodd(n + 1, vector<int>(26, 0));

    // 计算前缀和
    for (int i = 0; i < n; i++)
    {
        preeven[i + 1] = preeven[i];
        preodd[i + 1] = preodd[i];

        int c = s[i] - 'a';
        if ((i + 1) % 2 == 0)
        {
            preeven[i + 1][c]++;
        }
        else
        {
            preodd[i + 1][c]++;
        }
    }

    // 偶数长度的特殊情况
    if (n % 2 == 0)
    {
        cout << n - ranges::max(preeven[n]) - ranges::max(preodd[n]);
        return;
    }

    int ans = INF;
    for (int i = 0; i <= n; i++)
    {
        vector<int> even_count(26, 0), odd_count(26, 0);

        for (int j = 0; j < 26; j++)
        {
            even_count[j] = preeven[i][j];
            odd_count[j] = preodd[i][j];
        }

        for (int j = 0; j < 26; j++)
        {
            even_count[j] += preeven[n][j] - preeven[i][j];
            odd_count[j] += preodd[n][j] - preodd[i][j];
            if (i % 2 == 1)
            {
                swap(even_count[j], odd_count[j]);
            }
        }

        int curr_ans = n - ranges::max(even_count) - ranges::max(odd_count);
        ans = min(ans, curr_ans);
    }

    cout << ans;
}

signed main()
{
    cin.tie(nullptr)->ios::sync_with_stdio(false);
    cout << setiosflags(ios::fixed) << setprecision(2);
    int TT = 1;
    cin >> TT;
    while (TT--)
    {
        solve();
        cout << endl;
    }
}