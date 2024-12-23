#include <bits/stdc++.h>
using namespace std;

int main()
{
    vector<int> vec1;

    // 增：向 vec1 添加元素
    vec1.push_back(1);                    // 添加 1 -> [1]
    vec1.push_back(2);                    // 添加 2 -> [1, 2]
    vec1.insert(vec1.begin() + 1, 233);   // 在索引 1 处插入 233 -> [1, 233, 2]
    vec1.insert(vec1.begin(), 123456789); // 在开头插入 123456789 -> [123456789, 1, 233, 2]

    // 输出当前所有元素
    for (int num : vec1)
    {
        cout << num << endl;
    }

    // 查：通过索引访问元素
    cout << vec1[1] << endl;     // 输出索引 1 的元素：233
    cout << vec1.size() << endl; // 输出当前大小：4

    // 删：移除最后一个元素
    vec1.pop_back();                            // 移除 2 -> [123456789, 1, 233]
    vec1.erase(vec1.begin(), vec1.begin() + 1); // 移除索引 0 的元素 -> [1, 233]

    vec1.clear(); // 清空所有元素 -> []

    // 改：调整大小并初始化为 1
    vec1.resize(10, 1); // 调整大小为 10，初始化为 1 -> [1, 1, 1, 1, 1, 1, 1, 1, 1, 1]
    for (int i = 0; i < vec1.size(); i++)
    {
        vec1[i] = i; // 用索引值填充 vec1 -> [0, 1, 2, 3, 4, 5, 6, 7, 8, 9]
    }

    // 输出最终所有元素
    for (auto num : vec1)
    {
        cout << num << " ";
    }

    return 0;
}
