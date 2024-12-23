// #pragma GCC optimize(2)
#include <bits/stdc++.h>
using namespace std;
#define int long long
#define endl '\n'

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int n;
    cin >> n;
    char C = 'A';
    for (int i = 1;i<=n;i++)
    {
        char c = C;
        for (int j = 1; j <= n;j++)
        {
            cout << c;
            c++;
            if (c > 'Z')
            {
                c = 'A';
            }
        }
        cout << endl;
        C++;
        if (C > 'Z')
        {
            C = 'A';
        }
    }
}