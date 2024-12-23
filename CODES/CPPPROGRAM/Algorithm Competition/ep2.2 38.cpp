#include <bits/stdc++.h>
using namespace std;

int main(){
    int n;
    cin >> n; // do not forget to input.
    while(n--){
        string str;
        cin >> str;
        // create two Bidirectional pointers.
        int Size = str.size();
        int i = 0, j = Size - 1;
        //main func
        bool judge = true;
        while(i<j){
            if(str[i++]!=str[j--]){
                judge = false;
                break;
                // Exit the program to reduce memory usage.
            }
        }
        if(judge){
            cout << "yes" << endl;
        }else{
            cout << "no" << endl;
        }
    }
}