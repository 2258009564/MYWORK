// #pragma GCC optimize(2)
#include <bits/stdc++.h>
using namespace std;
#define int long long
#define endl '\n'

signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    double p1, p2, p3, p4, p5;
    cin >> p1 >> p2 >> p3 >> p4 >> p5;
    // 一个都没抽到 或者 只抽到一个
    // 一个都没抽到
    double p = p1 + p2 + p3;
    double P0 = pow(p, 10);
    double P1 = 10 * pow(p, 9) * (p4 + p5);
    cout << fixed << setprecision(14) << 1 - (P0 + P1);
}