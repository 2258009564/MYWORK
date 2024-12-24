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

// 基类 shape：所有形状的抽象基类
class shape
{
protected: // protected 使得子类可以直接访问这些成员
    int x, y;     // 形状的坐标位置
    static constexpr double pi = 3.14; // 常量 pi，用于圆形计算

public:
    // 构造函数：初始化形状的位置
    shape(int x, int y) : x(x), y(y) {};
    // 虚析构函数：确保正确释放派生类对象
    virtual ~shape() {};

    // 虚函数 GetArea：计算面积的接口
    // virtual 关键字使得这个函数可以被子类重写
    // const 表示这个方法不会修改对象的状态
    virtual double GetArea() const
    {
        return 0; // 基类默认返回0
    }
};

// 矩形类：继承自 shape
class Rectangle : public shape
{
private:
    int a, b; // 矩形的长和宽

public:
    // 构造函数：初始化位置和尺寸
    Rectangle(int x, int y, int a, int b) : shape(x, y), a(a), b(b) {};
    ~Rectangle() {};

    // 重写 GetArea 计算矩形面积
    double GetArea() const override
    {
        return a * b;
    }
};

// 正方形类：继承自矩形类（因为正方形是特殊的矩形）
class Square : public Rectangle
{
    int l; // 正方形的边长

public:
    // 构造函数：调用矩形的构造函数，边长相等
    Square(int x, int y, int l) : Rectangle(x, y, l, l), l(l) {};
    ~Square() {};

    // 重写 GetArea 计算正方形面积
    double GetArea() const override
    {
        return l * l;
    }
};

// 圆形类：继承自 shape
class Circle : public shape
{
private:
    int r; // 圆的半径

public:
    // 构造函数：初始化位置和半径
    Circle(int x, int y, int r) : shape(x, y), r(r) {};
    ~Circle() {};

    // 重写 GetArea 计算圆形面积
    double GetArea() const override
    {
        return pi * r * r;
    }
};

// 主要逻辑处理函数
void solve()
{
    int a, b, c, d;
    cin >> a >> b >> c >> d;  // 读入各种形状的参数
    int x = 0, y = 0;         // 所有形状的位置都设在原点

    // 创建并输出矩形面积
    Rectangle rect(x, y, a, b);
    cout << rect.GetArea() << endl;

    // 创建并输出圆形面积
    Circle cir(x, y, c);
    cout << cir.GetArea() << endl;

    // 创建并输出正方形面积
    Square sqr(x, y, d);
    cout << sqr.GetArea() << endl;
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