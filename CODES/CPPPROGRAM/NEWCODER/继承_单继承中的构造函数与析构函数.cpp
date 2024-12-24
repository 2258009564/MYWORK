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

const double PI = 3.14;

class Dot
{
private:
    double x, y;

public:
    Dot(double x, double y) : x(x), y(y) { cout << "Dot constructor called" << endl; }
    ~Dot() { cout << "Dot destructor called" << endl; }
};

class Circle : public Dot
{
private:
    double r;

public:
    Circle(double a, double b, double c) : Dot(a, b), r(c)
    {
        cout << "Circle constructor called" << endl;
    }
    ~Circle() { cout << "Circle destructor called" << endl; }
    double getArea()
    {
        return PI * r * r;
    }
};

void solve()
{
    double x, y, r;
    cin >> x >> y >> r;
    Circle c(x, y, r);
    cout << fixed << setprecision(2) << c.getArea() << endl;
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