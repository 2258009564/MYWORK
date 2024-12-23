// #pragma GCC optimize(2)
#include <bits/stdc++.h>
using namespace std;
#define int long long
#define endl '\n'

/*
回溯三部曲
递归函数参数返回值
确定终止条件
单层递归逻辑
*/

signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    void backtracking(/*参数*/) // 树的深度要放在这个位置
    {
        if (/*终止条件*/) // 树到达了最深处
        {
            /*存放结果 比方说把path压入result */
            return;
        }
        for (/*选择：本层集合中的元素(树中节点孩子的数量就是集合的大小) */)
        {
            /*
            处理节点 比方说把集合中的元素存入path
            */
            backtracking(/*路径，选择列表*/); // 递归，把树的深度推一层
            /*
            回溯，撤销处理结果 刚刚怎么压入的现在就怎么弹出
            */
        }
    }
}