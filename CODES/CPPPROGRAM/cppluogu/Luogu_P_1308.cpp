#include <bits/stdc++.h>
using namespace std;
#define int long long
#define endl '\n'

signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    string str;
    cin >> str;

    // 将目标字符串转换为小写
    for (auto &c : str)
    {
        if (c >= 'A' and c <= 'Z')
        {
            c = c - 'A' + 'a';
        }
    }

    // 读取整行作为要查找的文本
    string line;
    cin.ignore(); // 清除前一个 cin 后的换行符
    getline(cin, line);
    
    // 将 line 转换为小写
    for (auto &c : line)
    {
        if (c >= 'A' and c <= 'Z')
        {
            c = c - 'A' + 'a';
        }
    }

    int size1 = str.size();
    bool foundalready = false;
    int index = -1, total = 0;

    // 遍历 line，查找与 str 匹配的子串
    for (int i = 0; i <= line.size() - size1; i++)
    {
        bool found = 1;
        for (int j = 0; j < size1; j++)
        {
            if (line[i + j] != str[j])
            {
                found = 0;
                break;
            }
        }
        if (line[i + size1] != ' ' or (i > 0 and line[i - 1] != ' '))
        {
            found = 0;
        }
        if (found)
        {
            total++;
            if (!foundalready)
            {
                index = i;
                foundalready = 1;
            }
        }
    }

    // 输出结果
    if (total > 0)
    {
        cout << total << ' ' << index;
    }
    else
    {
        cout << -1;
    }
}
