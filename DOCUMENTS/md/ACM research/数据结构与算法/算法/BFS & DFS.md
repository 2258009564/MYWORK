> 仅用于帮自己在脑残忘记的时候补习，不是教程，特此说明。

## DFS vs BFS 核心差异

### DFS（深度优先）
```cpp
void dfs(当前状态) {
    if (达到目标) return;
    
    for (每个选择) {
        if (选择有效) {
            做选择;
            dfs(新状态);  // 递归深入
            撤销选择;     // 回溯
        }
    }
}
```

### BFS（广度优先）- 用队列模拟DFS
```cpp
void bfs() {
    queue<状态> q;
    q.push(初始状态);
    
    while (!q.empty()) {
        当前状态 = q.front(); q.pop();
        
        if (达到目标) return;
        
        for (每个选择) {
            if (选择有效) {
                q.push(新状态);  // 不是递归，而是加入队列
            }
        }
    }
}
```

## 用DFS思路理解你的代码

你的BFS实际上就是把DFS的递归调用栈换成了队列：

### DFS版本（你熟悉的）
```cpp
bool found = false;

void dfs(int cur, vector<bool>& used) {
    if (found) return;
    if (cur == (1 << n) - 1) {
        found = true;
        return;
    }
    
    for (int i = 0; i < n; i++) {
        if (used[i]) continue;  // 已经用过这个试剂
        
        int next = cur | (1 << i);
        if (!danger[next]) {    // 状态安全
            used[i] = true;
            dfs(next, used);    // 递归调用
            used[i] = false;    // 回溯
        }
    }
}
```

### BFS版本（你的代码）
```cpp
void bfs() {
    queue<int> q;
    vector<bool> visited(1 << n, false);
    
    q.push(0);
    visited[0] = true;
    
    while (!q.empty()) {
        int cur = q.front(); q.pop();
        
        if (cur == (1 << n) - 1) {
            cout << "Yes"; return;
        }
        
        for (int i = 0; i < n; i++) {
            if (cur & (1 << i)) continue;  // 相当于used[i]
            
            int next = cur | (1 << i);
            if (!visited[next] && !danger[next]) {
                visited[next] = true;
                q.push(next);              // 相当于递归调用
            }
        }
    }
    cout << "No";
}
```

## 关键对应关系

| DFS概念 | BFS等价 |
|---------|---------|
| 递归调用 | `q.push(新状态)` |
| 递归返回 | `q.pop()` |
| `used[]`数组 | `visited[]`数组 |
| 回溯撤销 | 不需要（因为每个状态独立处理） |

## 为什么BFS不需要回溯？

- **DFS**：同一个路径上的状态会相互影响，需要回溯
- **BFS**：每个状态都是独立的快照，包含了完整的信息

比如状态3（试剂1+2），在BFS中直接包含了"试剂1和2都已使用"的信息，不需要额外的`used`数组来记录。

## 你的代码思路总结

1. **状态表示**：用位掩码`cur`表示当前使用了哪些试剂
2. **状态转移**：`cur | (1 << i)` 表示在当前基础上添加试剂i
3. **避免重复**：`visited[]`防止重复访问同一状态
4. **安全检查**：`!danger[next]`确保新状态安全
