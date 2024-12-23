#include <bits/stdc++.h>
using namespace std;
#define int long long
#define endl '\n'

// 合并两个子数组的函数
void merge(vector<int> &arr, int left, int mid, int right)
{
    vector<int> temp;
    int i = left, j = mid + 1;

    // 合并两个子数组
    while (i <= mid && j <= right)
    {
        if (arr[i] <= arr[j])
        {
            temp.push_back(arr[i++]);
        }
        else
        {
            temp.push_back(arr[j++]);
        }
    }

    // 复制剩余的元素
    while (i <= mid)
        temp.push_back(arr[i++]);
    while (j <= right)
        temp.push_back(arr[j++]);

    // 将合并后的结果复制回原数组
    for (int k = 0; k < temp.size(); k++)
    {
        arr[left + k] = temp[k];
    }
}

// 归并排序的递归函数
void mergeSort(vector<int> &arr, int left, int right)
{
    if (left < right)
    {
        int mid = left + (right - left) >> 1;
        mergeSort(arr, left, mid);      // 排序左半部分
        mergeSort(arr, mid + 1, right); // 排序右半部分
        merge(arr, left, mid, right);   // 合并
    }
}

signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    vector<int> arr = {38, 27, 43, 3, 9, 82, 10};

    cout << "Before sorting: ";
    for (auto &x : arr)
        cout << x << " ";
    cout << endl;

    mergeSort(arr, 0, arr.size() - 1);

    cout << "After sorting: ";
    for (auto &x : arr)
        cout << x << " ";
    cout << endl;

    return 0;
}
