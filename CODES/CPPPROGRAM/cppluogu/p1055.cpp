#include <bits/stdc++.h>
using namespace std;

signed main()
{
    string str;
    int total = 0, k = 1;
    cin >> str;

    // 遍历字符串的每个字符（不包括最后一个字符）
    for (size_t i = 0; i < str.size() - 1; i++)
    {
        if (isdigit(str[i])) // 检查字符是否是数字
        {
            total += (str[i] - '0') * k++; // 计算加权和
        }
    }

    total %= 11;
    char end_num = (total == 10) ? 'X' : (total + '0');

    // 检查最后一个字符是否相等
    if (str[str.size() - 1] == end_num)
    {
        cout << "Right"; // 输出 "Right"
    }
    else
    {
        str[str.size() - 1] = end_num; // 替换最后一个字符
        cout << str;                   // 输出修改后的字符串
    }

    return 0;
}
