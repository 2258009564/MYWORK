#include <bits/stdc++.h>
using namespace std;
#define int long long
#define endl '\n'

void solve()
{
    int k;
    cin >> k;

    if (k == 0)
    {
        cout << "1\n0 0\n";
        return;
    }

    // 构造"L"形状
    // 找到合适的n和m使得(n+1)*m = k
    int n = sqrt(k); // 初始估计
    while ((n + 1) * (k / (n + 1)) != k)
    {
        n--;
        if (n < 0)
            n = sqrt(k);
    }

    int m = k / (n + 1);
    cout << n + 1 + m << endl; // 总点数

    // 输出水平线上的点
    for (int i = 0; i <= n; i++)
    {
        cout << i << " 0\n";
    }

    // 输出垂直线上的点（不包括原点）
    for (int i = 1; i <= m; i++)
    {
        cout << "0 " << i << "\n";
    }
}

signed main()
{
    cin.tie(0)->ios::sync_with_stdio(0);
    int T;
    cin >> T;
    while (T--)
        solve();
    return 0;
}