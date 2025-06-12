注意到 $2^n$ = $2^{n - 1} + 2^{n - 1}$ 所以对于任意一个 $i$ 我们统计出 $[0, i]$上最大的$a_j$和$b_k$ 那么肯定有$a_j > a_{i - j}$ 和 $b_k > b_{i - k}$ 所以可以认为所求值是由$max(a_j, b_k)$ 决定的 
即：
```cpp
int j = 0, k = 0;
for (int i = 0; i < n; i++)
{
	if (a[i] > a[j]) j = i;
	if (b[i] > b[k]) k = i;

	if (a[j] > b[k]) cout << ksm(2, a[j] + b[i - j]);
	else if (a[j] == b[k]) cout << ksm(2, a[j] + max(b[i - j], a[i - k]));
	else cout << ksm(2, b[k] + a[i - k]);
	cout << ' ';
}
```