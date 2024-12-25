#include <bits/stdc++.h>
using namespace std;

class Rectangle
{
private:
    int Length;
    int Width;

public:
    Rectangle(int l, int w) : Length(l), Width(w)
    {
        cout << "Rectangle's constructor is called!" << endl;
    }

    int GetArea()
    {
        cout << "Area = " << Length * Width << endl;
        return Length * Width;
    }

    int GetLength()
    {
        cout << "Length = " << Length << endl;
        return Length;
    }

    int GetWidth()
    {
        cout << "width = " << Width << endl;
        return Width;
    }

    ~Rectangle()
    {
        cout << "Rectangle's destructor is called!" << endl;
    }
};

int main()
{
    int l, w;
    cin >> l >> w;

    Rectangle rect(l, w);
    rect.GetLength();
    rect.GetWidth();
    rect.GetArea();

    return 0;
}