#include <bits/stdc++.h>
using namespace std;

int randint(int n)
{
    return (rand() % (n + 1));
}
int main(){
    int randint_num = randint(100) , a;
    cout << "随机数猜测：请输入一个数字(1~100)";
    cin >> a;
    while (true)
    {
        if (a > randint_num)
        {
            cout << "猜大了，请重新输入：";
            cin >> a;
        }else if (a < randint_num){
            cout << "猜小了，请重新输入：";
            cin >> a;
        }else{
            cout << "恭喜你猜对了！答案就是："<< randint_num;
            break;
        }
        
    }
    
}