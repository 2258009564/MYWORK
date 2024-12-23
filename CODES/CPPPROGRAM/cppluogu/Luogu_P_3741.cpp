#include <iostream>
#include <iomanip>
#include <algorithm>
#include <string>
using namespace std;
int main()
{
    int n, c = -1, cnt = 0;
    string s, a = "VK";
    cin >> n >> s;
    while (s.find(a, c + 1) != -1)
    {
        cnt++;
        int t = s.find(a, c + 1);
        s[t] = 'T';
        s[t + 1] = 'T';
        c = t;
    }
    for (int i = 0; i < s.length() - 1; i++)
    {
        string w = "KK";
        string e = "VV";
        if (s.find(w) != -1)
        {
            cnt++;
            break;
        }
        if (s.find(e) != -1)
        {
            cnt++;
            break;
        }
    }

    cout << cnt;
}