// #pragma GCC optimize(2)
#include <bits/stdc++.h>
using namespace std;
#define int long long
#define endl '\n'

vector<string> result;
vector<int> path;
void backtracking(int n, int sum, int startindex)
{
    // 临界条件
    if (sum == n)
    {
        string str = "";
        // path压入result
        for (int i = 0; i < path.size(); i++)
        {
            str += to_string(path[i]);
            if (i != path.size() - 1)
            {
                str += '+';
            }
        }
        result.push_back(str);
        return;
    }
    // father [startindex,n]
    //  son i
    for (int i = startindex; i <= n and sum + i <= n; i++)
    {
        sum += i;
        path.push_back(i);
        backtracking(n, sum, i);
        sum -= i;
        path.pop_back();
    }
}

signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int n;
    cin >> n;
    backtracking(n, 0, 1);
    for (auto &&i : result)
    {
        if (i != to_string(n))
        {
            cout << i << endl;
        }
    }
}