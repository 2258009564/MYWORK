#include <bits/stdc++.h>
using namespace std;
#define MAX 1000
#define int long long
//菜单界面
void showMenu()
{
    cout << "***************************" << endl;
    cout << "***** 1、添加联系人 *****" << endl;
    cout << "***** 2、显示联系人 *****" << endl;
    cout << "***** 3、删除联系人 *****" << endl;
    cout << "***** 4、查找联系人 *****" << endl;
    cout << "***** 5、修改联系人 *****" << endl;
    cout << "***** 6、清空联系人 *****" << endl;
    cout << "***** 0、退出通讯录 *****" << endl;
    cout << "***************************" << endl;
}

struct Person
{
    string m_Name;
    int m_Sex;//1男2女
    int m_Age;
    string m_Phone;
    string m_Addr;
};

struct Addressbooks
{
    Person p[MAX];
    int m_Size;//通讯录中的人员个数
};
// 1、添加一个联系人
void addPerson(Addressbooks &addr){
    //通讯录满了 就不能添加了
    if(addr.m_Size==MAX){
        cout << "通讯录满了，不能添加！" << endl;
        return;
    }else{
        //通讯录还没有满
        string name, phone, address;
        int age, sex;
        cout << "请输入姓名：" << endl;
        cin >> name;
        addr.p[addr.m_Size].m_Name = name;

        cout << "请输入性别：" << endl
             << "1 -- 男" << endl
             << "2 -- 女" << endl;
        //性别
        while(1)
        {
            cin >> sex;
            if (sex == 1 || sex == 2)
            {
                addr.p[addr.m_Size].m_Sex = sex;
                break;
            }
            cout << "输入有误，请重新输入";//------------------------------
        }

        //年龄
        cout << "请输入年龄：" << endl;
        cin >> age;
        addr.p[addr.m_Size].m_Age = age;
        //联系电话
        cout << "请输入联系电话：" << endl;
        cin >> phone;
        addr.p[addr.m_Size].m_Phone = phone;
        //家庭住址
        cout << "请输入家庭住址：" << endl;
        cin >> address;
        addr.p[addr.m_Size].m_Addr = address;
        //人数++
        addr.m_Size++;
        cout << "succeed to add!" << endl;
        system("pause");
        system("cls");
    }
    
}

// 2、显示所有联系人信息
void showPerson(Addressbooks &abs)
{
    if (abs.m_Size == 0)
    {
        cout << "当前记录为空" << endl;
    }
    else
    {
        for (int i = 0; i < abs.m_Size; i++)
        {
            cout << "姓名：" << abs.p[i].m_Name << "\t";
            cout << "性别：" << ((abs.p[i].m_Sex == 1) ? "男" : "女")
                 << "\t";
            cout << "年龄：" << abs.p[i].m_Age << "\t";
            cout << "电话：" << abs.p[i].m_Phone << "\t";
            cout << "住址：" << abs.p[i].m_Addr << endl;
        }
    }
    system("pause");
    system("cls");
}


//判断是否存在查询的人员，存在返回在数组中索引位置，不存在返回-1
int isExist(Addressbooks &abs, string name)
{
    for (int i = 0; i < abs.m_Size; i++)
    {
        if (abs.p[i].m_Name == name)
        {
            return i;
        }
    }
    return -1;
}
// 3、删除指定联系人信息
void deletePerson(Addressbooks &abs)
{
    cout << "请输入您要删除的联系人" << endl;
    string name;
    cin >> name;
    int ret = isExist(abs, name);
    if (ret != -1)
    { // 1 3 4 5 
        for (int i = ret; i < abs.m_Size; i++)
        {
            abs.p[i] = abs.p[i + 1];
        }
        abs.m_Size--;
        cout << "删除成功" << endl;
    }
    else
    {
        cout << "查无此人" << endl;
    }
    system("pause");
    system("cls");
}

// 4、查找指定联系人信息
void findPerson(Addressbooks &abs)
{
    cout << "请输入您要查找的联系人" << endl;
    string name;
    cin >> name;
    int ret = isExist(abs, name);
    if (ret != -1)
    {
        cout << "姓名：" << abs.p[ret].m_Name << "\t";
        cout << "性别：" << abs.p[ret].m_Sex << "\t";
        cout << "年龄：" << abs.p[ret].m_Age << "\t";
        cout << "电话：" << abs.p[ret].m_Phone << "\t";
        cout << "住址：" << abs.p[ret].m_Addr << endl;
    }
    else
    {
        cout << "查无此人" << endl;
    }
    system("pause");
    system("cls");
}

// 5、修改指定联系人信息
void modifyPerson(Addressbooks &abs)
{
    cout << "请输入您要修改的联系人" << endl;
    string name;
    cin >> name;
    int ret = isExist(abs, name);
    if (ret != -1)
    {
        //姓名
        string name;
        cout << "请输入姓名：" << endl;
        cin >> name;
        abs.p[ret].m_Name = name;
        cout << "请输入性别：" << endl;
        cout << "1 -- 男" << endl;
        cout << "2 -- 女" << endl;
        //性别
        int sex = 0;
        while (true)
        {
            cin >> sex;
            if (sex == 1 || sex == 2)
            {
                abs.p[ret].m_Sex = sex;
                break;
            }
            cout << "输入有误，请重新输入";
        }
        //年龄
        cout << "请输入年龄：" << endl;
        int age = 0;
        cin >> age;
        abs.p[ret].m_Age = age;
        //联系电话
        cout << "请输入联系电话：" << endl;
        string phone = "";
        cin >> phone;
        abs.p[ret].m_Phone = phone;
        //家庭住址
        cout << "请输入家庭住址：" << endl;
        string address;
        cin >> address;
        abs.p[ret].m_Addr = address;
        cout << "修改成功" << endl;
    }
    else
    {
        cout << "查无此人" << endl;
    }
    system("pause");
    system("cls");
}

//6 清空联系人
void clean(Addressbooks &abs)
{
    cout << "r u sure?" << endl
         << "press \"yes\" to clean all of the addressbooks." << endl;

    string x;
    cin >> x;
    if (x != "yes"){
        cout << "你他妈在骗老子 我还是要清空" << endl;
    }
    abs.m_Size = 0;
    cout << "你妹的 清空了" << endl;
    system("pause");
    system("cls");
}
signed main()
{
    // 创建通讯录变量 abs
    Addressbooks abs;
    //初始化通讯录中人数
    abs.m_Size = 0;

    int select = 0;
    showMenu();
    while(1){
        cin >> select;
        switch (select)
        {
        case 1: //添加联系人
            addPerson(abs);
            break;
        case 2: //显示联系人
            showPerson(abs);
            break;
        case 3: //删除联系人
            deletePerson(abs);
            break;
        case 4: //查找联系人
            findPerson(abs);
            break;
        case 5: //修改联系人
            modifyPerson(abs);
            break;
        case 6: //清空联系人
            clean(abs);
            break;
        case 0: //退出通讯录
            cout << "欢迎下次使用" << endl;
            system("pause");
            return 0;
            break;
        default:
            break;
        }

        showMenu();
    }
}
