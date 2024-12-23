#include <iostream>
using namespace std;

int main()
{
    int n; // 题目数量
    cin >> n;
    int count = 0; // 用于计数符合条件的题目

    // 遍历每个问题
    for (int i = 0; i < n; i++)
    {
        int p, v, t; // Petya, Vasya, Tonya 的看法
        cin >> p >> v >> t;

        // 判断是否至少有两个确定
        if (p + v + t >= 2)
        {
            count++; // 符合条件的题目计数
        }
    }

    // 输出结果
    cout << count << endl;
    return 0;
}
