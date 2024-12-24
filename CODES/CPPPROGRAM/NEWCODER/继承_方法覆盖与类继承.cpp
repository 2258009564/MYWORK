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

// 抽象基类 Shape：定义图形的基本接口
class Shape
{
public:
    virtual double area() const = 0;      // 纯虚函数：计算面积
    virtual double perimeter() const = 0; // 纯虚函数：计算周长
    virtual ~Shape() {}                   // 虚析构函数，确保正确释放子类对象
};

// 矩形类：继承自Shape
class Rect : public Shape
{
private:
    double x1, y1, x2, y2; // 存储矩形对角线两点坐标

public:
    // 构造函数：初始化矩形的两个对角点
    Rect(double x1, double y1, double x2, double y2)
        : x1(x1), x2(x2), y1(y1), y2(y2) {}

    // 重写面积计算方法
    double area() const override
    {
        return abs(x2 - x1) * abs(y2 - y1); // 长×宽
    }

    // 重写周长计算方法
    double perimeter() const override
    {
        return 2 * (abs(x2 - x1) + abs(y2 - y1)); // 2×(长+宽)
    }
};

// 圆形类：继承自Shape
class Circle : public Shape
{
private:
    double x, y, r; // 圆心坐标和半径

public:
    // 构造函数：初始化圆心坐标和半径
    Circle(double x, double y, double r) : x(x), y(y), r(r) {}

    // 重写面积计算方法
    double area() const override
    {
        return M_PI * r * r; // πr²
    }

    // 重写周长计算方法
    double perimeter() const override
    {
        return 2 * M_PI * r; // 2πr
    }
};

// 三角形类：继承自Shape
class Triangle : public Shape
{
private:
    double x1, y1, x2, y2, x3, y3; // 三个顶点坐标

public:
    // 构造函数：初始化三个顶点坐标
    Triangle(double x1, double y1, double x2, double y2, double x3, double y3)
        : x1(x1), y1(y1), x2(x2), y2(y2), x3(x3), y3(y3) {}

    // 重写面积计算方法
    double area() const override
    {
        // 使用三角形面积的叉积公式：S = |(x1(y2-y3) + x2(y3-y1) + x3(y1-y2))| / 2
        return abs(x1 * (y2 - y3) + x2 * (y3 - y1) + x3 * (y1 - y2)) / 2.0;
    }

    // 重写周长计算方法
    double perimeter() const override
    {
        // 计算三边长度并求和
        double side1 = sqrt(pow(x2 - x1, 2) + pow(y2 - y1, 2));
        double side2 = sqrt(pow(x3 - x2, 2) + pow(y3 - y2, 2));
        double side3 = sqrt(pow(x1 - x3, 2) + pow(y1 - y3, 2));
        return side1 + side2 + side3;
    }
};

// 主要解题函数
void solve()
{
    string shapeType;
    cin >> shapeType;

    // 根据输入的图形类型创建相应对象并计算
    if (shapeType == "Rect")
    {
        double x1, y1, x2, y2;
        cin >> x1 >> y1 >> x2 >> y2;
        Rect shape(x1, y1, x2, y2);
        cout << fixed << setprecision(5) << shape.area() << " " << shape.perimeter() << endl;
    }
    else if (shapeType == "Circle")
    {
        double x, y, r;
        cin >> x >> y >> r;
        Circle shape(x, y, r);
        cout << fixed << setprecision(5) << shape.area() << " " << shape.perimeter() << endl;
    }
    else if (shapeType == "Triangle")
    {
        double x1, y1, x2, y2, x3, y3;
        cin >> x1 >> y1 >> x2 >> y2 >> x3 >> y3;
        Triangle shape(x1, y1, x2, y2, x3, y3);
        cout << fixed << setprecision(5) << shape.area() << " " << shape.perimeter() << endl;
    }
}

signed main()
{
    ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
    int TT = 1;
    cin >> TT;
    while (TT--)
    {
        solve();
    }
}