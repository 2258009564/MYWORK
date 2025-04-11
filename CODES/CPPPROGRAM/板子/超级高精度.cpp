// #pragma GCC optimize(2)
#include <bits/stdc++.h>
using namespace std;
// #define int long long
#define endl '\n'
#define all(x) (x).begin(), (x).end()

const int MOD = 1e9 + 7;

// 高精度整数类
class BigInteger
{
private:
    // 数字以十进制存储，个位在前
    vector<int> digits;
    // 符号位，true为负数
    bool negative;

    // 去除前导零
    void removeLeadingZeros()
    {
        while (digits.size() > 1 && digits.back() == 0)
        {
            digits.pop_back();
        }
        // 如果只剩0，确保符号为正
        if (digits.size() == 1 && digits[0] == 0)
        {
            negative = false;
        }
    }

    // 绝对值比较，不考虑符号
    static bool absLess(const BigInteger &a, const BigInteger &b)
    {
        if (a.digits.size() != b.digits.size())
        {
            return a.digits.size() < b.digits.size();
        }
        for (int i = a.digits.size() - 1; i >= 0; i--)
        {
            if (a.digits[i] != b.digits[i])
            {
                return a.digits[i] < b.digits[i];
            }
        }
        return false; // 相等
    }

    // 无符号加法
    static BigInteger absAdd(const BigInteger &a, const BigInteger &b)
    {
        BigInteger result;
        result.negative = false;

        const vector<int> &longer = a.digits.size() >= b.digits.size() ? a.digits : b.digits;
        const vector<int> &shorter = a.digits.size() < b.digits.size() ? a.digits : b.digits;

        result.digits.resize(longer.size() + 1, 0);

        for (size_t i = 0; i < shorter.size(); i++)
        {
            result.digits[i] += shorter[i];
        }

        for (size_t i = 0; i < longer.size(); i++)
        {
            result.digits[i] += longer[i];
        }

        // 处理进位
        for (size_t i = 0; i < result.digits.size() - 1; i++)
        {
            if (result.digits[i] >= 10)
            {
                result.digits[i + 1] += result.digits[i] / 10;
                result.digits[i] %= 10;
            }
        }

        result.removeLeadingZeros();
        return result;
    }

    // 无符号减法，假设a >= b
    static BigInteger absSub(const BigInteger &a, const BigInteger &b)
    {
        BigInteger result;
        result.negative = false;
        result.digits.resize(a.digits.size(), 0);

        for (size_t i = 0; i < a.digits.size(); i++)
        {
            result.digits[i] += a.digits[i];
        }

        for (size_t i = 0; i < b.digits.size(); i++)
        {
            result.digits[i] -= b.digits[i];
        }

        // 处理借位
        for (size_t i = 0; i < result.digits.size() - 1; i++)
        {
            if (result.digits[i] < 0)
            {
                result.digits[i] += 10;
                result.digits[i + 1]--;
            }
        }

        result.removeLeadingZeros();
        return result;
    }

public:
    // 默认构造函数
    BigInteger() : negative(false)
    {
        digits.push_back(0);
    }

    // 从整数构造
    BigInteger(long long num) : negative(false)
    {
        if (num < 0)
        {
            negative = true;
            num = -num;
        }

        if (num == 0)
        {
            digits.push_back(0);
        }
        else
        {
            while (num > 0)
            {
                digits.push_back(num % 10);
                num /= 10;
            }
        }
    }

    // 从字符串构造
    BigInteger(const string &str) : negative(false)
    {
        if (str.empty())
        {
            digits.push_back(0);
            return;
        }

        size_t start = 0;
        if (str[0] == '-')
        {
            negative = true;
            start = 1;
        }
        else if (str[0] == '+')
        {
            start = 1;
        }

        for (size_t i = str.size(); i > start; i--)
        {
            if (isdigit(str[i - 1]))
            {
                digits.push_back(str[i - 1] - '0');
            }
            else
            {
                throw invalid_argument("Invalid BigInteger string");
            }
        }

        removeLeadingZeros();
    }

    // 复制构造函数
    BigInteger(const BigInteger &other) : digits(other.digits), negative(other.negative) {}

    // 赋值运算符
    BigInteger &operator=(const BigInteger &other)
    {
        if (this != &other)
        {
            digits = other.digits;
            negative = other.negative;
        }
        return *this;
    }

    // 加法
    BigInteger operator+(const BigInteger &other) const
    {
        // 同号相加
        if (negative == other.negative)
        {
            BigInteger result = absAdd(*this, other);
            result.negative = negative;
            return result;
        }

        // 异号相加等于绝对值大的减去绝对值小的
        if (absLess(*this, other))
        {
            BigInteger result = absSub(other, *this);
            result.negative = other.negative;
            return result;
        }
        else
        {
            BigInteger result = absSub(*this, other);
            result.negative = negative;
            return result;
        }
    }

    // 减法
    BigInteger operator-(const BigInteger &other) const
    {
        // 相当于加上other的相反数
        BigInteger negOther = other;
        negOther.negative = !negOther.negative;
        return *this + negOther;
    }

    // 乘法
    BigInteger operator*(const BigInteger &other) const
    {
        if ((digits.size() == 1 && digits[0] == 0) ||
            (other.digits.size() == 1 && other.digits[0] == 0))
        {
            return BigInteger(); // 0乘以任何数都是0
        }

        // 结果的符号
        bool resultNegative = negative != other.negative;

        // 结果的位数最多是两个乘数位数之和
        vector<int> resultDigits(digits.size() + other.digits.size(), 0);

        // 逐位相乘
        for (size_t i = 0; i < digits.size(); i++)
        {
            for (size_t j = 0; j < other.digits.size(); j++)
            {
                resultDigits[i + j] += digits[i] * other.digits[j];
            }
        }

        // 处理进位
        for (size_t i = 0; i < resultDigits.size() - 1; i++)
        {
            resultDigits[i + 1] += resultDigits[i] / 10;
            resultDigits[i] %= 10;
        }

        BigInteger result;
        result.digits = resultDigits;
        result.negative = resultNegative;
        result.removeLeadingZeros();

        return result;
    }

    // 除法
    pair<BigInteger, BigInteger> divmod(const BigInteger &divisor) const
    {
        if (divisor.digits.size() == 1 && divisor.digits[0] == 0)
        {
            throw invalid_argument("Division by zero");
        }

        // 被除数是0，结果是0
        if (digits.size() == 1 && digits[0] == 0)
        {
            return make_pair(BigInteger(), BigInteger());
        }

        // 获取绝对值用于计算
        BigInteger absThis = *this;
        absThis.negative = false;
        BigInteger absDivisor = divisor;
        absDivisor.negative = false;

        // 如果被除数小于除数，商为0，余数为被除数
        if (absLess(absThis, absDivisor))
        {
            return make_pair(BigInteger(), *this);
        }

        // 结果的符号
        bool resultNegative = negative != divisor.negative;

        // 做除法计算
        BigInteger quotient;
        BigInteger remainder;

        // 从高位到低位做除法
        for (int i = absThis.digits.size() - 1; i >= 0; i--)
        {
            remainder = remainder * BigInteger(10) + BigInteger(absThis.digits[i]);

            // 寻找当前位的商
            int q = 0;
            BigInteger temp = absDivisor;
            while (!absLess(remainder, temp))
            {
                remainder = remainder - temp;
                q++;
            }

            quotient.digits.insert(quotient.digits.begin(), q);
        }

        quotient.negative = resultNegative;
        remainder.negative = negative; // 余数符号与被除数相同

        quotient.removeLeadingZeros();

        return make_pair(quotient, remainder);
    }

    // 除法运算符
    BigInteger operator/(const BigInteger &divisor) const
    {
        return divmod(divisor).first;
    }

    // 取模运算符
    BigInteger operator%(const BigInteger &divisor) const
    {
        return divmod(divisor).second;
    }

    // 求绝对值
    BigInteger abs() const
    {
        BigInteger result = *this;
        result.negative = false;
        return result;
    }

    // 比较运算符
    bool operator<(const BigInteger &other) const
    {
        if (negative != other.negative)
        {
            return negative;
        }

        if (negative)
        {
            return absLess(other, *this);
        }
        else
        {
            return absLess(*this, other);
        }
    }

    bool operator>(const BigInteger &other) const
    {
        return other < *this;
    }

    bool operator<=(const BigInteger &other) const
    {
        return !(other < *this);
    }

    bool operator>=(const BigInteger &other) const
    {
        return !(*this < other);
    }

    bool operator==(const BigInteger &other) const
    {
        return !(*this < other) && !(other < *this);
    }

    bool operator!=(const BigInteger &other) const
    {
        return *this < other || other < *this;
    }

    // 转换为字符串
    string toString() const
    {
        string result;
        if (negative)
        {
            result += "-";
        }

        for (int i = digits.size() - 1; i >= 0; i--)
        {
            result += digits[i] + '0';
        }

        return result;
    }

    // 重载输出运算符
    friend ostream &operator<<(ostream &os, const BigInteger &num)
    {
        os << num.toString();
        return os;
    }

    // 重载输入运算符
    friend istream &operator>>(istream &is, BigInteger &num)
    {
        string str;
        is >> str;
        num = BigInteger(str);
        return is;
    }
};

void solve()
{
    // 测试高精度计算
    string a, b;
    cin >> a >> b;

    BigInteger num1(a);
    BigInteger num2(b);

    cout << "加法: " << num1 + num2 << endl;
    cout << "减法: " << num1 - num2 << endl;
    cout << "乘法: " << num1 * num2 << endl;

    try
    {
        cout << "除法: " << num1 / num2 << endl;
        cout << "取模: " << num1 % num2 << endl;
    }
    catch (const invalid_argument &e)
    {
        cout << e.what() << endl;
    }

    cout << "num1的绝对值: " << num1.abs() << endl;
    cout << "num2的绝对值: " << num2.abs() << endl;

    cout << "比较结果: " << endl;
    cout << "num1 < num2: " << (num1 < num2) << endl;
    cout << "num1 > num2: " << (num1 > num2) << endl;
    cout << "num1 == num2: " << (num1 == num2) << endl;
}

signed main()
{
    cin.tie(0)->ios::sync_with_stdio(0);
    int TT = 1;
    // cin >> TT;
    while (TT--)
    {
        solve();
    }
    return 0;
}