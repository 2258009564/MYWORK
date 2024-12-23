#include <bits/stdc++.h>
using namespace std;
#define int long long
#define endl '\n'

// 快速排序 基于分治
void quick_sort(vector<int> &vec, int left, int right)
{
    if (left >= right)
        return;

    // 选择基准元素（这里选择最左边的元素作为基准）
    int p = vec[left];
    int i = left, j = right;

    // 将数组分成两部分，小于基准的在左，大于基准的在右
    while (i < j)
    {
        // 找到第一个小于基准的元素
        while (vec[i] >= p)
        {
            i++;
        }
        // 找到第一个大于基准的元素
        while (vec[j] <= p)
        {
            j--;
        }

        if (i < j)
        {
            swap(vec[i], vec[j]);
        }
    }

    // 最后将基准元素交换到中间
    swap(vec[left], vec[i]);

    // 递归排序基准左边和右边的部分
    quick_sort(vec, left, i - 1);
    quick_sort(vec, i + 1, right);
}

signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
}
