#include <bits/stdc++.h>
using namespace std;
#define int long long
#define endl '\n'

// 判断一个数是否为素数
bool isPrime(int n)
{
    // 如果n小于2，则不是素数
    if (n < 2)
    {
        return 0;
    }
    // 如果n小于4，则是素数
    if (n < 4)
    {
        return 1;
    }
    // 从2开始遍历到n的平方根，判断n是否能被整除
    for (int i = 2; i <= n / i; i++)
    {
        // 如果能被整除，则不是素数
        if (n % i == 0)
        {
            return 0;
        }
    }
    // 否则是素数
    return 1;
}

// 判断一个字符串是否为幸运单词
int isLuckyWord(string str)
{
    // 初始化一个数组，用于存储每个字母出现的次数
    int values[26] = {};
    // 遍历字符串，统计每个字母出现的次数
    for (auto c : str)
    {
        values[c - 'a']++;
    }
    // 初始化最大值和最小值
    int maxnum = INT_MIN, minnum = INT_MAX;
    // 遍历数组，找到最大值和最小值
    for (auto num : values)
    {
        if (num != 0)
        {
            maxnum = max(maxnum, num);
            minnum = min(minnum, num);
        }
    }
    // 判断最大值和最小值的差是否为素数，如果是，则返回差值，否则返回0
    return isPrime(maxnum - minnum) ? (maxnum - minnum) : 0;
}

signed main()
{
    string str;
    // 输入一个字符串
    cin >> str;
    // 输出判断结果
    cout << (isLuckyWord(str) ? "Lucky Word" : "No Answer") << endl
         << isLuckyWord(str);
}
