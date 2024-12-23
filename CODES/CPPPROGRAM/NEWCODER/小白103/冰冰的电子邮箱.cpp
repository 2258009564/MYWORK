#pragma GCC optimize(2)
#include <bits/stdc++.h>
using namespace std;
#define int long long
#define endl '\n'

bool isValidEmail(const string &s)
{
    size_t atPos = s.find('@');
    if (atPos == string::npos || atPos == 0 || atPos == s.size() - 1)
        return false;

    string localPart = s.substr(0, atPos);
    string domain = s.substr(atPos + 1);

    if (localPart.length() < 1 || localPart.length() > 64 || domain.length() < 1 || domain.length() > 255)
        return false;

    if (localPart.front() == '.' || localPart.back() == '.' || domain.front() == '.' || domain.front() == '-' || domain.back() == '.' || domain.back() == '-')
        return false;

    for (char c : localPart)
        if (!(isalnum(c) || c == '.' || c == '-'))
            return false;

    for (char c : domain)
        if (!(isalnum(c) || c == '.' || c == '-'))
            return false;

    return true;
}

signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int t;
    cin >> t;
    while (t--)
    {
        string email;
        cin >> email;
        cout << (isValidEmail(email) ? "Yes" : "No") << endl;
    }
}
