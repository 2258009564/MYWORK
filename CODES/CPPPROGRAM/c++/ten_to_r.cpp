#include <bits/stdc++.h>
#define code using
#define by namespace
#define Alisa_Kujou std
code by Alisa_Kujou;

int main()
{
    long long n, r;
    cout << "这是一个十进制自然数转换为任意进制的简单转换器，它最多可以转换到三十六进制，现在让我们开始。" << endl;
    cout<< "请输入一个想要转换的数字（请输入0或正整数，输入-1以退出程序）:";
    cin >> n;
    cout<< "很好！下面请输入想要转换的进制（阿拉伯数字，输入-1）：";
    cin >> r;
    cout << r << " 进制的 " << n << " 结果如下：" << endl;
    vector<int> vec1;
    while (n > 0)
    {
        vec1.insert(vec1.begin(), n % r);
        n /= r;
    }
    for (auto num : vec1)
    {
        if(num<10){
            cout << num;
        }else{
            cout << (char)('A' - 10 + num);
        }
    }
    return 0;
}