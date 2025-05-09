// #pragma GCC optimize(2)
#include <bits/stdc++.h>
using namespace std;
#define int long long
#define endl '\n'
#define all(x) (x).begin(), (x).end()

const int INF = 1e9;     // 无穷大
const int INFLL = 1e18;  // 长整型无穷大
const int MOD = 1e9 + 7; // 模数
// -9.2e18 ~ 9.2e18

class DSU
{
private:
    vector<int> parent, rank, size;
    int count;

public:
    DSU(int n) : parent(n + 1), rank(n + 1, 0), size(n + 1, 1), count(n)
    {
        iota(all(parent), 0ll);
    }

    int find(int x)
    {
        return parent[x] == x ? x : parent[x] = find(parent[x]);
    }

    void merge(int i, int j)
    {
        int ri = find(i), rj = find(j);
        if (ri == rj)
        {
            return;
        }

        if (rank[ri] < rank[rj])
        {
            swap(ri, rj);
        }
        parent[rj] = ri;
        size[ri] += size[rj];
        if (rank[ri] == rank[rj])
        {
            rank[ri]++;
        }
        count--;
    }

    bool issame(int i, int j)
    {
        return find(i) == find(j);
    }

    int getsize(int x)
    {
        return size[find(x)];
    }

    int getgroups()
    {
        return count;
    }
};

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
        cout << endl;
    }
}