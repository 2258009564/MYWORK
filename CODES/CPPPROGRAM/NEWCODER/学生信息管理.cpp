#include <bits/stdc++.h> // 包含C++标准库的所有头文件
using namespace std;

// 定义学生结构体，包含学号、姓名和三门课程成绩
struct Student
{
    int id;        // 学号
    string name;   // 姓名
    int scores[3]; // 三门课程成绩的数组
};

// 输入函数：读取n个学生的信息并存储到vector中
void input(vector<Student> &students, int n)
{
    for (int i = 0; i < n; i++)
    {
        Student s;             // 创建临时学生对象
        cin >> s.id >> s.name; // 输入学号和姓名
        for (int j = 0; j < 3; j++)
        {
            cin >> s.scores[j]; // 依次输入三门课程成绩
        }
        students.push_back(s); // 将学生信息添加到vector中
    }
}

// 打印函数：显示所有学生的信息
void print(const vector<Student> &students)
{
    for (const auto &s : students)
    {                                         // 使用范围for循环遍历所有学生
        cout << s.id << " " << s.name << " "; // 打印学号和姓名
        for (int i = 0; i < 3; i++)
        {
            cout << s.scores[i] << (i < 2 ? " " : ""); // 打印成绩，最后一个成绩后不加空格
        }
        cout << endl; // 每个学生信息打印完后换行
    }
}

int main()
{
    int n;                    // 学生人数
    cin >> n;                 // 输入学生人数
    vector<Student> students; // 创建存储学生信息的vector容器
    input(students, n);       // 调用输入函数读取学生信息
    print(students);          // 调用打印函数显示学生信息
    return 0;
}