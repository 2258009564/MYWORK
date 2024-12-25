#include <bits/stdc++.h>
using namespace std;

// 日期结构体，用于处理年月日相关的日期计算
struct Date
{
    // 年份
    int year;
    // 月份（1-12）
    int month;
    // 日期（1-31）
    int day;
    // 判断闰年
    bool isLeapYear() const
    {
        return (year % 4 == 0 && year % 100 != 0) || (year % 400 == 0);
    }

    // 计算天数
    int getDayOfYear() const
    {
        const int monthDays[12] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
        int result = day;

        // 加上前面月份的天数
        for (int i = 0; i < month - 1; i++)
        {
            result += monthDays[i];
        }

        // 如果是闰年且过了2月，加1天
        if (month > 2 && isLeapYear())
        {
            result++;
        }

        return result;
    }
};

int main()
{
    Date date;
    cin >> date.year >> date.month >> date.day;
    cout << date.getDayOfYear();
}