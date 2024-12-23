// #pragma GCC optimize(2)
#include <bits/stdc++.h>
using namespace std;
#define int long long
#define endl '\n'

// 用于将数字转换成对应的字符
char convertDigit(int num)
{
    if (num < 10)
        return '0' + num; // 数字 0-9
    else
        return 'A' + (num - 10); // 字母 A-Z
}

string decimalToBase(int N, int R)
{
    string result;
    while (N > 0)
    {
        int remainder = N % R;
        result += convertDigit(remainder);
        N /= R;
    }
    reverse(result.begin(), result.end()); // 因为结果是逆序的
    return result;
}

signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int N, R;
    cin >> N >> R;
    cout << decimalToBase(N, R) << endl;
}
