#include <bits/stdc++.h>
#include "Qiucjsort.h"
using namespace std;

// 快速排序算法
int Partition(int a[], int left, int right) // 形式参数
{
    int pivot = a[left];
    while (left < right)
    {
        while ((a[right] >= pivot) && (left < right))
        {
            right--;
        }
        a[left] = a[right];
        while ((a[left] <= pivot) && (left < right))
        {
            left++;
        }
        a[right] = a[left];
    }
    a[left] = pivot;
    return left;
}

void Quicksort(int a[], int left, int right)
{
    if (left < right)
    {
        int pivotpos = Partition(a, left, right);
        Quicksort(a, left, pivotpos - 1);
        Quicksort(a, pivotpos + 1, right);
    }
    return;
}
int main()
{
    int arr[10];
    for (int i = 0; i < 10; i++)
    {
        cin >> arr[i];
    }
    Quicksort(arr, 0, 9); // 实参 实际参数
    for (int i = 0; i < 10; i++)
    {
        cout << arr[i] << " ";
    }
    return 0;
}