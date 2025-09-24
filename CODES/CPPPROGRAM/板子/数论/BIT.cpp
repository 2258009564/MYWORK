// #pragma GCC optimize(2)
#include <bits/stdc++.h>
using namespace std;
#define int long long
#define endl '\n'
#define all(x) (x).begin(), (x).end()

constexpr int MOD = 1e9 + 7;
// -9.2e18 ~ 9.2e18

class BIT
{
private:
    vector<int> c;
    int n;

    int lowbit(int x)
    {
        return x & -x;
    }

public:
    BIT(int size) : n(size), c(n + 1)
    {
    }

    BIT(vector<int> &arr) : n(arr.size())
    {
        c.resize(n + 1, 0);
        for (int i = 1; i <= n; i++)
        {
            add(i, arr[i - 1]);
        }
    }

    void add(int i, int val)
    {
        while (i <= n)
        {
            c[i] += val;
            i += lowbit(i);
        }
    }

    int sum(int i)
    {
        int ans = 0;
        while (i)
        {
            ans += c[i];
            i -= lowbit(i);
        }
        return ans;
    }

    int query(int l, int r)
    {
        return sum(r) - sum(l - 1);
    }

    int get(int i)
    {
        return query(i, i);
    }

    int update(int i, int val)
    {
        auto delta = val = get(i);
        add(i, delta);
    }

    void clear()
    {
        fill(all(c), 0);
    }

    // 获取树状数组的大小
    int size()
    {
        return n;
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
        // cout << endl;
    }
}