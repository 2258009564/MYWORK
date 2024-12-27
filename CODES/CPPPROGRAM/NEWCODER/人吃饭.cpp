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
    virtual ~Person() {};
};

class Chinese : public Person
{
public:
    Chinese() { cout << "chinese come in" << endl; }
    ~Chinese() { cout << "chinese go out" << endl; }
    void eat() override { cout << "chinese eat" << endl; }
    void pay() override { cout << "chinese pay by wechat" << endl; }
};

class American : public Person
{
public:
    American() { cout << "american come in " << endl; }
    ~American() { cout << "american go out" << endl; }
    void eat() override { cout << "american eat" << endl; }
    void pay() override { cout << "american pay by paypel" << endl; }
};

class Indian : public Person
{
public:
    Indian() { cout << "Indian come in" << endl; }
    ~Indian() { cout << "Indian go out" << endl; }
    void eat() override { cout << "indian eat" << endl; }
    void pay() override { cout << "indian pay by shit" << endl; }
};

void personeat(Person& p)
{
    p.eat();
}

void solve()
{
    Chinese c;
    American a;
    Indian i;
    personeat(c);
    personeat(a);
    personeat(i);
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