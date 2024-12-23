#include <iostream>
using namespace std;
void Panduan(int n)
{
    int y = 0;
    for (int i = 2; i <= n; i++)
    {
        int is = 1;
        for (int j = 2; j < i; j++)
        {
            if (i % j == 0)
            {
                is = 0;
                break;
            }
        }
        if (is == 1)
        {
            y++;
        }
    }
    cout << y << endl;
    return;
}

int main()
{
    int T;
    cin >> T;
    int arr[T];
    for (int i = 0; i < T; i++)
    {
        cin >> arr[i];
    }
    for (int i = 0; i < T; i++)
    {
        Panduan(arr[i]);
    }
    return 0;
}
