#include <bits/stdc++.h>
using namespace std;
#define int long long

/*
链接：https://ac.nowcoder.com/acm/contest/98256/C
来源：牛客网

题目描述
小红希望你构造一个由
𝑎
a个'0'、
𝑏
b个'1'组成的01串，该01串有恰好
𝑘
k对相邻的字符不同。
输入描述:
第一行一个整数
𝑡
t，表示测试样例数。
接下来
𝑡
t行，每行三个整数
𝑎
,
𝑏
,
𝑘
a,b,k，用空格隔开。
1
≤
𝑡
≤
1
0
4
1≤t≤10
4

0
≤
𝑎
,
𝑏
,
𝑘
≤
1
0
5
0≤a,b,k≤10
5

𝑎
+
𝑏
>
0
a+b>0
保证所有测试样例的
𝑎
+
𝑏
a+b的和不超过
5
×
1
0
5
5×10
5
 。
输出描述:
对于每组测试样例，如果无解，请输出-1。
否则输出一个长度为
𝑎
+
𝑏
a+b的01串。有多解时输出任意即可。
示例1
输入
复制
2
2 3 3
1 1 1
输出
复制
01011
01
说明
对于第一组样例，输出11010也是可以的。
*/

signed main()
{
    int t;
    cin >> t;
    int sz0, sz1, k;
    string s;
    while (t--)
    {
        s.clear();
        bool flag = 1;

        cin >> sz0 >> sz1 >> k;

        if (k == 0)
        {
            if (sz1 and sz0)
            {
                cout << -1 << endl;
                continue;
            }
        }

        int sz = k + 1;
        if (sz % 2 == 0)
        {
            sz0 -= sz / 2;
            sz1 -= sz / 2;

            if (sz0 < 0 or sz1 < 0)
            {
                flag = 0;
            }
            if (flag)
            {
                for (int i = 1; i <= sz0; i++)
                {
                    s += '0';
                }

                for (int i = 1; i <= sz / 2; i++)
                {
                    s += "01";
                }

                for (int i = 1; i <= sz1; i++)
                {
                    s += '1';
                }
            }
        }
        else
        {
            sz -= 1;
            sz0 -= sz / 2;
            sz1 -= sz / 2;

            if (sz0 < 0 or sz1 < 0)
            {
                flag = 0;
            }
            if (flag)
            {
                for (int i = 1; i <= sz / 2; i++)
                {
                    s += "01";
                }

                for (int i = 1; i <= sz1; i++)
                {
                    s += '1';
                }

                for (int i = 1; i <= sz0; i++)
                {
                    s += '0';
                }

                if (s.size() > 0 && s[s.size() - 1] == '1' && sz0 > 0)
                {
                    flag = 0;
                }
            }
        }

        cout << (flag ? s : "-1") << endl;
    }
}