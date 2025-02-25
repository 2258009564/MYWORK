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
    vector<int> v(3);
    for (int i = 0; i < 3; i++)
    {
        cin >> v[i];
    }

    ranges::sort(v);
    int a = v[0], b = v[1], c = v[2];

    if (a + b <= c) // 两边和不大于第三边 构不成三角形
    {
        cout << "Not triangle" << endl;
    }
    else // 可以构成三角形
    {
        //先判断角度大小
        if (a * a + b * b == c * c)
        {
            cout << "Right triangle" << endl;
        }
        else if (a * a + b * b < c * c)
        {
            cout << "Obtuse triangle" << endl;
        }
        else // a * a + b * b > c * c
        {
            cout << "Acute triangle" << endl;
        }

        // 判断有没有可能是等腰
        if (a == b)
        {
            cout << "Isosceles triangle" << endl;

            // 在等腰基础上有没有可能是等边
            if (b == c)
            {
                cout << "Equilateral triangle" << endl;
            }
        }
    }
}

signed main()
{
    cin.tie(nullptr)->ios::sync_with_stdio(false);
    cout << setiosflags(ios::fixed) << setprecision(2);
    int TT = 1;
    // cin >> TT;
    while (TT--)
    {
        solve();
        cout << endl;
    }
}