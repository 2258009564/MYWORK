```cpp
// #pragma GCC optimize(2)
#include <bits/stdc++.h>
using namespace std;
#define int long long
#define endl '\n'
#define all(x) (x).begin(), (x).end()

constexpr int MOD = 1e9 + 7;
// -9.2e18 ~ 9.2e18

const int N = 1e6 + 10;
vector trie(N, vector<int>(26));
vector<int> p(N), e(N);

int cnt = 0;
void insert(string &s)
{
    int idx = 0;
    for (auto c : s)
    {
        auto cur = c - 'a';
        if (!trie[idx][cur])
        {
            trie[idx][cur] = ++cnt;
        }
        idx = trie[idx][cur];
        p[idx]++;
    }
    e[idx]++;
}

// 查询单词是否存在（严格匹配）
bool search_word(const string &s)
{
    int idx = 0;
    for (auto ch : s)
    {
        int c = ch - 'a';
        if (c < 0 || c >= 26)
            return false;
        if (!trie[idx][c])
            return false;
        idx = trie[idx][c];
    }
    return e[idx] > 0;
}

// 返回以 s 为前缀的字符串个数（插入时 p[idx] 的值）
int count_prefix(const string &s)
{
    int idx = 0;
    for (auto ch : s)
    {
        int c = ch - 'a';
        if (c < 0 || c >= 26)
            return 0;
        if (!trie[idx][c])
            return 0;
        idx = trie[idx][c];
    }
    return p[idx];
}

// 返回单词 s 被插入了多少次
int count_word(const string &s)
{
    int idx = 0;
    for (auto ch : s)
    {
        int c = ch - 'a';
        if (c < 0 || c >= 26)
            return 0;
        if (!trie[idx][c])
            return 0;
        idx = trie[idx][c];
    }
    return e[idx];
}

// 删除（基于计数）：如果单词存在则删除一次并返回 true；否则返回 false。
// 我们把经过的节点的 p 值逐个 --，并把结尾 e--。
// 注意：该实现不会物理回收节点，仅逻辑删除（竞赛常用）。
bool erase(string &s)
{
    int idx = 0;
    vector<int> path;
    path.reserve(s.size());
    for (auto ch : s)
    {
        int c = ch - 'a';
        if (c < 0 || c >= 26)
            return false;
        if (!trie[idx][c])
            return false; // 单词不存在
        idx = trie[idx][c];
        path.push_back(idx);
    }
    if (e[idx] == 0)
        return false; // 单词确实不存在
    e[idx]--;         // 删除一个单词结尾计数
    // 沿路径把 p--（与 insert 时 p++ 对应）
    for (int node : path)
        p[node]--;
    return true;
}

void solve()
{
}

signed main()
{
    cin.tie(0)->ios::sync_with_stdio(0);
    cout << setiosflags(ios::fixed) << setprecision(2);
    int TT = 1;
    // cin >> TT;
    while (TT--)
    {
        solve();
        // cout << endl;
    }
}
```