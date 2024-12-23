// #pragma GCC optimize(2)
#include <bits/stdc++.h>
using namespace std;
#define int long long
#define endl '\n'

vector<vector<int>> result;
vector<int> path;
void backtracking(string str, int startindex)
{
    if (startindex == str.size())
    {
        result .push_back(path);
        return;
    }
    // fa [startindex, str.size - 1]
    // son str[i]
    for (int i = startindex; i < str.size(); i++)
    {
        path.push_back(str[i]);
        backtracking(str, i + 1);
        path.pop_back();
    }
}

signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int p;
    cin >> p;
    string str;
    cin >> str;
    backtracking(str, 0);
    int total
}