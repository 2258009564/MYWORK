#include <bits/stdc++.h>
using namespace std;
#define int long long

// 判断一个数是否为素数
bool isPrime(int n)
{
    // 创建一个长度为n+1的布尔型向量，初始值为1
    vector<bool> isprime(n + 1, 1);
    // 将0和1标记为非素数
    isprime[0] = isprime[1] = 0;
    // 从2开始遍历到n/i
    for (int i = 2; i <= n / i; i++)
    {
        // 如果i是素数
        if (isprime[i])
        {
            // 将i的倍数标记为非素数
            for (int j = i; j <= n; j += i)
            {
                isprime[j] = 0;
            }
        }
    }
    // 返回n是否为素数
    return isprime[n];
}

signed main()
{
    int n, m, total = 0;
    // 输入两个整数n和m
    cin >> n >> m;
    // 遍历n到m之间的所有数
    for (int i = n; i <= m; i++)
    {
        // 如果i是素数，则total加1
        if (isPrime(i))
        {
            total++;
        }
    }
    // 输出total的值
    cout << total;
}