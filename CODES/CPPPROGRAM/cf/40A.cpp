#include <bits/stdc++.h>
using namespace std;
#define int long long
#define endl '\n'

signed main()
{
    int x, y;
    cin >> x >> y;

    int distSquared = x * x + y * y;

    int sqrtDist = sqrt(distSquared);
    if (sqrtDist * sqrtDist == distSquared)
    {
        cout << "black" << endl;
        return 0;
    }

    int d = static_cast<int>(sqrt(distSquared));

    if (x >= 0 && y >= 0 || x <= 0 && y <= 0)
    { 
        if (d % 2 == 0)
        {
            cout << "black" << endl;
        }
        else
        {
            cout << "white" << endl;
        }
    }
    else
    { 
        if (d % 2 == 0)
        {
            cout << "white" << endl;
        }
        else
        {
            cout << "black" << endl;
        }
    }
}
