#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cin >> n;
    vector<int> vec(n);
    for (auto &num : vec)
    {
        cin >> num;
    }
    int s;
    cin >> s;
    int i = 0, j = 0, sum = vec[0];
    while (j < n)
    {
        while (sum > s && i <= j)
        {
            sum -= vec[i];
            i++;
        }
        if (sum == s)
        {
            cout << i << " " << j << endl;
        }
        sum += vec[j];
        j++;
    }
}