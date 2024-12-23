#include <bits/stdc++.h>
using namespace std;
#define int long long
#define endl '\n'

struct stu
{
    double count;
    double value;
    double avarage_value;
};

bool paixu(stu stu1, stu stu2)
{
    return stu1.avarage_value > stu2.avarage_value;
}

signed main()
{
    int n, t;
    cin >> n >> t;
    vector<stu> vec(n);
    for(auto &stu1:vec)
    {
        cin >> stu1.count >> stu1.value;
        stu1.avarage_value = stu1.value / stu1.count;
    }
    sort(vec.begin(), vec.end(), paixu);
    
}