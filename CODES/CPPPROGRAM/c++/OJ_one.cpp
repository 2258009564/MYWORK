#include <bits/stdc++.h>
using namespace std;
#define int long long
#define endl '\n'

// 判断一个数是否为质数
vector<int> isPrime(int n)
{
    // 创建一个布尔类型的向量，用于存储每个数是否为质数
    vector<bool> is_prime(n + 1, 1);
    // 0和1不是质数
    is_prime[0] = is_prime[1] = 0;
    // 创建一个整型向量，用于存储质数
    vector<int> prime;
    // 遍历从2到n的所有数
    for (int i = 2;i<=n;i++)
    {
        // 如果当前数是质数，则将其加入质数向量
        if(is_prime[i])
        {
            prime.push_back(i);
        }
        // 遍历质数向量中的所有质数
        for (int j = 0; j < prime.size() and prime[j] * i <= n;j++)
        {
            // 将当前质数与i的乘积标记为非质数
            is_prime[prime[j] * i] = 0;
            // 如果当前质数是i的因数，则跳出循环
            if (i % prime[j] == 0)
            {
                break;
            }
        }
    }
    // 返回质数向量
    return prime;
}

signed main() {
    
}