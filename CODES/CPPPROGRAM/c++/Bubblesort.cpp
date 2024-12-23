# include <bits/stdc++.h>
using namespace std;

void Bubblesort(int a[],int len)//从小到大
{
    for (int i = 0; i < len; i++)//执行len次
    {
        for (int j  = 0; j < len-1; j++)//主体部分
        //
        {
            if (a[j] > a[j+1])
            {
                //交换位置
                int temp = a[j];
                a[j] = a[j + 1];
                a[j + 1] = temp;
            }
            
        }
        
    }
    return;
}
int main()
{
    int arr[5];
    for (int i = 0; i < 5; i++)
    {
        cin >> arr[i];
    }
    Bubblesort(arr, 5);
    for (int i = 0; i < 5; i++)
    {
        cout << arr[i]<<" ";
    }
    return 0;
}