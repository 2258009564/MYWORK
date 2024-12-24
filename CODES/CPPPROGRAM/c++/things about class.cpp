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

// 定义学生类
class stu
{
private:
    int age;        // 年龄
    string name;    // 姓名

public:
    // 构造函数，使用初始化列表初始化成员变量
    stu(int a, string n) : age(a), name(n) {}
    // 默认构造函数
    stu() {}
    
    // 设置学生信息的成员函数
    void set(int a, string n)
    {
        age = a;
        name = n;
    }
    
    // 打印学生信息
    void print()
    {
        cout << age << ' ' << name << endl;
    }
    
    // 设置年龄
    void setage(int a)
    {
        age = a;
    }
    
    // 设置姓名
    void setname(string n)
    {
        name = n;
    }
    
    // 获取年龄
    int getage()
    {
        return age;
    }
    
    // 获取姓名
    string getname()
    {
        return name;
    }
    
    // 析构函数
    ~stu() {}
};

// 主要的解决函数
void solve()
{
    // 创建学生对象并初始化
    stu a(18, "zhangsan");
    a.print();  // 输出：18 zhangsan
    
    // 修改学生信息
    a.set(20, "lisi");
    a.print();  // 输出：20 lisi
    
    // 分别设置年龄和姓名
    a.setage(22);
    a.setname("wangwu");
    a.print();  // 输出：22 wangwu
    
    // 获取并输出学生信息
    cout << a.getage() << ' ' << a.getname() << endl;  // 输出：22 wangwu
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