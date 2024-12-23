#include <bits/stdc++.h>
using namespace std;

void Bucketsort(int a[], int len)
{
    int b[10000];
    for (int i = 0; i < 10000; i++)
    {
        b[i] = 0;
    }
    for (int i = 0; i < len; i++)
    {
        b[a[i]]++; // b[9999] = 2
    }
    for (int i = 0; i < 10000; i++)
    {
        for (int j = 0; j < b[i]; j++)
        {
            cout << i << " ";
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
    Bucketsort(arr, 5);
    return 0;
}