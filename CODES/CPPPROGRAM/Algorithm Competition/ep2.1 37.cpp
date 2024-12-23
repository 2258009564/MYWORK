#include <bits/stdc++.h>
using namespace std;

int main(){
    int n,k;
    cin >> n >> k;
    int m = n;
    vector<int> vec;
    //输入数组
    while(m--){
        int a;
        cin >> a;
        vec.push_back(a);
    }
    //sort first
    sort(vec.begin(), vec.end());
    // Create two scanning pointers.
    int i = 0, j = n - 1;
    while(i<j){
        int sum = vec[i] + vec[j];
        //judge if sum equals k
        if(sum>k){
            j--;
        }
        if(sum<k){
            i++;
        }
        if(sum==k){
            cout << vec[i] << " " << vec[j] << endl;
            i++;
        }
    }
}
/*
是的，尺取法（Two-pointer technique）是一种常用的算法技巧，特别适用于有序数组或链表的相关问题。它通过两个指针分别指向序列的两端，或在序列中进行扫描，从而有效地减少了时间复杂度。这个方法常用于寻找和、差等条件的组合。

在你的代码中，使用尺取法来寻找和为 k 的数对非常合适，因为排序后的数组允许你通过移动指针来逐步逼近目标和。
*/