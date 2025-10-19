### 在数组中高效判环
```cpp
vector<int> vis(n + 1);
for (int i = 1; i <= n; i++) {
	if (!vis[i]) {
		for (int r = i; !vis[r]; r = v[r]) {
			vis[r] = i;
		}
	}
}
```
  