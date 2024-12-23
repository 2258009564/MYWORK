#include <bits/stdc++.h>
using namespace std;
#define int long long
#define endl '\n'

signed main()
{
    // 输入一个整数l
    int l;
    cin >> l;
    // 创建一个大小为l+1的向量，初始值为1
    vector<int> vec(l + 1, 1);
    // 输入一个整数m
    int m, a, b;
    cin >> m;
    // 循环m次
    while (m--)
    {
        // 输入两个整数a和b
        cin >> a >> b;
        // 将向量vec中从a到b的元素都置为0
        for (int i = a; i <= b; i++)
        {
            vec[i] = 0;
        }
    }
    // 初始化一个变量total为0
    int total = 0;
    // 遍历向量vec，将所有元素相加
    for (auto num : vec)
    {
        total += num;
    }
    // 输出total
    cout << total;
}