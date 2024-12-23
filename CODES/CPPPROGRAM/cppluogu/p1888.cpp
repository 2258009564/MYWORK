#include <bits/stdc++.h>
using namespace std;

int main()
{
    int arr[3];
    for (auto &num : arr)
    {
        cin >> num;
    }
    sort(arr, arr + 3);
    int end_num = gcd(arr[0], arr[2]);
    cout << arr[0] / end_num << '/' << arr[2] / end_num;
}