#include <bits/stdc++.h>
using namespace std;

enum CPU_Rank
{
    P1 = 1,
    P2,
    P3,
    P4,
    P5,
    P6,
    P7
};

class CPU
{
private:
    CPU_Rank rank;
    int frequency;
    float voltnumber;

public:
    CPU(int r, int f, float v) : rank(static_cast<CPU_Rank>(r)), frequency(f), voltnumber(v)
    {
        cout << "CPU's constructor is called!" << endl;
    }

    void run()
    {
        cout << fixed << setprecision(1);
        cout << "I am working, my rank is " << rank
             << ", my frequency is " << frequency
             << ", my voltnumber is " << voltnumber
             << "." << endl;
    }

    void stop()
    {
        cout << "I stopped working!" << endl;
    }

    ~CPU() { cout << "CPU's destructor is called!" << endl; }
};

int main()
{
    int r, f;
    float v;
    cin >> r >> f >> v;

    CPU cpu(r, f, v);
    cpu.run();
    cpu.stop();

    return 0;
}