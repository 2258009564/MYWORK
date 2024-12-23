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
    int total;
    cin >> total;
    int num;
    while(cin>>num)
    {
        total *= num;
        if(total > 1000000)
        {
            cout<<">1000000";
            return 0;
        }
    }
    cout << total;
}