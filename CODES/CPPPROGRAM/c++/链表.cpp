// #pragma GCC optimize(2)
#include <bits/stdc++.h>
using namespace std;
#define BUFF ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
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
typedef vector<bool> vb;
typedef vector<vb> vvb;
typedef vector<vvb> vvvb;
typedef map<int, int> mii;
typedef map<char, int> mci;
#define endl '\n'
#define ts    \
    int T;    \
    cin >> T; \
    while (T--)
#define all(v) v.begin(), v.end()
#define sall(x) sort(all(x))
#define re(v) reverse(all(v))

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

struct listnode
{
    // data
    string name;
    int id;

    // pointer
    listnode *next = nullptr;
};

void Push_back(listnode *&p_head /*指向头节点的指针的引用？*/, listnode *p_new /*指向新节点的指针*/)
{
    if (p_head == nullptr)
    {
        p_head = p_new;
    }
    else
    {
        listnode *p_temp = p_head;
        while (p_temp->next != nullptr)
        {
            p_temp = p_temp->next;
        }
        p_temp->next = p_new;
    }
}

void Insert(listnode *p_pos, listnode *p_new)
{
    if (p_pos->next == nullptr)
    {
        p_pos->next == p_new;
    }
    else
    {
        p_new->next = p_pos->next;
        p_pos->next = p_new;
    }
}

void Pop_back(listnode *p_head /*指向节点地址的指针*/)
{
    if (p_head == nullptr)
    {
        cout << "already empty";
        return;
    }
    if ((p_head)->next == nullptr)
    {
        p_head = nullptr;
        return;
    }
    listnode *p_temp = p_head;
    while (p_temp->next->next != nullptr)
    {
        p_temp = p_temp->next;
    }
    delete p_temp->next;
    p_temp->next = nullptr;
    return;
}

signed main()
{
    BUFF;
    listnode *p_head = nullptr, *p_new = nullptr;
    int num;
    cin >> num;
    for (int i = 0; i < num; i++)
    {
        p_new = (listnode *)malloc(sizeof(listnode));

        cin >> p_new->name >> p_new->id;
    }
}