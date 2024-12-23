#include <bits/stdc++.h>
using namespace std;
#define int long long
#define endl '\n'

signed main()
{
    // ios::sync_with_stdio(false);
    // cin.tie(0);
    // cout.tie(0);
    // 输入一个整数n
    int n;
    cin >> n;
    // 创建一个n*n的二维数组
    vector<vector<int>> arr(n, vector<int>(n));
    // 定义四个变量，分别表示数组的起始和结束位置
    int xbegin = 0, xend = n - 1, ybegin = 0, yend = n - 1, num = 1;
    // 当num小于等于n*n时，循环执行以下操作
    while (num <= n * n)
    {
        // 从左到右遍历数组的第一行，将num赋值给arr[xbegin][i]，并将num加1
        for (int i = ybegin; i <= yend; i++)
        {
            arr[xbegin][i] = num++;
        }
        // 将xbegin加1
        xbegin++;
        // 从上到下遍历数组的最后一列，将num赋值给arr[i][yend]，并将num加1
        for (int i = xbegin; i <= xend; i++)
        {
            arr[i][yend] = num++;
        }
        // 将yend减1
        yend--;
        // 从右到左遍历数组的最后一行，将num赋值给arr[xend][i]，并将num加1
        for (int i = yend; i >= ybegin; i--)
        {
            arr[xend][i] = num++;
        }
        // 将xend减1
        xend--;
        // 从下到上遍历数组的第一列，将num赋值给arr[i][ybegin]，并将num加1
        for (int i = xend; i >= xbegin; i--)
        {
            arr[i][ybegin] = num++;
        }
        // 将ybegin加1
        ybegin++;
    }
    // 遍历二维数组，输出每个元素
    for (const auto &arr1 : arr)
    {
        for (auto num1 : arr1)
        {
            printf("%3d", num1);
        }
        cout << endl;
    }
}