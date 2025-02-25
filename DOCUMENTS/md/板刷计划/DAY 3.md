#  [2010C1](https://codeforces.com/problemset/problem/2010/C1)

> 题意：
> 给一个（可能由两条字符串重叠形成的）字符串 让判断出原来的字符串 如果没有就输出-1

> 思路： 01234 i + x == n - 1
> 把字符串分为 `p o q` 三部分 要求`po == oq` 唯一的可能就是`p.size() -- q.size()` 所以我们直接从中间点开始遍历 看看`s.substr(0, i)` 是否等于`s.substr(n - i)` 即可

代码：
```cpp
string s;
cin >> s;
int n = s.size();
int k = n / 2 + 1;
for (int i = k; i < n; i++)
{
	if (s.substr(0, i) == s.substr(n - i))
	{
		cout << "YES" << endl << s.substr(0, i);
		return;
	}
}
cout << "NO";
```
#  [2009E](https://codeforces.com/problemset/problem/2009/E)

> 题意：
> 一个前缀和 - 一个后缀和 求绝对值

> 思路：
> 预处理前缀和 后缀和 记为sum1, sum2
> 找到`sum1 - sum2 >= 0` 的最大index 把index往前挪一位 就是 `sum2 - sum1 >= 0` 的最大数字 记录这两个数字 然后比较出 `min(abs())` 即可

代码：
```cpp
int n;
cin >> n;
vector<int> v(n);
for (int i = 0; i < n; i++) cin >> v[i];
vector<int> pre(n + 1, 0);
partial_sum(all(v), pre.begin() + 1);
// 0   1   2   3   4
// 1 + 2 + 3 + 4 + 5
// 那么 4 + 5 其实就是 总和 - (1 + 2 + 3)
/*
定义 pre[i] 是 前i个元素的前缀和
那么 pre[3] = v[0] + v[1] + v[2]
那么 要求的 v[4] + v[5] = pre[5] - pre[3]
*/

int l = 1, r = n, m, ans = INF, index;
while (l <= r)
{
	m = l + (r - l) / 2;
	if (pre[m] - (pre[n] - pre[m]) >= 0)
	{
		index = m;
		r = m - 1;
	}
	else
	{
		l = m + 1;
	}
}

cout << min(abs(pre[index] - (pre[n] - pre[index]), abs(pre[index - 1] - (pre[n] - pre[index - 1])));
```
#  [2009D](https://codeforces.com/problemset/problem/2009/D)

> 题意：
> 给一堆y = 0 或者y = 1 的点 求能构成多少个直角三角形

> 思路：
> 相对简单 但是我思考的时候还是脑抽
> 用一个map分别存下来y = 0 和 y = 1的点 然后对于每一个$(x, 0)$ 查找是否存在 $(x, 1)$ 如果存在 那么 `ans += (n - 2)` 
> 这之后 对于每一个$(x, 0)$ 查找是否同时存在$(x - 1, 1)$ 和 $(x + 1, 1)$， 对于每一个$(x, 0)$ 查找是否同时存在$(x - 1, 1)$ 和 $(x + 1, 1)$ 如果有的话 那就ans++;
#  [2008E](https://codeforces.com/problemset/problem/2008/E)

#  []()
#  []()

