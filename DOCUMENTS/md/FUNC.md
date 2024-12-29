下面是关于 C++ 中许多有用的 STL 函数的详细介绍，包括但不限于 `partial_sum`、`accumulate`、`transform` 等。这些函数主要来自 `<algorithm>` 和 `<numeric>` 头文件。

------

## **1. Accumulate and Reduction Functions**

### 1.1 `std::accumulate`

- **功能**：累加范围内的值，支持自定义操作。

- **头文件**：`<numeric>`

- 原型

  ：

  ```cpp
  T accumulate(InputIterator first, InputIterator last, T init);
  T accumulate(InputIterator first, InputIterator last, T init, BinaryOperation op);
  ```

- 示例

  ：

  ```cpp
  std::vector<int> nums = {1, 2, 3, 4, 5};
  int sum = std::accumulate(nums.begin(), nums.end(), 0); // 15
  int product = std::accumulate(nums.begin(), nums.end(), 1, std::multiplies<int>()); // 120
  ```

### 1.2 `std::reduce` (C++17)

- **功能**：类似 `accumulate`，但可以并行处理。

- **头文件**：`<numeric>`

- 原型

  ：

  ```cpp
  T reduce(ExecutionPolicy&& policy, InputIterator first, InputIterator last, T init);
  T reduce(InputIterator first, InputIterator last, T init, BinaryOperation op);
  ```

- 示例

  ：

  ```cpp
  std::vector<int> nums = {1, 2, 3, 4};
  int sum = std::reduce(nums.begin(), nums.end(), 0); // 10
  ```

------

## **2. Transformation and Manipulation Functions**

### 2.1 `std::transform`

- **功能**：对范围内的每个元素应用函数，存储结果。

- **头文件**：`<algorithm>`

- 原型

  ：

  ```cpp
  OutputIterator transform(InputIterator first, InputIterator last, OutputIterator result, UnaryOperation op);
  OutputIterator transform(InputIterator1 first1, InputIterator1 last1, InputIterator2 first2, OutputIterator result, BinaryOperation op);
  ```

- 示例

  ：

  ```cpp
  std::vector<int> nums = {1, 2, 3, 4};
  std::vector<int> squares(nums.size());
  std::transform(nums.begin(), nums.end(), squares.begin(), [](int x) { return x * x; });
  ```

### 2.2 `std::adjacent_difference`

- **功能**：计算相邻元素的差并存储结果。

- **头文件**：`<numeric>`

- 原型

  ：

  ```cpp
  OutputIterator adjacent_difference(InputIterator first, InputIterator last, OutputIterator result);
  OutputIterator adjacent_difference(InputIterator first, InputIterator last, OutputIterator result, BinaryOperation op);
  ```

- 示例

  ：

  ```cpp
  std::vector<int> nums = {1, 2, 4, 7};
  std::vector<int> diff(nums.size());
  std::adjacent_difference(nums.begin(), nums.end(), diff.begin()); // {1, 1, 2, 3}
  ```

------

## **3. Prefix and Partial Operations**

### 3.1 `std::partial_sum`

- **功能**：计算前缀和，支持自定义操作。

- **头文件**：`<numeric>`

- 原型

  ：

  ```cpp
  OutputIterator partial_sum(InputIterator first, InputIterator last, OutputIterator result);
  OutputIterator partial_sum(InputIterator first, InputIterator last, OutputIterator result, BinaryOperation op);
  ```

- 示例

  ：

  ```cpp
  std::vector<int> nums = {1, 2, 3, 4};
  std::vector<int> prefixSums(nums.size());
  std::partial_sum(nums.begin(), nums.end(), prefixSums.begin()); // {1, 3, 6, 10}
  ```

------

## **4. Sorting and Partitioning Functions**

### 4.1 `std::sort`

- **功能**：对范围内的元素排序。

- **头文件**：`<algorithm>`

- 原型

  ：

  ```cpp
  void sort(RandomIt first, RandomIt last);
  void sort(RandomIt first, RandomIt last, Compare comp);
  ```

- 示例

  ：

  ```cpp
  std::vector<int> nums = {4, 2, 1, 3};
  std::sort(nums.begin(), nums.end()); // {1, 2, 3, 4}
  ```

### 4.2 `std::stable_sort`

- **功能**：稳定排序，保持相等元素的顺序。

- **头文件**：`<algorithm>`

- 原型

  ：

  ```cpp
  void stable_sort(RandomIt first, RandomIt last);
  void stable_sort(RandomIt first, RandomIt last, Compare comp);
  ```

- 示例

  ：

  ```cpp
  std::vector<int> nums = {4, 2, 1, 3};
  std::stable_sort(nums.begin(), nums.end()); // {1, 2, 3, 4}
  ```

### 4.3  `std::partition`

- **功能**：将范围内的元素重新排列，使得满足条件的元素位于前半部分。

- **头文件**：`<algorithm>`

- 原型

  ：

  ```cpp
  ForwardIterator partition(ForwardIterator first, ForwardIterator last, UnaryPredicate pred);
  ```

- 示例

  ：

  ```cpp
  std::vector<int> nums = {1, 2, 3, 4, 5};
  std::partition(nums.begin(), nums.end(), [](int x) { return x % 2 == 0; }); // {2, 4, 3, 1, 5}
  ```

### 4.4 `std::partition_point`

- **功能**：在已按条件分区的范围中找到分区点。

- **头文件**：`<algorithm>`

- 原型

  ：

  ```cpp
  ForwardIterator partition_point(ForwardIterator first, ForwardIterator last, UnaryPredicate pred);
  ```

- 示例

  ：

  ```cpp
  std::vector<int> nums = {2, 4, 3, 1, 5}; // 已按条件分区
  auto it = std::partition_point(nums.begin(), nums.end(), [](int x) { return x % 2 == 0; }); // 指向 3
  ```



------

## **5. Searching and Counting**

### 5.1 `std::find`

- **功能**：在范围内查找等于指定值的元素。

- **头文件**：`<algorithm>`

- 原型

  ：

  ```cpp
  InputIterator find(InputIterator first, InputIterator last, const T& value);
  ```

- 示例

  ：

  ```cpp
  std::vector<int> nums = {1, 2, 3, 4};
  auto it = std::find(nums.begin(), nums.end(), 3); // 指向 3
  ```

### 5.2 `std::count`

- **功能**：计算范围内等于指定值的元素个数。

- **头文件**：`<algorithm>`

- 原型

  ：

  ```cpp
  typename iterator_traits<InputIterator>::difference_type
  count(InputIterator first, InputIterator last, const T& value);
  ```

- 示例

  ：

  ```cpp
  std::vector<int> nums = {1, 2, 3, 3, 4};
  int count = std::count(nums.begin(), nums.end(), 3); // 2
  ```

------

## **6. Unique and Set Operations**

### 6.1 `std::unique`

- **功能**：移除范围内的连续重复元素。

- **头文件**：`<algorithm>`

- 原型

  ：

  ```cpp
  ForwardIt unique(ForwardIt first, ForwardIt last);
  ForwardIt unique(ForwardIt first, ForwardIt last, BinaryPredicate p);
  ```

- 示例

  ：

  ```cpp
  std::vector<int> nums = {1, 1, 2, 2, 3};
  auto it = std::unique(nums.begin(), nums.end()); // {1, 2, 3}
  nums.erase(it, nums.end());
  ```

### 6.2 `std::set_union`

- **功能**：计算两个有序范围的并集。

- **头文件**：`<algorithm>`

- 原型

  ：

  ```cpp
  OutputIterator set_union(InputIterator1 first1, InputIterator1 last1, InputIterator2 first2, InputIterator2 last2, OutputIterator result);
  ```

- 示例

  ：

  ```cpp
  std::vector<int> a = {1, 2, 3};
  std::vector<int> b = {2, 3, 4};
  std::vector<int> result;
  std::set_union(a.begin(), a.end(), b.begin(), b.end(), std::back_inserter(result)); // {1, 2, 3, 4}
  ```



## **7. Numerical and Arithmetic Operations**

### 7.1 `std::inner_product`

- **功能**：计算两个范围的内积。

- **头文件**：`<numeric>`

- 原型

  ：

  ```cpp
  T inner_product(InputIterator1 first1, InputIterator1 last1, InputIterator2 first2, T init);
  T inner_product(InputIterator1 first1, InputIterator1 last1, InputIterator2 first2, T init, BinaryOperation1 op1, BinaryOperation2 op2);
  ```

- 示例

  ：

  ```cpp
  std::vector<int> a = {1, 2, 3};
  std::vector<int> b = {4, 5, 6};
  int result = std::inner_product(a.begin(), a.end(), b.begin(), 0); // 1*4 + 2*5 + 3*6 = 32
  ```

### 7.2 `std::iota`

- **功能**：为范围填充递增值。

- **头文件**：`<numeric>`

- 原型

  ：

  ```cpp
  void iota(ForwardIterator first, ForwardIterator last, T value);
  ```

- 示例

  ：

  ```cpp
  std::vector<int> nums(5);
  std::iota(nums.begin(), nums.end(), 1); // {1, 2, 3, 4, 5}
  ```

------

## **8. Permutation and Combination**

### 8.1 `std::next_permutation`

- **功能**：生成范围内元素的下一个排列。

- **头文件**：`<algorithm>`

- 原型

  ：

  ```cpp
  bool next_permutation(BidirectionalIt first, BidirectionalIt last);
  bool next_permutation(BidirectionalIt first, BidirectionalIt last, Compare comp);
  ```

- 示例

  ：

  ```cpp
  std::vector<int> nums = {1, 2, 3};
  std::next_permutation(nums.begin(), nums.end()); // {1, 3, 2}
  ```

### 8.2 `std::prev_permutation`

- **功能**：生成范围内元素的上一个排列。

- **头文件**：`<algorithm>`

- 原型

  ：

  ```cpp
  bool prev_permutation(BidirectionalIt first, BidirectionalIt last);
  bool prev_permutation(BidirectionalIt first, BidirectionalIt last, Compare comp);
  ```

- 示例

  ：

  ```cpp
  std::vector<int> nums = {1, 3, 2};
  std::prev_permutation(nums.begin(), nums.end()); // {1, 2, 3}
  ```

------

## **9. Search Algorithms**

### 9.1 `std::binary_search`

- **功能**：检查有序范围内是否包含某值。

- **头文件**：`<algorithm>`

- 原型

  ：

  ```cpp
  bool binary_search(ForwardIt first, ForwardIt last, const T& value);
  bool binary_search(ForwardIt first, ForwardIt last, const T& value, Compare comp);
  ```

- 示例

  ：

  ```cpp
  std::vector<int> nums = {1, 2, 3, 4, 5};
  bool found = std::binary_search(nums.begin(), nums.end(), 3); // true
  ```

### 9.2 `std::lower_bound`

- **功能**：找到有序范围中不小于某值的第一个位置。

- **头文件**：`<algorithm>`

- 原型

  ：

  ```cpp
  ForwardIt lower_bound(ForwardIt first, ForwardIt last, const T& value);
  ForwardIt lower_bound(ForwardIt first, ForwardIt last, const T& value, Compare comp);
  ```

- 示例

  ：

  ```cpp
  std::vector<int> nums = {1, 3, 3, 5, 7};
  auto it = std::lower_bound(nums.begin(), nums.end(), 3); // 指向第一个3
  ```

### 9.3 `std::upper_bound`

- **功能**：找到有序范围中大于某值的第一个位置。

- **头文件**：`<algorithm>`

- 原型

  ：

  ```cpp
  ForwardIt upper_bound(ForwardIt first, ForwardIt last, const T& value);
  ForwardIt upper_bound(ForwardIt first, ForwardIt last, const T& value, Compare comp);
  ```

- 示例

  ：

  ```cpp
  std::vector<int> nums = {1, 3, 3, 5, 7};
  auto it = std::upper_bound(nums.begin(), nums.end(), 3); // 指向5
  ```

------

## **10. Set Operations**

### 10.1 `std::set_difference`

- **功能**：计算两个有序范围的差集。

- **头文件**：`<algorithm>`

- 原型

  ：

  ```cpp
  OutputIterator set_difference(InputIterator1 first1, InputIterator1 last1, InputIterator2 first2, InputIterator2 last2, OutputIterator result);
  ```

- 示例

  ：

  ```cpp
  std::vector<int> a = {1, 2, 3};
  std::vector<int> b = {2, 3, 4};
  std::vector<int> result;
  std::set_difference(a.begin(), a.end(), b.begin(), b.end(), std::back_inserter(result)); // {1}
  ```

### 10.2 `std::set_intersection`

- **功能**：计算两个有序范围的交集。

- **头文件**：`<algorithm>`

- 原型

  ：

  ```cpp
  OutputIterator set_intersection(InputIterator1 first1, InputIterator1 last1, InputIterator2 first2, InputIterator2 last2, OutputIterator result);
  ```

- 示例

  ：

  ```cpp
  std::vector<int> a = {1, 2, 3};
  std::vector<int> b = {2, 3, 4};
  std::vector<int> result;
  std::set_intersection(a.begin(), a.end(), b.begin(), b.end(), std::back_inserter(result)); // {2, 3}
  ```

------

## **11. Copying and Filling**

### 11.1 `std::copy`

- **功能**：复制范围的元素到另一位置。

- **头文件**：`<algorithm>`

- 原型

  ：

  ```cpp
  OutputIterator copy(InputIterator first, InputIterator last, OutputIterator result);
  ```

- 示例

  ：

  ```cpp
  std::vector<int> nums = {1, 2, 3};
  std::vector<int> copy(nums.size());
  std::copy(nums.begin(), nums.end(), copy.begin());
  ```

### 11.2 `std::fill`

- **功能**：将范围内的所有元素赋值为指定值。

- **头文件**：`<algorithm>`

- 原型

  ：

  ```cpp
  void fill(ForwardIterator first, ForwardIterator last, const T& value);
  ```

- 示例

  ：

  ```cpp
  std::vector<int> nums(5);
  std::fill(nums.begin(), nums.end(), 42); // {42, 42, 42, 42, 42}
  ```

### 11.3 `std::generate`

- **功能**：用生成器函数填充范围内的元素。

- **头文件**：`<algorithm>`

- 原型

  ：

  ```cpp
  void generate(ForwardIterator first, ForwardIterator last, Generator g);
  ```

- 示例

  ：

  ```cpp
  std::vector<int> nums(5);
  int n = 1;
  std::generate(nums.begin(), nums.end(), [&n]() { return n++; }); // {1, 2, 3, 4, 5}
  ```



------

## **12. Functional Modifications**

### 12.2 `std::replace`

- **功能**：将范围内的所有匹配值替换为新值。

- **头文件**：`<algorithm>`

- 原型

  ：

  ```cpp
  void replace(ForwardIterator first, ForwardIterator last, const T& old_value, const T& new_value);
  ```

- 示例

  ：

  ```cpp
  std::vector<int> nums = {1, 2, 3, 2};
  std::replace(nums.begin(), nums.end(), 2, 42); // {1, 42, 3, 42}
  ```

------

## **13. Heap Operations**

### 13.1 `std::make_heap`

- **功能**：将范围的元素重排为堆。

- **头文件**：`<algorithm>`

- 原型

  ：

  ```cpp
  void make_heap(RandomAccessIterator first, RandomAccessIterator last);
  void make_heap(RandomAccessIterator first, RandomAccessIterator last, Compare comp);
  ```

- 示例

  ：

  ```cpp
  std::vector<int> nums = {3, 1, 4, 1, 5};
  std::make_heap(nums.begin(), nums.end()); // 堆化后的顺序：{5, 3, 4, 1, 1}
  ```

### 13.2 `std::push_heap`

- **功能**：将一个元素插入到堆中。

- **头文件**：`<algorithm>`

- 原型

  ：

  ```cpp
  void push_heap(RandomAccessIterator first, RandomAccessIterator last);
  void push_heap(RandomAccessIterator first, RandomAccessIterator last, Compare comp);
  ```

- 示例

  ：

  ```cpp
  std::vector<int> nums = {3, 1, 4};
  std::make_heap(nums.begin(), nums.end());
  nums.push_back(5);
  std::push_heap(nums.begin(), nums.end()); // 堆化后的顺序：{5, 3, 4, 1}
  ```

### 13.3 `std::pop_heap`

- **功能**：移除堆的最大元素（将其移动到范围末尾）。

- **头文件**：`<algorithm>`

- 原型

  ：

  ```cpp
  void pop_heap(RandomAccessIterator first, RandomAccessIterator last);
  void pop_heap(RandomAccessIterator first, RandomAccessIterator last, Compare comp);
  ```

- 示例

  ：

  ```cpp
  std::vector<int> nums = {3, 1, 4, 5};
  std::make_heap(nums.begin(), nums.end());
  std::pop_heap(nums.begin(), nums.end()); // 堆化后顺序：{4, 3, 1}，5在最后
  nums.pop_back(); // 删除最后的最大值
  ```

------

## **14. String Manipulation**

### 14.1 `std::getline`

- **功能**：从输入流中读取一整行。

- **头文件**：`<string>`

- 原型

  ：

  ```cpp
  std::istream& getline(std::istream& is, std::string& str);
  std::istream& getline(std::istream& is, std::string& str, char delim);
  ```

- 示例

  ：

  ```cpp
  std::string input;
  std::getline(std::cin, input); // 输入 "Hello, World!"，变量 input 为 "Hello, World!"
  ```

### 14.2 `std::stoi` / `std::stol` / `std::stof` / `std::stod`

- **功能**：将字符串转换为整数、长整数或浮点数。

- **头文件**：`<string>`

- 原型

  ：

  ```cpp
  int stoi(const std::string& str, std::size_t* idx = 0, int base = 10);
  long stol(const std::string& str, std::size_t* idx = 0, int base = 10);
  float stof(const std::string& str, std::size_t* idx = 0);
  double stod(const std::string& str, std::size_t* idx = 0);
  ```

- 示例

  ：

  ```cpp
  std::string s = "42";
  int n = std::stoi(s); // n = 42
  ```

## **15. Other Utilities**

### 15.1 `std::min_element` / `std::max_element`

- **功能**：返回范围内最小值或最大值的迭代器。

- **头文件**：`<algorithm>`

- 原型

  ：

  ```cpp
  ForwardIterator min_element(ForwardIterator first, ForwardIterator last);
  ForwardIterator max_element(ForwardIterator first, ForwardIterator last);
  ```

- 示例

  ：

  ```cpp
  std::vector<int> nums = {3, 1, 4, 1, 5};
  auto min_it = std::min_element(nums.begin(), nums.end()); // 指向 1
  auto max_it = std::max_element(nums.begin(), nums.end()); // 指向 5
  ```

### 15.2 `std::distance`

- **功能**：计算两个迭代器之间的距离。

- **头文件**：`<iterator>`

- 原型

  ：

  ```cpp
  typename std::iterator_traits<Iterator>::difference_type distance(InputIterator first, InputIterator last);
  ```

- 示例

  ：

  ```cpp
  std::vector<int> nums = {1, 2, 3, 4, 5};
  int dist = std::distance(nums.begin(), nums.end()); // 5
  ```

------

## **16. Randomized Algorithms**

### 16.1 `std::random_shuffle` (已弃用，建议用 `std::shuffle`)

- **功能**：随机重排范围内的元素。

- **头文件**：`<algorithm>`

- 原型

  ：

  ```cpp
  void random_shuffle(RandomAccessIterator first, RandomAccessIterator last);
  ```

- 示例

  ：

  ```cpp
  std::vector<int> nums = {1, 2, 3, 4, 5};
  std::random_shuffle(nums.begin(), nums.end()); // 随机顺序
  ```

### 16.2 `std::shuffle`

- **功能**：用给定的随机数生成器随机重排范围内的元素。

- **头文件**：`<algorithm>`

- 原型

  ：

  ```cpp
  void shuffle(RandomAccessIterator first, RandomAccessIterator last, URNG&& g);
  ```

- 示例

  ：

  ```cpp
  #include <random>
  std::vector<int> nums = {1, 2, 3, 4, 5};
  std::random_device rd;
  std::mt19937 gen(rd());
  std::shuffle(nums.begin(), nums.end(), gen); // 随机顺序
  ```

------

## **17. Bit Manipulation**

### 17.1 `std::bitset`

- **功能**：提供操作位序列的工具。

- **头文件**：`<bitset>`

- 原型

  ：

  ```cpp
  template<size_t N> class bitset;
  ```

- 示例

  ：

  ```cpp
  std::bitset<8> bs("1100");
  bs.set(0); // {1101}
  bs.flip(1); // {1111}
  ```

### 17.2 `std::popcount` (C++20)

- **功能**：计算一个整数的二进制表示中 1 的个数。

- **头文件**：`<bit>`

- 原型

  ：

  ```cpp
  int popcount(unsigned int x);
  ```

- 示例

  ：

  ```cpp
  #include <bit>
  int count = std::popcount(42); // 42 的二进制是 101010，popcount = 3
  ```

------

## **18. Numeric Algorithms**

### 18.1 `std::gcd`

- **功能**：计算两个数的最大公约数。

- **头文件**：`<numeric>`

- 原型

  ：

  ```cpp
  template<class T> T gcd(T x, T y);
  ```

- 示例

  ：

  ```cpp
  #include <numeric>
  int g = std::gcd(42, 56); // g = 14
  ```

### 18.2 `std::lcm`

- **功能**：计算两个数的最小公倍数。

- **头文件**：`<numeric>`

- 原型

  ：

  ```cpp
  template<class T> T lcm(T x, T y);
  ```

- 示例

  ：

  ```cpp
  #include <numeric>
  int l = std::lcm(6, 8); // l = 24
  ```

