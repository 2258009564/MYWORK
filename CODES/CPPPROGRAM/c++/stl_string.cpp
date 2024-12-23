#include <bits/stdc++.h>
using namespace std;

int main()
{
    // 创建
    string str1 = "hello!";
    string str2(10, '6'); // 十个6
    string str3;          // 构造一个空的字符串
    string str4(str2);    // copy了str2
    // 以上四种创建方式没有优劣之分 灵活使用即可

    // 输入输出
    /*使用cin给string赋值的时候 会获取空格分隔的元素
    如果想获取包括空格在内的一整行 请如下使用 */

    getline(cin, str3, '\n');

    // 字符串拼接 只需使用+或者+=即可
    str1 = str2 + str4;
    str1 += str2;

    // 字符的查找 ———— find(str)和str.find()的区别
    str1.find("你想寻找的字符串/字符");
    /*
    返回一个整数 从0开始 如果没找到会返回-1
    这是string独有的
    */
    find(str1.begin(), str1.end(), '1');
    /*
    查找单个元素在容器中的位置 这是stl通用的 .begin()和.end()是迭代器
    返回的结果同样是一个迭代器
    我们可以通过distance函数来确定返回的结果到.begin()的距离 从而得到一个整数
    */
   
}
