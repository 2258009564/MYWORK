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
    string str;
    cin >> str;
    for (auto c : str)
    {
        cout << arr[c - 'A'] << " ";
    }
}
