#include <bits/stdc++.h>
using namespace std;
struct node // 结构体排序
{
    string s;         // 名字
    int n, y, r, num; // 年，月，日，输入的编号。
} a[110];
int n;
bool cmp(node a, node b)
{
    if (a.n < b.n)
        return 1; // 先比年
    if (a.n > b.n)
        return 0;
    if (a.n == b.n)
    {
        if (a.y < b.y)
            return 1; // 再比月
        if (a.y > b.y)
            return 0;
        if (a.y == b.y)
        {
            if (a.r < b.r)
                return 1; // 再比日
            if (a.r > b.r)
                return 0;
            if (a.r == b.r)
            {
                if (a.num > b.num)
                    return 1; // 最后比编号
                else
                    return 0;
            }
        }
    }
}
int main()
{
    cin >> n;
    for (int i = 1; i <= n; i++)
        cin >> a[i].s >> a[i].n >> a[i].y >> a[i].r, a[i].num = i; // 输入
    sort(a + 1, a + n + 1, cmp);                                   // 快排
    for (int i = 1; i <= n; i++)
        cout << a[i].s << endl; // 输出。
    return 0;
}
