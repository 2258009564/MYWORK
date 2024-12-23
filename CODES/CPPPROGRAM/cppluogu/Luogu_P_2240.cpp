#include <bits/stdc++.h>
using namespace std;
#define int long long
#define endl '\n'

auto main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int n, t;
    cin >> n >> t;

    vector<pair<double, double>> mp(n);
    for (auto &&v : mp)
    {
        cin >> v.first >> v.second;
    }

    sort(mp.begin(), mp.end(), [](pair<double, double> pr1, pair<double, double> pr2)
         { return pr1.second / pr1.first > pr2.second / pr2.first; });

    double weighttotal = 0, valuesum = 0;

    for (auto &&v : mp)
    {
        if (weighttotal + v.first > t)
        {
            double moreweight = t - weighttotal;
            valuesum += (moreweight / v.first) * v.second;
            cout << fixed << setprecision(2) << valuesum;
            return 0;
        }

        weighttotal += v.first;
        valuesum += v.second;
    }

    cout << fixed << setprecision(2) << valuesum;
}
