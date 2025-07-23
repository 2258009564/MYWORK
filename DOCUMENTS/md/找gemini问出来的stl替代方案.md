# Java中C++ STL的替代方案（进阶）

作为一名C++ ACMer，您对STL（标准模板库）的强大和便利性一定深有体会。在Java中，虽然没有一个直接名为“STL”的库，但其“Java集合框架”（Java Collections Framework, JCF）以及其他核心库提供了与STL高度相似甚至更强大的功能。本节将更深入地探讨这些对应关系，并提供更多针对C++背景的细节。

## 1. 数据结构 (Containers)

| C++ STL容器             | Java对应类/接口                                      | 描述                                                                                                                                      |
| --------------------- | ----------------------------------------------- | --------------------------------------------------------------------------------------------------------------------------------------- |
| `std::vector`         | `java.util.ArrayList`                           | 动态数组，底层是数组实现。提供O(1)$的随机访问，插入/删除尾部$O(1)$均摊，中间插入/删除$O(N)。**与C++ `vector`类似，当容量不足时会自动扩容，这可能导致一次性较大的开销。**                                   |
| `std::list`           | `java.util.LinkedList`                          | 双向链表。提供O(1)$的插入/删除，但随机访问$O(N)。在需要频繁在列表两端或中间插入删除时很有用。**与C++ `list`不同，Java的`LinkedList`也实现了`List`接口，因此可以像`ArrayList`一样使用索引访问（虽然效率低）。**    |
| `std::deque`          | `java.util.ArrayDeque`                          | 双端队列，底层是循环数组。支持两端$O(1)$的插入和删除。也可以作为栈或队列使用。**在竞技编程中，`ArrayDeque`是实现队列和栈的首选，因为它比`LinkedList`作为队列/栈时性能更好。**                                |
| `std::set`            | `java.util.TreeSet`                             | 基于红黑树实现的有序集合。元素唯一且自动排序。插入、删除、查找都是O(logN)。**元素必须实现`Comparable`接口或在构造`TreeSet`时提供`Comparator`。**                                          |
| `std::unordered_set`  | `java.util.HashSet`                             | 基于哈希表实现的无序集合。元素唯一，不保证顺序。平均O(1)$的插入、删除、查找，最坏$O(N)。**元素需要正确实现`hashCode()`和`equals()`方法，否则可能导致错误的行为。**                                     |
| `std::map`            | `java.util.TreeMap`                             | 基于红黑树实现的有序键值对映射。键唯一且自动排序。插入、删除、查找都是O(logN)。**键必须实现`Comparable`接口或在构造`TreeMap`时提供`Comparator`。**                                         |
| `std::unordered_map`  | `java.util.HashMap`                             | 基于哈希表实现的无序键值对映射。键唯一，不保证顺序。平均O(1)$的插入、删除、查找，最坏$O(N)。**键需要正确实现`hashCode()`和`equals()`方法。**                                                |
| `std::queue`          | `java.util.LinkedList` 或 `java.util.ArrayDeque` | Java中没有专门的`Queue`类，但`LinkedList`和`ArrayDeque`都实现了`Queue`接口，并提供了队列操作（`offer`, `poll`, `peek`）。`ArrayDeque`通常是更好的选择，因为它在作为队列使用时性能更优。      |
| `std::priority_queue` | `java.util.PriorityQueue`                       | 优先队列，底层是堆实现。默认是小顶堆（最小元素优先），可以通过传入自定义比较器实现大顶堆。插入和删除都是O(logN)。**默认是小顶堆，若要实现大顶堆，需传入`Collections.reverseOrder()`或自定义`Comparator`。**         |
| `std::stack`          | `java.util.Stack` 或 `java.util.ArrayDeque`      | `java.util.Stack`是遗留类，不推荐使用。推荐使用`ArrayDeque`作为栈（`push`, `pop`, `peek`），因为它性能更好且更符合现代Java设计。                                             |
| `std::pair`           | `java.util.AbstractMap.SimpleEntry` 或自定义类       | Java没有直接的`pair`类型。通常使用`AbstractMap.SimpleEntry`（或`HashMap.Entry`）来表示键值对，或者为了更清晰的语义，自定义一个包含两个字段的简单类。**在竞技编程中，为了方便，通常会直接创建一个简单的`Pair`类。** |

**`std::pair` 的Java实现示例：**

```
// 自定义Pair类
class Pair<K, V> {
    public K key;
    public V value;

    public Pair(K key, V value) {
        this.key = key;
        this.value = value;
    }

    // 通常还会重写equals和hashCode方法，以便在集合中使用
    @Override
    public boolean equals(Object o) {
        if (this == o) return true;
        if (o == null || getClass() != o.getClass()) return false;
        Pair<?, ?> pair = (Pair<?, ?>) o;
        return Objects.equals(key, pair.key) &&
               Objects.equals(value, pair.value);
    }

    @Override
    public int hashCode() {
        return Objects.hash(key, value);
    }

    @Override
    public String toString() {
        return "(" + key + ", " + value + ")";
    }
}

// 使用示例
Pair<String, Integer> p = new Pair<>("apple", 10);
System.out.println(p.key + ": " + p.value); // apple: 10
```

**重要概念：**

- **接口与实现分离：** Java集合框架大量使用接口（如`List`, `Set`, `Map`, `Queue`）来定义行为，然后由具体的类（如`ArrayList`, `HashSet`, `HashMap`）来实现这些接口。这提供了更大的灵活性。**这意味着你可以用接口类型声明变量，而用具体实现类来创建对象，例如 `List<String> myList = new ArrayList<>();` 这种多态性在C++中通过基类指针/引用实现。**
    
- **泛型（Generics）：** Java的泛型 `<E>` 或 `<K, V>` 提供了编译时类型安全，类似于C++的模板。例如，`ArrayList<String>`表示一个只存储字符串的列表。
    

## 2. 算法 (Algorithms)

C++ STL的算法通常是独立函数，接受迭代器范围作为参数。在Java中，算法通常作为静态方法存在于工具类中，或者作为集合类自身的方法。

- **排序：**
    
    - C++: `std::sort(vec.begin(), vec.end());`
        
    - Java:
        
        - `Collections.sort(list);` (用于`List`，默认升序)
            
        - `Arrays.sort(array);` (用于数组，默认升序)
            
        - 自定义排序：通过传入`Comparator`接口的实现。
            
            ```
            import java.util.Collections;
            import java.util.Comparator;
            import java.util.List;
            import java.util.ArrayList;
            
            // 对List进行降序排序
            List<String> names = new ArrayList<>(List.of("Alice", "Bob", "Charlie"));
            Collections.sort(names, (a, b) -> b.compareTo(a)); // Lambda表达式
            System.out.println(names); // [Charlie, Bob, Alice]
            
            // 或者使用方法引用
            Collections.sort(names, Comparator.reverseOrder());
            System.out.println(names); // [Alice, Bob, Charlie] (又变回升序，因为reverseOrder是对自然顺序的逆序)
            
            // 对自定义对象列表排序
            class Student {
                String name;
                int score;
                public Student(String name, int score) { this.name = name; this.score = score; }
                public int getScore() { return score; }
                @Override public String toString() { return name + ":" + score; }
            }
            List<Student> students = new ArrayList<>();
            students.add(new Student("Alice", 90));
            students.add(new Student("Bob", 85));
            students.add(new Student("Charlie", 92));
            
            // 按分数升序排序
            Collections.sort(students, Comparator.comparingInt(Student::getScore));
            System.out.println(students); // [Bob:85, Alice:90, Charlie:92]
            
            // 按分数降序排序
            Collections.sort(students, Comparator.comparingInt(Student::getScore).reversed());
            System.out.println(students); // [Charlie:92, Alice:90, Bob:85]
            ```
            
- **查找：**
    
    - C++: `std::find(vec.begin(), vec.end(), value);`
        
    - Java: 集合类通常有`contains()`方法。对于更复杂的查找，需要手动遍历或使用Java 8的Stream API。
        
        - `list.contains(value);`
            
        - `map.containsKey(key);`
            
        - `map.containsValue(value);`
            
    - **二分查找：**
        
        - C++: `std::lower_bound`, `std::upper_bound`, `std::binary_search`
            
        - Java: `Collections.binarySearch(list, key);` 或 `Arrays.binarySearch(array, key);`。**注意：Java的`binarySearch`返回的是索引，如果找不到，返回 `(-(insertion point) - 1)`。它没有直接的`lower_bound`和`upper_bound`功能，需要自行实现或结合`binarySearch`的结果进行判断。**
            
- **最大/最小值：**
    
    - C++: `*std::max_element(vec.begin(), vec.end());`
        
    - Java:
        
        - `Collections.max(collection);`
            
        - `Collections.min(collection);`
            
        - 对于自定义对象，需要传入`Comparator`。
            
- **遍历：**
    
    - C++: 基于范围的for循环 `for (int x : vec)` 或迭代器 `for (auto it = vec.begin(); it != vec.end(); ++it)`
        
    - Java:
        
        - 增强型for循环 (foreach): `for (Type element : collection)`
            
        - 迭代器: `Iterator<Type> it = collection.iterator(); while (it.hasNext()) { Type element = it.next(); }`
            
        - Java 8 Stream API: 提供了更函数式的操作，如`forEach`, `map`, `filter`, `reduce`等。
            
            ```
            List<String> words = new ArrayList<>(List.of("apple", "banana", "cat", "dog"));
            words.stream()
                .filter(s -> s.length() > 3) // 过滤长度大于3的字符串
                .map(String::toUpperCase)   // 转换为大写
                .forEach(System.out::println); // 打印每个结果
            // 输出:
            // APPLE
            // BANANA
            // CHARLIE (如果之前有Charlie)
            ```
            

## 3. 迭代器 (Iterators)

C++ STL的迭代器是泛型指针，指向容器中的元素，支持指针算术（如`it + 5`）。Java的迭代器是对象，并且行为更受限制。

- **`java.util.Iterator<E>`：** 用于顺序遍历集合。
    
    - `hasNext()`: 检查是否还有下一个元素。
        
    - `next()`: 返回下一个元素并前进迭代器。
        
    - `remove()`: 从底层集合中移除迭代器最后返回的元素（可选操作）。**注意：在遍历过程中使用集合的`add()`或`remove()`方法（而不是迭代器自身的`remove()`）会导致`ConcurrentModificationException`。**
        
- **`java.util.ListIterator<E>`：** 仅用于`List`接口的实现（如`ArrayList`, `LinkedList`），提供了双向遍历和在遍历过程中修改列表的能力。
    
    - 除了`hasNext()`, `next()`, `remove()`，还提供`hasPrevious()`, `previous()`, `add()`, `set()`, `nextIndex()`, `previousIndex()`等方法。
        

**与C++迭代器的主要区别：**

- **无指针算术：** Java迭代器不支持`it + N`或`it - N`这样的操作。要跳过多个元素，需要多次调用`next()`。
    
- **类型安全：** Java迭代器是泛型的，提供了编译时类型检查。
    
- **修改限制：** 在遍历过程中修改集合（除了通过迭代器自身的`remove()`或`add()`方法）会导致运行时错误。
    

## 4. 泛型 (Generics)

C++的模板在编译时生成特定类型的代码。Java的泛型在编译时进行类型检查，并在运行时擦除类型信息（Type Erasure），这意味着运行时所有泛型类型都被替换为其边界类型（通常是`Object`）。

- **优势：** 提供了编译时类型安全，避免了强制类型转换和运行时`ClassCastException`。
    
- **限制（类型擦除的影响）：**
    
    - **不能直接创建泛型数组：** 例如，`new T[size]` 是不允许的。你需要创建`Object[]`然后进行强制类型转换，这通常会产生一个警告。
        
        ```
        // 错误：不能直接创建泛型数组
        // T[] array = new T[capacity];
        
        // 正确但有警告：
        // T[] array = (T[]) new Object[capacity];
        ```
        
    - **不能在运行时获取泛型类型信息：** 例如，`list instanceof ArrayList<String>` 是不允许的，因为运行时`ArrayList<String>`和`ArrayList<Integer>`都被擦除为`ArrayList`。
        
    - **不能使用基本类型作为泛型参数：** 例如，`ArrayList<int>` 是不允许的。你必须使用对应的包装类，如 `ArrayList<Integer>`。
        

## 5. 输入/输出 (Input/Output)

在ACM/ICPC等竞技编程中，高效的I/O至关重要。

- **标准输入：**
    
    - C++: `cin >> var;`
        
    - Java: `java.util.Scanner` 是最常用的，但对于大量数据，`BufferedReader` 更快。
        
        ```
        import java.io.BufferedReader;
        import java.io.InputStreamReader;
        import java.io.IOException;
        import java.util.Scanner;
        
        // 使用Scanner (方便，但可能较慢)
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        String s = sc.next();
        double d = sc.nextDouble();
        sc.nextLine(); // 消费掉nextInt/next等操作后留下的换行符，避免影响后续readLine()
        
        // 使用BufferedReader (更推荐用于竞技编程，速度快)
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        try {
            String line = br.readLine(); // 读取一行
            String[] parts = line.split(" "); // 分割字符串
            int num = Integer.parseInt(parts[0]); // 转换为整数
        
            // 读取整数数组
            int[] arr = new int[n];
            String[] numStrs = br.readLine().split(" ");
            for (int i = 0; i < n; i++) {
                arr[i] = Integer.parseInt(numStrs[i]);
            }
        } catch (IOException e) {
            e.printStackTrace();
        }
        ```
        
- **标准输出：**
    
    - C++: `cout << var << endl;`
        
    - Java: `System.out.print()`, `System.out.println()`, `System.out.printf()`。对于大量输出，`PrintWriter` 更快。
        
        ```
        import java.io.BufferedWriter;
        import java.io.OutputStreamWriter;
        import java.io.PrintWriter;
        import java.io.IOException;
        
        System.out.println("Hello World!");
        System.out.printf("Value: %d%n", 123); // %n 是平台独立的换行符
        
        // 使用PrintWriter (更推荐用于竞技编程，速度快)
        PrintWriter pw = new PrintWriter(new BufferedWriter(new OutputStreamWriter(System.out)));
        pw.println("Result: " + result);
        pw.print("Another line without newline.");
        pw.printf("Formatted output: %.2f%n", 123.456);
        pw.flush(); // 确保输出被写入缓冲区，非常重要！
        // pw.close(); // 在程序结束时关闭，但竞技编程中通常不需要显式关闭System.out的PrintWriter
        ```
        

**竞技编程I/O模板：**

```
import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.InputStreamReader;
import java.io.OutputStreamWriter;
import java.io.PrintWriter;
import java.io.IOException;
import java.util.StringTokenizer; // 用于更高效地分割字符串

public class Main {
    static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    static PrintWriter pw = new PrintWriter(new BufferedWriter(new OutputStreamWriter(System.out)));
    static StringTokenizer st;

    // 读取下一个token
    static String next() throws IOException {
        while (st == null || !st.hasMoreTokens()) {
            st = new StringTokenizer(br.readLine());
        }
        return st.nextToken();
    }

    // 读取下一个整数
    static int nextInt() throws IOException {
        return Integer.parseInt(next());
    }

    // 读取下一个长整数
    static long nextLong() throws IOException {
        return Long.parseLong(next());
    }

    // 读取下一个双精度浮点数
    static double nextDouble() throws IOException {
        return Double.parseDouble(next());
    }

    // 读取一行
    static String readLine() throws IOException {
        return br.readLine();
    }

    public static void main(String[] args) throws IOException {
        // 在这里编写您的主要逻辑
        int T = nextInt(); // 读取测试用例数量
        while (T-- > 0) {
            int N = nextInt();
            int M = nextInt();
            pw.println(N + M); // 打印结果
        }

        pw.flush(); // 务必刷新缓冲区
        // pw.close(); // 通常不需要显式关闭
    }
}
```

## 6. 其他常用工具类

- **字符串：**
    
    - C++: `std::string`
        
    - Java: `java.lang.String` (不可变), `java.lang.StringBuilder` (可变，用于字符串拼接，性能优于`+`操作符)。**C++的`std::string`是可变的，而Java的`String`是不可变的。频繁的字符串修改操作应使用`StringBuilder`，类似于C++中对字符串进行大量拼接时考虑的效率问题。**
        
- **数学运算：**
    
    - C++: `<cmath>` 中的函数
        
    - Java: `java.lang.Math` 类提供了各种数学函数（`sqrt`, `pow`, `abs`, `min`, `max`等）。
        
- **大整数：**
    
    - C++: 通常需要手写或使用第三方库。
        
    - Java: `java.math.BigInteger` (任意精度整数), `java.math.BigDecimal` (任意精度浮点数)。**这是Java在竞技编程中的一大优势，可以直接处理超出`long long`范围的整数。**
        
- **时间/日期：**
    
    - C++: `<chrono>`, `<ctime>`
        
    - Java: `java.util.Date`, `java.util.Calendar` (旧API)，`java.time` 包 (Java 8及以后推荐的新API，更强大和易用)。
        
- **随机数：**
    
    - C++: `<random>`
        
    - Java: `java.util.Random`。
        

## 7. C++ STL算法在Java中的替代（更详细）

许多C++ `std::algorithm` 中的函数在Java中没有直接的、通用的对应方法，但可以通过Stream API或手动实现来达到类似效果。

- **`std::fill`：** 填充容器
    
    - Java: `Arrays.fill(array, value);` 或手动循环。
        
- **`std::copy`：** 复制元素
    
    - Java: `System.arraycopy(src, srcPos, dest, destPos, length);` 或手动循环。
        
- **`std::unique`：** 去重（需要先排序）
    
    - Java: 通常结合Stream API或手动遍历。
        
        ```
        List<Integer> numbers = new ArrayList<>(List.of(1, 2, 2, 3, 3, 3, 4));
        // 使用Stream API去重
        List<Integer> distinctNumbers = numbers.stream().distinct().collect(Collectors.toList());
        System.out.println(distinctNumbers); // [1, 2, 3, 4]
        ```
        
- **`std::next_permutation` / `std::prev_permutation`：** 生成下一个/上一个字典序排列
    
    - Java: 没有直接的库函数。通常需要自己实现，算法与C++的实现原理类似。
        
- **`std::iota`：** 填充递增序列
    
    - Java: 手动循环。
        
        ```
        int[] arr = new int[5];
        for (int i = 0; i < arr.length; i++) {
            arr[i] = i + 1; // 填充 1, 2, 3, 4, 5
        }
        ```
        

## 8. 性能注意事项

- **自动装箱/拆箱：** Java集合框架只能存储对象，因此当你将基本类型（`int`, `double`等）放入集合时，它们会自动装箱（转换为对应的包装类`Integer`, `Double`等），取出时会自动拆箱。这会带来额外的性能开销和内存消耗。在竞技编程中，如果性能敏感，有时会使用基本类型数组而不是`ArrayList<Integer>`。
    
- **`hashCode()` 和 `equals()`：** 对于`HashSet`, `HashMap`, `TreeSet`, `TreeMap`等基于哈希或比较的集合，如果你存储自定义对象，必须正确重写`hashCode()`和`equals()`（对于哈希表）或实现`Comparable` / 提供`Comparator`（对于树结构），否则集合的行为可能不符合预期。
    
- **`Stream API`：** Java 8引入的Stream API提供了非常简洁和函数式的编程风格，但其性能开销可能比传统循环略高。在对性能要求极高的竞技编程场景中，有时仍需权衡使用。
    

## 9. 面向对象特性

Java是纯粹的面向对象语言，这意味着一切皆对象（除了基本类型）。STL中的容器和算法在Java中也以类和对象的形式存在。

- **方法调用：** C++中你可能习惯于`std::sort(vec.begin(), vec.end())`，而在Java中，你会看到`Collections.sort(list)`，这是`Collections`工具类的静态方法。集合自身也有方法，如`list.add()`，`map.get()`。
    
- **接口：** Java集合框架大量依赖接口。理解`List`, `Set`, `Map`, `Queue`等接口的定义及其具体实现类的特点是掌握JCF的关键。
    

## 总结

Java的集合框架和核心库提供了与C++ STL非常相似的功能，甚至在某些方面（如内置的大整数支持、Stream API）更为强大。作为C++ ACMer，您在数据结构和算法方面的知识将是巨大的优势。您需要适应的是Java的面向对象特性、接口与实现的分离、泛型的工作方式以及一些常用的工具类。掌握了这些，您会发现用Java进行竞技编程同样高效和愉快。

祝您在Java的竞技编程之旅中取得好成绩！