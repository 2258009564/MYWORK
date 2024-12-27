#include <iostream>
#include <cmath>
#include <bits/stdc++.h>
using namespace std;
class Complex // 复数类声明
{
public:
    Complex(double r = 0.0, double i = 0.0)
    {
        real = r;
        imag = i;
        L = sqrt(r * r + i * i);
    }
    Complex(const Complex &c)
    {
        cout << "产生一个新对象\n";
        real = c.real;
        imag = c.imag;
        L = c.L;
    }
    void display()
    {
        char op = '+';
        if (imag < 0)
            op = '-';
        cout << real << op << abs(imag) << "i" << endl;
    }
    Complex operator+(Complex &b)
    {
        Complex c;
        c.real = real + b.real;
        c.imag = imag + b.imag;
        c.L = sqrt(c.real * c.real + c.imag * c.imag);
        return c;
    }
    Complex operator-(Complex &b)
    {
        Complex c;
        c.real = real - b.real;
        c.imag = imag - b.imag;
        c.L = sqrt(c.real * c.real + c.imag * c.imag);
        return c;
    }
    friend bool operator>(Complex &a, Complex &b);

private:
    double real;
    double imag;
    double L;
};
bool operator>(Complex &a, Complex &b)
{
    cout << a.L << endl;
    cout << b.L << endl;
    return a.L > b.L;
}
int main()
{
    Complex a(2, 3), b(6, 7); // 2 + 3i     6 + 7i
    Complex c = a + b;        // a.operator+(b);   = 没有调用
    Complex d = a - b;        // a.operator-(b);
    c.display();
    d.display();
    cout << (c > d) << endl; // operator>(c, d)  or   c.operator>(d);
    system("pause");
    return 0;
}