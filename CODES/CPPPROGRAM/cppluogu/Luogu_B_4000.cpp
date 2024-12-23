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
    int h, m, s, k;
    cin >> h >> m >> s >> k;
    s += k;
    int s1 = s / 60;
    s %= 60;
    m += s1;
    int m1 = m / 60;
    m %= 60;
    h += m1;
    cout << h << ' ' << m << ' ' << s;
}