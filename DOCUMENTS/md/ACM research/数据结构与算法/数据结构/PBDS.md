# PBDS (Policy-Based Data Structures)

PBDS 是 GCC 编译器提供的一套基于策略的数据结构库，包含了许多高效的数据结构，在算法竞赛中非常实用。

## 引入头文件

```cpp
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
```

## 核心数据结构

### 1. ordered_set / ordered_map

这是 PBDS 中最常用的数据结构，支持排序和按排名查找。

#### 基本定义

```cpp
// ordered_set：有序集合
typedef tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> ordered_set;

// ordered_map：有序映射
typedef tree<int, int, less<int>, rb_tree_tag, tree_order_statistics_node_update> ordered_map;

// 支持重复元素的 multiset
typedef tree<int, null_type, less_equal<int>, rb_tree_tag, tree_order_statistics_node_update> ordered_multiset;
```

#### 基本操作

```cpp
void pbds_basic_demo() {
    ordered_set s;

    // 插入元素
    s.insert(1);
    s.insert(3);
    s.insert(5);
    s.insert(7);

    // 查找第 k 小的元素（0-indexed）
    cout << *s.find_by_order(0) << endl;  // 输出 1（第 0 小）
    cout << *s.find_by_order(2) << endl;  // 输出 5（第 2 小）

    // 查找小于 x 的元素个数
    cout << s.order_of_key(5) << endl;    // 输出 2（小于 5 的有 1,3）
    cout << s.order_of_key(6) << endl;    // 输出 3（小于 6 的有 1,3,5）

    // 删除元素
    s.erase(3);

    // 普通 set 的操作也支持
    cout << s.size() << endl;             // 输出 3
    cout << s.count(5) << endl;           // 输出 1
}
```

#### 处理重复元素

```cpp
void multiset_demo() {
    // 方法1：使用 less_equal
    typedef tree<int, null_type, less_equal<int>, rb_tree_tag, tree_order_statistics_node_update> ordered_multiset;

    ordered_multiset ms;
    ms.insert(1);
    ms.insert(1);
    ms.insert(2);
    ms.insert(2);
    ms.insert(2);

    cout << ms.order_of_key(2) << endl;    // 小于 2 的元素个数
    cout << *ms.find_by_order(2) << endl;  // 第 2 小的元素

    // 删除一个特定值（注意：less_equal 下删除会删除所有相同元素）
    ms.erase(ms.find_by_order(ms.order_of_key(2)));

    // 方法2：使用 pair 处理重复元素
    typedef tree<pair<int, int>, null_type, less<pair<int, int>>, rb_tree_tag, tree_order_statistics_node_update> ordered_set_with_duplicates;

    ordered_set_with_duplicates s2;
    int cnt = 0;
    s2.insert({1, cnt++});  // {value, unique_id}
    s2.insert({1, cnt++});
    s2.insert({2, cnt++});

    // 查找值为 x 的元素个数
    auto lower = s2.lower_bound({1, -1});
    auto upper = s2.lower_bound({2, -1});
    cout << "值为 1 的元素个数: " << distance(lower, upper) << endl;
}
```

### 2. 优先队列 (priority_queue)

PBDS 提供了更灵活的优先队列实现：

```cpp
#include <ext/pb_ds/priority_queue.hpp>

void priority_queue_demo() {
    // 不同类型的优先队列
    __gnu_pbds::priority_queue<int> pq1;  // 默认：二叉堆
    __gnu_pbds::priority_queue<int, greater<int>, pairing_heap_tag> pq2;  // 配对堆，最小堆
    __gnu_pbds::priority_queue<int, less<int>, thin_heap_tag> pq3;  // 斐波那契堆

    // 支持修改操作的优先队列
    typedef __gnu_pbds::priority_queue<int>::point_iterator pq_iterator;
    __gnu_pbds::priority_queue<int> pq;

    // 插入并获取迭代器
    pq_iterator it1 = pq.push(10);
    pq_iterator it2 = pq.push(20);
    pq_iterator it3 = pq.push(5);

    cout << "Top: " << pq.top() << endl;  // 输出 20

    // 修改指定位置的值
    pq.modify(it1, 25);  // 将 10 修改为 25
    cout << "New top: " << pq.top() << endl;  // 输出 25

    // 删除指定位置的元素
    pq.erase(it2);

    // 合并两个优先队列
    __gnu_pbds::priority_queue<int> pq_other;
    pq_other.push(15);
    pq_other.push(30);
    pq.join(pq_other);  // pq_other 会被清空
}
```

### 3. 哈希表 (gp_hash_table / cc_hash_table)

```cpp
#include <ext/pb_ds/assoc_container.hpp>

void hash_table_demo() {
    // gp_hash_table：基于探测的哈希表
    __gnu_pbds::gp_hash_table<int, int> gp_ht;

    // cc_hash_table：基于链式的哈希表
    __gnu_pbds::cc_hash_table<int, int> cc_ht;

    // 基本操作
    gp_ht[1] = 10;
    gp_ht[2] = 20;
    cc_ht[1] = 100;
    cc_ht[2] = 200;

    cout << gp_ht[1] << " " << cc_ht[1] << endl;

    // 自定义哈希函数
    struct custom_hash {
        size_t operator()(const pair<int, int>& p) const {
            return hash<int>()(p.first) ^ (hash<int>()(p.second) << 1);
        }
    };

    __gnu_pbds::gp_hash_table<pair<int, int>, int, custom_hash> custom_ht;
    custom_ht[{1, 2}] = 42;
}
```

## 实战应用

### 1. 求逆序对

```cpp
long long count_inversions(vector<int>& arr) {
    ordered_set s;
    long long inversions = 0;

    for (int i = arr.size() - 1; i >= 0; i--) {
        // 小于 arr[i] 的元素个数就是以 arr[i] 为左端点的逆序对数
        inversions += s.order_of_key(arr[i]);
        s.insert(arr[i]);
    }

    return inversions;
}
```

### 2. 动态第 k 小

```cpp
class KthLargest {
private:
    ordered_set s;
    int k;

public:
    KthLargest(int k) : k(k) {}

    void add(int val) {
        s.insert(val);
    }

    int kthLargest() {
        if (s.size() < k) return -1;
        return *s.find_by_order(s.size() - k);  // 第 k 大 = 第 (n-k) 小
    }

    int kthSmallest() {
        if (s.size() < k) return -1;
        return *s.find_by_order(k - 1);  // 第 k 小（0-indexed）
    }
};
```

### 3. 区间不同元素个数

```cpp
struct Query {
    int l, r, id;
};

vector<int> solve_distinct_elements(vector<int>& arr, vector<Query>& queries) {
    int n = arr.size();
    int q = queries.size();

    // 按右端点排序
    sort(queries.begin(), queries.end(), [](const Query& a, const Query& b) {
        return a.r < b.r;
    });

    vector<int> ans(q);
    ordered_set s;
    unordered_map<int, int> last_pos;

    int query_idx = 0;
    for (int i = 0; i < n; i++) {
        // 如果当前元素之前出现过，先删除之前的位置
        if (last_pos.count(arr[i])) {
            s.erase(last_pos[arr[i]]);
        }

        // 插入当前位置
        s.insert(i);
        last_pos[arr[i]] = i;

        // 处理右端点为 i 的查询
        while (query_idx < q && queries[query_idx].r == i) {
            int l = queries[query_idx].l;
            // 统计 >= l 的位置个数
            ans[queries[query_idx].id] = s.size() - s.order_of_key(l);
            query_idx++;
        }
    }

    return ans;
}
```

### 4. 可持久化数组

```cpp
// 使用 PBDS 的 tree 模拟可持久化数组
class PersistentArray {
private:
    typedef tree<int, int, less<int>, rb_tree_tag, tree_order_statistics_node_update> version_tree;
    vector<version_tree> versions;

public:
    PersistentArray(vector<int>& initial) {
        version_tree v0;
        for (int i = 0; i < initial.size(); i++) {
            v0.insert({i, initial[i]});
        }
        versions.push_back(v0);
    }

    // 基于版本 ver 修改位置 pos 的值为 val，返回新版本号
    int update(int ver, int pos, int val) {
        version_tree new_version = versions[ver];  // 复制
        new_version.erase(new_version.find_by_order(new_version.order_of_key(pos)));
        new_version.insert({pos, val});
        versions.push_back(new_version);
        return versions.size() - 1;
    }

    // 查询版本 ver 中位置 pos 的值
    int query(int ver, int pos) {
        auto it = versions[ver].find_by_order(versions[ver].order_of_key(pos));
        return it->second;
    }
};
```

## 性能比较

| 操作        | std::set   | ordered_set | std::priority_queue | pbds::priority_queue |
| ----------- | ---------- | ----------- | ------------------- | -------------------- |
| 插入        | O(log n)   | O(log n)    | O(log n)            | O(log n)             |
| 删除        | O(log n)   | O(log n)    | O(log n)            | O(log n)             |
| 查找第 k 小 | O(n)       | O(log n)    | 不支持              | 不直接支持           |
| 查找排名    | O(n)       | O(log n)    | 不支持              | 不支持               |
| 修改元素    | 删除+插入  | 删除+插入   | 不支持              | O(log n)             |
| 合并        | O(n log n) | O(n log n)  | 不支持              | O(log n)             |

## 注意事项

1. **编译器支持**：PBDS 只在 GCC 编译器中可用，其他编译器不支持
2. **头文件**：需要包含特定的头文件，不是标准 C++ 库
3. **命名空间**：使用 `__gnu_pbds` 命名空间
4. **重复元素**：默认的 `ordered_set` 不支持重复元素，需要特殊处理
5. **调试**：某些在线判题系统可能不支持 PBDS

## 常用模板

```cpp
// 万能头文件中的 PBDS 设置
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;

// 常用类型定义
typedef tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> ordered_set;
typedef tree<pair<int, int>, null_type, less<pair<int, int>>, rb_tree_tag, tree_order_statistics_node_update> ordered_set_pair;

// 可修改优先队列
typedef __gnu_pbds::priority_queue<int>::point_iterator pq_iterator;

// 哈希表
typedef __gnu_pbds::gp_hash_table<int, int> fast_map;
```

PBDS 是算法竞赛中的强力工具，特别是 `ordered_set` 在处理排序、排名相关问题时非常有用！
