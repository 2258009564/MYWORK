#include <bits/stdc++.h>
using namespace std;
// 判断质数，直接运行即可

bool PrimeJudgement(int a)
{
    for (int i = 2; i * i <= a; i++)
    {
        if (a % i == 0)
            return false;
    }
    return true;
}

int PrimeTotal(int a)
{
    int total = 0;
    for (int j = 2; j <= a; j++)
    {
        if (PrimeJudgement(j))
        {
            total++;
        }
    }

    return total;
}

int main()
{
    int num, num1 = 0;
    cout << "这是一个简易的质数检测器" << endl
         << "请输入一个整数(输入-1以退出)：";
    while (true)
    {
        cin >> num;
        if (num == -1)
        {
            cout << "byebye!";
            if (num1 == 0)
                cout << "怎么一次都不玩就走了！";
            else if (num1 <= 3)
                cout << "怎么才玩" << num1 << "次就走了！";
            else
            {
                cout << "你这次玩了" << num1 << "次，觉得程序怎么样？";
            }
            break;
        }
        else
        {
            num1++;

            if (PrimeJudgement(num)) // 判断num是否为质数
                cout << num << "是个质数" << endl;
            else
                cout << num << "不是质数" << endl;

            int total_of_num = PrimeTotal(num);
            cout << num << "及之前共有" << total_of_num << "个质数" << endl
                 << "请继续输入，输入-1以退出：";
        }
    }
    system("pause");
    return 0;
}