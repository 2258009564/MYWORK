#include <bits/stdc++.h>
using namespace std;
#define int long long
#define endl '\n'

// 判断一个数是否为回文数
bool isPalindrome(int n)
{
    string str = to_string(n);       // 将整数转换为字符串
    int lf = 0, ri = str.size() - 1; // 定义左右指针
    while (lf <= ri)                 // 遍历字符串
    {
        if (str[lf++] != str[ri--]) // 如果左右指针指向的字符不相等，则不是回文数
        {
            return 0;
        }
    }
    return 1; // 如果左右指针指向的字符都相等，则是回文数
}

// 判断一个数是否为素数
bool isPrime(int n)
{
    if (n == 0 or n == 1) // 如果是0或1，则不是素数
    {
        return 0;
    }
    if (n == 2 or n == 3) // 如果是2或3，则是素数
    {
        return 1;
    }
    vector<bool> isprime(n + 1, 1);  // 定义一个布尔类型的数组，用于存储每个数是否为素数
    for (int i = 2; i <= n / i; i++) // 遍历从2到n的平方根的数
    {
        if (isprime[i]) // 如果当前数是素数
        {
            for (int j = i * i; j <= n; j += i) // 将当前数的倍数标记为非素数
            {
                isprime[j] = 0;
            }
        }
    }
    return isprime[n]; // 返回当前数是否为素数
}

signed main()
{
    int left, right;
    cin >> left >> right;               // 输入左右边界
    for (int i = left; i <= right; i++) // 遍历左右边界之间的数
    {
        if (i % 2 != 0) // 如果当前数是奇数
        {
            if (isPalindrome(i)) // 如果当前数是回文数
            {
                if (isPrime(i)) // 如果当前数是素数
                {
                    printf("%d\n", i); // 输出当前数
                }
            }
        }
    }
}