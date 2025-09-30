alisa为了督促自己学习所以写点题解，如果能帮到补题的你就再好不过了。
### 头文件参考
```cpp
#include <bits/stdc++.h>
using namespace std;
#define int long long
#define endl '\n'
#define all(x) (x).begin(), (x).end()
```

### A
用一个`map`来存储所给字符串`s`的信息，然后尝试和`Kato_Shoko`逐位匹配 如果最后不为0 那就说明可以成立，答案是`n - 10` ，否则输出`no` 
```cpp
void solve()
{
    int n;
    cin >> n;
    string s;
    cin >> s;

    map<char, int> mp;
    for (auto c : s)
    {
        mp[c]++;
    }

    string ss = "Kato_Shoko";
    for (auto c : ss)
    {
        if (mp[c])
        {
            mp[c]--;
        }
        else
        {
            return void(cout << "NO");
        }
    }
    cout << "YES" << ' ' << n - 10;
}
```

### B
我们希望用最少的复制次数使得`tot`满足要求，一种自然的想法是贪心。具体来说 我们对a排序 从大到小一个一个加，在不断累加的过程中判断是否符合要求即可。

在实现上 一个一个加略显累赘，为了加速，我们可以直接把`a[i] * b[i]` 加到结果里 判断是否符合要求 如果符合那就计算多余的量；如果不符合就可以一次性加完然后判断下一个。

> 在计算余量时候需要用到向上取整 可以使用 `(a + b - 1) / b`
```cpp
void solve()
{
    int n, t;
    cin >> n >> t;
    vector<pair<int, int>> v(n);
    int sum = 0;
    for (int i = 0; i < n; i++)
    {
        cin >> v[i].first;
        sum += v[i].first;
    }
    for (int i = 0; i < n; i++)
    {
        cin >> v[i].second;
    }

    sort(all(v), [](auto a, auto b)
         { return a.first > b.first; });

    if (sum >= t)
    {
        return void(cout << 0);
    }

    int ans = 0;
    for (int i = 0; i < n; i++)
    {
        auto [val, times] = v[i];
        if (sum + val * times >= t)
        {
            t -= sum;
            // 希望 val * times >= t
            /*
            2 * x >= 5
            x_min = 5/2 上取整
            */
            cout << ans + (t + val - 1) / val;
            return;
        }
        else
        {
            ans += times;
            sum += val * times;
        }
    }
    cout << -1;
}
```

### C
#### 法一
赛时我的做法是大致估算了一下：

最多八位数 每一位选与不选能得到 `1 << 8 = 256` 种可能 对每一种可能计算全排列复杂度是阶乘，极限情况下是`256 * 8!`仍然可以在一秒内跑完，所以我就直接暴力弄过去了。

实现上 为了避免复杂的回溯选择，我采用了二进制枚举；特判了 `0` 可以被任何正整数整除的情况。

以下代码仅供参考。
```cpp
void solve()
{
    int n, d;
    cin >> n >> d;
    string s;
    cin >> s;

    if (count(all(s), '0'))
    {
        cout << 0;
        return;
    }
    int ans = LLONG_MAX;
    for (int mask = 1; mask < (1ll << n); mask++)
    {
        auto cur = mask;
        vector<char> v;
        for (int i = 0; i < n; i++)
        {
            if (cur & 1)
            {
                v.emplace_back(s[i]);
            }
            cur >>= 1;
        }
        sort(all(v));
        do
        {
            string ss;
            for (auto c : v)
            {
                ss += c;
            }

            auto num = stoll(ss);

            if (num % d == 0)
            {
                ans = min(ans, num);
            }
        } while (next_permutation(all(v)));
    }
    if (ans == LLONG_MAX)
    {
        cout << -1;
    }
    else
    {
        cout << ans;
    }
}
```

#### 法二
赛后跟一个学弟交流了一下，说是记录`s`能取到的最大整数为`maxnum` 那么可以枚举 `i` 直到 `d*i > maxnum` 然后转为跟A题一模一样的暴力匹配即可，时间复杂度大概是`1e6` 的样子；看完代码之后觉得很有道理，而且实现起来比我简单很多，遂觉得后生可畏。

请ai生成了一下大概是这样：
```cpp
// 检查 t 的数字是否是 s 的数字的子集
bool is_subsequence_of_digits(string t, map<char, int>& s_counts)
{
    map<char, int> t_counts;
    for (char c : t)
    {
        t_counts[c]++;
    }

    for (auto const& [key, val] : t_counts)
    {
        if (s_counts.find(key) == s_counts.end() || s_counts[key] < val)
        {
            return false;
        }
    }
    return true;
}

void solve()
{
    int n, d;
    cin >> n >> d;
    string s;
    cin >> s;

    if (count(all(s), '0'))
    {
        cout << 0;
        return;
    }

    // 记录 s 中各数字的出现次数
    map<char, int> s_counts;
    for (char c : s)
    {
        s_counts[c]++;
    }

    // 计算 s 能组成的最大数作为枚举上界
    string temp_s = s;
    sort(all(temp_s), greater<char>());
    int max_num = stoll(temp_s);

    // 枚举 d 的倍数
    for (int i = d; i <= max_num; i += d)
    {
        string current_multiple_str = to_string(i);
        // 检查当前倍数是否能由 s 的数字构成
        if (is_subsequence_of_digits(current_multiple_str, s_counts))
        {
            cout << i;
            return;
        }
    }

    cout << -1;
}
```
### D

### E 
#### 如何计算数根
alisa 想了很久，都没有办法很好的展示 $\mod 9$ 是如何得到数根的，为此咕咕到了现在 但是我好像找到了一种感性的理解方式：

对于一个数字，各位相加的过程其实等价于 减去若干个9的倍数。

譬如 76 要想得到7+6 只需要计算 $76-7*9$ ，这是因为 $76 = 70 + 6$ 而对于每一个10 把它减去9就能得到1。

同样的道理，要计算521的数位之和，应当对每一个100都减去99，对每一个10都减去9

最终 我们会得到一个 一位数 $r$ ，因为先前的每一步操作都不改变 $\mod 9$ 的余数，所以：

$$r≡N (\mod 9)$$

这启示我们，要计算一个数的数根，只需要把这个数字对9取模即可。

但是，这个计算公式需要我们知道数字N 还可以如何转化呢

我们不直接计算数字N 而是想办法凑出$N\%9$ 

对于一个数字串 $s_{1}s_{2}s_{3}...s_{n-1}s_{n}$ 他对应的十进制数可以被拆解为

$$N=s_{1} \cdot 10^{n-1}+s_{2} \cdot 10^{n-2}+s_{3} \cdot 10^{n-3}+...+s_{(n-1)} \cdot 10^{n-(n-1)}+s_{n} \cdot 10^{n-n}$$


把等式两侧分别对9取模，可以得到


$$N\mod 9 = s_{1}+s_{2}+s_{3}+...+s_{n-1}+s_{n} \mod 9$$ 

(这是因为$10 \mod 9 = 1$) 

跟上面的结论结合在一起，我们注意到 要求521的数根，其实只要5+2+1然后将结果对9取模就好了！


而5+2+1的过程 是可以用前缀和来统计的。

#### 问题转化

形式化地说：定义前缀和

$$pre[i] = s_{1}+s_{2}+...+s_i$$

那么任意子串$[l, r]$ 的数字和即为

$$S(l, r)=pre[r]-pre[l-1]$$ 

那么子串模9 就可以被转化为

$$S(l, r) \mod 9=pre[r]-pre[l-1] \mod 9$$

这把“子串问题”转成了“两个前缀的差”的问题，不可不谓是质的突破。

接下来 我们的任务目标就是在遍历字符串的同时，对前缀和的信息动手脚了。

#### 把“统计所有子串”变成“统计前缀模的配对”


想统计多少子串 $[l, r]$ 满足 子串模为t 

$$(pre[r]-pre[l-1])\mod 9=t$$ 等价于$$pre[l-1]=(pre[r]-t)\mod9$$ 我们采取 外层循环遍历r，内层循环遍历t $t \in [0, 8]$ 


固定右端 r 后，满足条件的左端数目 = 之前出现过的前缀模等于 $(pre[r]-t)\%9$ 的次数。

所以如果你**从左到右遍历 r**，并维护一个数组 `cnt[t]`（记录之前前缀模为 t 的次数），那么对于每个 r、每个目标余数 t，你可以立刻得到贡献 `cnt[(P[r]-t) mod 9]`。把 t 从 $[0, 8]$ 都加上，就得到了以 r 为右端的所有子串模分布。

#### 配对技巧
上面提供的是一种常见的配对统计技巧，我们可以来打个表看看**为什么可以处理所有子串**
- 遍历到$s[1]$ 记录1的信息
- 遍历到2 先累加之前1的信息，得到12的信息；接着记录2的信息
- 遍历到3 先累加之前12,2的信息 得到123，23；接着记录3的信息
- ...
所以，遍历到i位置的时候，我们总能确保前面所有子串的信息都已经被记录。
下次遇到形如$a[l]+a[r]=k$的式子的时候，我们也可以尝试采用枚举r和k 然后从预处理信息中找$a[l]$ 的做法。

#### 统计答案（完整步骤）

- 维护一个长度 9 的计数数组 `cnt[0..8]`，`cnt[t]` 表示已经遇到的前缀（包括空前缀）中模为 t 的个数。
    - 初始：`cnt[0] = 1`（空前缀，代表 l=1 的子串）。
- 维护当前前缀和模 `pref`（也就是 `pre[r] % 9`）。初始化 `pref = 0`。
- 维护一个变量 `ans`（用来累积数字根之和），初始 `ans = 0`。
- 从左到右遍历每个位置 `r = 1..n`（处理字符 `s[r]`）：
    1. 用 `pref = (pref + digit(s[r])) % 9` 更新当前前缀模（这里 `digit(s[r])` 是字符转成的 0..9）。
    2. 用历史 `cnt` 来统计以 `r` 为右端的新产生的所有子串的数字根之和：
        - 对历史前缀模 `t`（t = 0..8`）：
            - 该历史前缀与当前 `pref` 配对会产生模 `v = (pref - t + 9) % 9` 的若干子串，数量为 `cnt[t]`（对应所有 l 使得 `pre[l] % 9 = t）。
            - 数字根贡献：
                - 如果 `v != 0`：这些子串每个的数字根 = `v`，所以总贡献 `v * cnt[t]`。
                - 如果 `v == 0`：这些子串中 **非全零** 的会贡献 `9`（数字根 = 9），但 **全零** 的子串贡献 `0`。为了实现简单，**在此处统一把 v == 0 的子串暂且当作 9 来加**，即加 `9 * cnt[t]`。（以后统一修正）
            - 所以在遍历 m 时可以执行 `ans += (v ? v : 9) * cnt[t]`。
    3. 完成上述统计后，把当前前缀模记入历史：`cnt[pref]++`（**注意顺序：先统计再更新 cnt**，否则会把包含当前 r 的左端错误地计为历史）。
- 遍历结束后，你已经把每个模为 0 的子串都当作 9 加进去了（包含那些实际为 0 的全零子串）。现在需要修正：
    - 计算全零子串的数量 `Z`：扫描字符串中的每一段连续零段，长度为 `L` 的零段包含 `L*(L+1)/2` 个全零子串，累加得到 `Z`。
    - 把多加的 `9 * Z` 减回：`ans -= 9 * Z`。
- 最终 `ans` 即为所有连续子串（去掉前导零后表示的整数）的数字根之和。

```cpp
void solve()
{
    string s;
    cin >> s;
    int n = s.size();

    vector<int> cnt(9);
    int pref = 0;
    cnt[0] = 1;
    int ans = 0;
    for (int r = 0; r < n; r++)
    {
        pref = (pref + s[r] - '0') % 9; // 记录 pre[r]

        for (int t = 0; t <= 8; t++)
        {
            // pre[l - 1] % 9 == t
            auto val = (pref + 9 - t) % 9;
            ans += (val ? val : 9) * cnt[t];
        }

        cnt[pref]++;
    }

    int Z = 0;
    int L = 0;
    for (auto c : s)
    {
        if (c - '0' == 0)
        {
            L++;
        }
        else
        {
            Z += (L + 1) * L / 2;
            L = 0;
        }
    }

    Z += (L + 1) * L / 2; // 别忘了最后再算一次！
    ans -= 9 * Z;         // 每一个0多贡献了9
    cout << ans;
}
```

### F
正在写喵
