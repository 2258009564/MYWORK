// #pragma GCC optimize(2)
#include <bits/stdc++.h>
using namespace std;
#define int long long
typedef pair<int, int> pii;
typedef pair<double, double> pdd;
typedef vector<string> vs;
typedef vector<vs> vvs;
typedef vector<vvs> vvvs;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<vvi> vvvi;
typedef vector<pii> vpii;
typedef vector<vpii> vvpii;
typedef vector<pdd> vpdd;
typedef vector<double> vd;
typedef vector<vd> vvd;
typedef vector<char> vc;
typedef vector<vc> vvc;
typedef vector<vvc> vvvc;
typedef map<int, int> mii;
typedef map<char, int> mci;
#define endl '\n'
#define all(v) v.begin(), v.end()

// 通用版本的 >> 重载，用于任意类型的 std::vector<T>
template <typename T>
istream &operator>>(istream &in, vector<T> &v)
{
    for (auto &x : v)
    {
        in >> x;
    }
    return in;
}

// 通用版本的 << 重载，用于任意类型的 std::vector<T>
template <typename T>
ostream &operator<<(ostream &out, const vector<T> &v)
{
    for (const auto &x : v)
    {
        out << x << ' ';
    }
    return out;
}

class Person
{
public:
    virtual void eat() = 0;
    virtual void pay() = 0;
    virtual ~Person() {}
};
class Chinese : public Person
{
public:
    Chinese() { cout << "中国人进入餐厅" << endl; }
    ~Chinese() { cout << "中国人离开餐厅" << endl; }
    void eat() override { cout << "中国人用筷子吃饭" << endl; }
    void pay() override { cout << "中国人用微信支付" << endl; }
};

class American : public Person
{
public:
    American() { cout << "美国人进入餐厅" << endl; }
    ~American() { cout << "美国人离开餐厅" << endl; }
    void eat() override { cout << "美国人用叉子吃饭" << endl; }
    void pay() override { cout << "美国人用信用卡支付" << endl; }
};

class Indian : public Person
{
public:
    Indian() { cout << "印度人进入餐厅" << endl; }
    ~Indian() { cout << "印度人离开餐厅" << endl; }
    void eat() override { cout << "印度人用手吃饭" << endl; }
    void pay() override { cout << "印度人用现金支付" << endl; }
};
void processMeal(Person &p)
{
    p.eat();
    p.pay();
}
void solve()
{
    Chinese c;
    American a;
    Indian i;

    processMeal(c);
    processMeal(a);
    processMeal(i);
}

signed main()
{
    ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
    int TT = 1;
    // cin >> TT;
    while (TT--)
    {
        solve();
    }
}