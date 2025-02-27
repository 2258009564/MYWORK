# [2034C](https://codeforces.com/problemset/problem/2034/C)

> 题意：
> 给一个地图 标了上下左右四个方向 在地图中只能按照标点走 有一些问号可以用来自己定方向 问有多少个方块使得 无法离开地图

> 思路：
> 一开始 我的想法是用并查集把所有的点都标记上集合 然后遍历所有点 看看哪些节点是跟外界连着的 `n*m` 减去那些点 就是最终答案 但是实际操作的时候我遇到了问题 我无法对整个集合做“是否可以联通到外界” 的标记 导致复杂度过高
> 实际上 这题可以巧妙的把所有方向都反过来 这样就只需要bfs跑一遍 把所有能到达的地方都vis++ 对于所有的问号 如果 问号四周都已经被标记 说明无论如何他都跑不出去




 
# [2033E](https://codeforces.com/problemset/problem/2033/E)
> 题意：
> 一个置换图问题
> 用了并查集的思想 需要把所有`v[i]` 和 `v[v[i]]` 放到同一个集合里 如果集合的大小是1或者2就是符合要求的 否则我们应该把它从中间拆开 拆开的最佳方法就是每次分离两个 直到他剩下爱最后一个或者两个 而 分离两个需要一步交换操作

代码：
```cpp
int n;
cin >> n;
vector<int> v(n);
for (int i = 0; i < n; i++) cin >> v[i];
int ans = 0; // 记录交换的次数
vector<int> vis(n, 0);
for (int i = 0; i < n; i++)
{
	int x = i;
	int tot = 0; // 记录集合中有多少个元素
	while (!vis[x])
	{
		vis[x] = 1；
		tot++;
		x = v[x];
	}
	ans += (tot - 1) / 2;
}
cout << ans;
```
# [2033C](https://codeforces.com/problemset/problem/2033/C)
>题意：
>给一个数组 要求尽可能的把相同的相邻项分开

 >思路：
 >是一个贪心问题 但是我一开始没有想到 积累在这里 希望下一次能做出来

## [[贪心]]
从两边到中间 依次尝试更改 可以保证前面的结构已经最优
代码：
```cpp
int n;
cin >> n;
vector<int> v(n + 1, 0);
for (int i = 1; i <= n; i++) cin >> v[i];

// 固定v[1] 和 v[n]  这样我们第一步处理就是处理 v[1] v[2] 以及 v[n - 1] v[n] 之间的关系 不需要考虑他们之后的结构 达到贪心的目的

for (int i = 2; i <= n / 2; i++)
{
	if (v[i] == v[i - 1] or v[n + 1 - i] == v[n + 2 - i])
	{
		swap(v[i], v[n + 1 - i]);
	}
}

int ans = 0;
for (int i = 1; i + 1 <= n; i++) ans += v[i] == v[i + 1];

cout << ans;
```
# [2032C](https://codeforces.com/problemset/problem/2032/C)
> 题意：
> 需要把所有的三元组变成符合 `任意两个之和大于另一个` 的样子 问最小操作次数

> 思路：
> 让我们首先 `sort` 这样可以把问题转化为 `较小的两个之和大于最大的` 
> 此时 我们只需要保证头两个之和大于最后一个即可 把所有小于头两个的， 大于最后一个的 都做改变（不妨把他们都变成最大的）
> 实现过程值得细细品味。

代码：
```cpp
int n;
cin >> n;
vector<int> v(n);
for (int i = 0; i < n; i++) cin >> v[i];
ranges::sort(v);
vector<int> sum(n); // 记录最小的头两个 的可能情况
for (int i = 1; i < n; i++) sum[i] = v[i] + v[i - 1];
int ans = n;
for (int i = 1; i < n; i++)
{
	auto it = ranges::lower_bound(v, sum[i]); // 找到原数组中 不小于sum[i]的第一个位置
	// 所以 it 以及之后的元素 都需要处理， i - 1之前的元素需要处理
	ans = min(ans, i - 1 + distance(v.end(), it));
}
cout << ans;
```

# [2028B](https://codeforces.com/problemset/problem/2028/B)
> 题意：
> 找mex题 数据范围给的特别大 需要构造技巧

> 思路：
> 好像mex题目都是非常神秘的构造题？需要多多积累
> 这次说 $a_i = (i - 1) \cdot b + c$ 那么主要可以围绕几个方向讨论：
> - `b == 0` 此时所有$a_i$ 都等于c 而他会挑选最大的变成mex
> - `b != 0` 我们想要让所有的数字都在 $[0, n - 1]$ 范围内，也就是要让 $n - 1 >= m \cdot b + c$ 的m最大 移项即可直接求解m

代码：
```cpp
int n, b, c;
cin >> n >> b >> c;
int k = n - 1;
if (b == 0) // 所有的 a_i 一样
{
	if (k - c > 1)
	{
		cout << -1; // 差距太大无法构造
	}
	else if (k >= c)
	{
		cout << n - 1; // 有一个已经在了 不用构造
	}
	else // k < c
	{
		cout << n; // 全都需要构造
	}
}
else // b != 0
{
	if (c > k)
	{
		cout << n;
	}
	else
	{
		int m;
		// k >= m * b + c 要让 m 最大
		m = (k - c) / b;
		// 如果m == 0 就说明还有一个是已经在的 
		cout << n - max(0ll, 1 + m);
	}
}
```

这里的 `b != 0 and c > k` 比较难想
# [2027C](https://codeforces.com/problemset/problem/2027/C)

# [2026C](https://codeforces.com/problemset/problem/2026/C)

# [2020C](https://codeforces.com/problemset/problem/2020/C)

> 题意：
> 在i64范围内找到一个a 使得 $(a\ or\ b)\ -\ (a\ and\ c)\ ==\ d$  

>思路：
>这是肯定不能遍历的 观察发现对于每一位上 or 的结果一定不小于and 的结果
>所以这个操作是**位独立**的

所以我们把`b c d` 都转换成二进制 然后把所有可能列出来
值得注意的是 `1 0 0` 和 `0 1 1` 这两种情况是不可能出现的 
因为这两种情况下 不管a的值如何取 都不可能让d合法

> 总结：
> 下次遇到位运算多久多项移项 一位一位拆开来
# [2014D](https://codeforces.com/problemset/problem/2014/D)

感觉一天十道题写不完也吸收不完 决定降低一点 一天五道题如何？

# [[DAY 3]] 