#include <bits/stdc++.h>
using namespace std;
#define int long long
#define endl '\n'

// 判断一个数是否为素数
bool isPrime(int n){
    if(n<=3){
        return 1;
    }
    // 创建一个长度为n+1的数组，初始值为1
    vector<int> isprime(n + 1, 1);
    // 从2开始遍历到n/i
    for (int i = 2; i <= n / i;i++)
    {
        // 如果i是素数
        if(isprime[i]){
            // 将i的倍数标记为非素数
            for (int j = i * i; j <= n;j+=i){
                isprime[j] = 0;
            }
        }
    }
    // 返回n是否为素数
    return isprime[n];
}

signed main() {
    int n, k,num;
    // 输入n和k
    cin >> n >> k;
    // 创建一个长度为n的数组
    vector<int> nums(n);
    // 输入数组nums
    for(auto &num:nums)
    {
        cin >> num;
    }
    // 创建一个长度为n的数组，初始值为0
    vector<int> binary_mask(n, 0);
    // 将binary_mask的最后k个元素置为1
    fill(binary_mask.begin() + n - k, binary_mask.end(), 1);
    // 初始化total为0
    int total = 0;
    // 使用next_permutation函数生成binary_mask的所有排列
    do{
        // 初始化sum为0
        int sum = 0;
        // 遍历binary_mask
        for (int i = 0; i < n;i++){
            // 如果binary_mask[i]为1，则将nums[i]加到sum中
            if(binary_mask[i]==1)
            {
                sum += nums[i];
            }
        }
        // 如果sum是素数，则total加1
        if(isPrime(sum)){
            total++;
        }
    } while (next_permutation(binary_mask.begin(), binary_mask.end()));
    // 输出total
    cout << total;
}