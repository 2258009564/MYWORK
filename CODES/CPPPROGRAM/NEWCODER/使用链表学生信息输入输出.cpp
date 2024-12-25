#include <bits/stdc++.h>
using namespace std;

// 学生节点结构体
struct Student
{
    string id;
    string name;
    int score;
    Student *next;

    Student(string id, string name, int score)
        : id(id), name(name), score(score), next(nullptr) {}
};

// 链表类
class StudentList
{
private:
    Student *head;

public:
    StudentList() : head(nullptr) {}

    // 在链表尾部插入新节点
    void insert(string id, string name, int score)
    {
        Student *newStudent = new Student(id, name, score);
        if (!head)
        {
            head = newStudent;
            return;
        }
        Student *current = head;
        while (current->next)
        {
            current = current->next;
        }
        current->next = newStudent;
    }

    // 打印所有学生信息
    void print()
    {
        Student *current = head;
        while (current)
        {
            cout << current->id << " "
                 << current->name << " "
                 << current->score << endl;
            current = current->next;
        }
    }

    // 析构函数释放内存
    ~StudentList()
    {
        while (head)
        {
            Student *temp = head;
            head = head->next;
            delete temp;
        }
    }
};

int main()
{
    StudentList list;
    string id, name;
    int score;

    // 读取学生信息直到id为0
    while (cin >> id && id != "0")
    {
        cin >> name >> score;
        list.insert(id, name, score);
    }

    list.print();
    return 0;
}