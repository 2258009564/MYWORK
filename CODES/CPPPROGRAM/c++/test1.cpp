#include <bits/stdc++.h>
using namespace std;
#define int long long
#define endl '\n'

signed main()
{
    // ————————顺序容器
    vector<int> vec;
    vec.push_back(1);
    vec.pop_back();
    int a = vec.size();
    vec.clear();
    vec.empty();
    vec.resize(3, 1);

    // ————————关联容器
    set<int, less<int> /*默认就这个*/> st;
    st.insert(1);
    st.erase(2);
    auto it = st.find(2);
    st.count(3);
    // 查看大小 / 清空 / 判空 略

    map<int, int, less<int> /*默认就这个*/> mp;


    // ————————容器适配器
    stack<int> stk;
    stk.push(1);
    stk.pop();
    int a = stk.top();
    // 查看大小 / 清空 / 判空 略

    queue<int> que;
    que.push(1);
    que.pop();
    int a = que.front();
    int a = que.back();
    // 查看大小 / 清空 / 判空 略
    priority_queue<int, vector<int> /*存储数据用的底层容器 保持默认即可*/, less<int> /*比较器 默认就是less*/> pque;
    pque.push(1);
    pque.pop();
    int a = pque.top();
    // 查看大小 / 清空 / 判空 略 (清空好像无法直接实现)

    // ————————字符串
    string str;

    // 对与元组
    pair<int, int> pr = {1, 'a'};
}