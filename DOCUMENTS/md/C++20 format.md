# C++20 std::format 用法详解

在 C++20 中，格式化输出的功能得到了显著增强，使得我们在打印信息时可以更加简单和灵活。接下来，我们将一步一步讲解这个新特性

## 什么是格式化输出？

格式化输出是指将数据以特定的方式呈现出来，允许我们控制数字的小数点位数、字符串的对齐方式等。比如，当我们要告诉别人“需要3个苹果、500克面粉、1升牛奶”时，格式化输出就像是把这些信息整理得更加清晰易读。

## C++20中的格式化输出

在 C++20 之前，C++ 的输出通常使用 `std::cout`，像这样：

```cpp
#include <iostream>

int main() {
    int apples = 3;
    double flour = 500.0;
    double milk = 1.0;
    std::cout << "需要" << apples << "个苹果、" << flour << "克面粉、" << milk << "升牛奶。" << std::endl;
    return 0;
}
```

这段代码可以输出简单的信息，但当数据变得复杂时，就会显得有点杂乱。

### 引入 `<format>` 库

C++20 引入了一个新的库，叫做 `<format>`，它提供了一种更直观的方式来进行格式化输出。使用这个库，我们可以通过一种更加易读的方式来构造输出字符串。

## `<format>` 库的基础用法

要使用 `<format>` 库，我们首先需要包含这个库：

```cpp
#include <format>
```

然后，我们可以使用 `std::format` 函数，它允许我们使用占位符来定义输出格式。

### 占位符的使用

占位符使用花括号 `{}` 表示，程序会在输出时自动替换成对应的变量值。例如：

```cpp
#include <iostream>
#include <format>

int main() {
    int apples = 3;
    double flour = 500.0;
    double milk = 1.0;
    
    std::string output = std::format("需要{}个苹果、{}克面粉、{}升牛奶。", apples, flour, milk);
    std::cout << output << std::endl;

    return 0;
}
```

这里，`{}` 就像是一个空框，C++ 会将 `apples`、`flour` 和 `milk` 的值填进去，最终输出清晰易读的内容。

## 格式化选项

`<format>` 库不仅可以格式化输出，还可以提供各种选项来调整输出的样式。

### 控制小数位数

假设我们希望在输出中，面粉的量只保留一位小数，可以这样做：

```cpp
#include <iostream>
#include <format>

int main() {
    double flour = 500.12345;
    
    std::string output = std::format("面粉的量是{:.1f}克。", flour); // {:.1f}表示保留1位小数
    std::cout << output << std::endl;

    return 0;
}
```

这里的 `{:.1f}` 表示这个数字是浮点数（f），并且只保留1位小数。

### 对齐输出

如果你希望数字在输出中能够对齐，可以使用冒号 `:` 后面跟上格式，比如：

```cpp
#include <iostream>
#include <format>

int main() {
    int apples = 3;
    double flour = 500.12345;
    double milk = 1.0;

    std::string output = std::format("{:<10} | {:>10} | {:>10}\n", "苹果", apples, flour);
    output += std::format("{:<10} | {:>10} | {:>10}\n", "面粉", "", flour);
    output += std::format("{:<10} | {:>10} | {:>10}\n", "牛奶", "", milk);
    std::cout << output;

    return 0;
}
```

在这个例子中，`{:<10}` 表示左对齐，宽度为10个字符；`{:>10}` 表示右对齐，宽度也为10个字符。这样一来，输出就显得整齐了。

## 格式化数字

### 填充和宽度

我们还可以控制输出数字的填充和宽度。比如，如果我们希望数字用零填充至8位，可以这样写：

```cpp
#include <iostream>
#include <format>

int main() {
    int number = 42;
    std::string output = std::format("数字是：{:0>8}", number); // 用0填充至8位
    std::cout << output << std::endl; // 输出: 数字是：00000042

    return 0;
}
```

这里的 `{:<8}` 表示左对齐并填充空格，`{:0>8}` 则表示右对齐并用零填充。

### 进制格式化

我们还可以轻松地格式化为不同的进制。例如，如果我们想将整数以十六进制形式输出，可以使用 `{:#x}`：

```cpp
#include <iostream>
#include <format>

int main() {
    int value = 255;
    std::string hexOutput = std::format("十六进制：{:#x}", value); // 输出十六进制
    std::cout << hexOutput << std::endl; // 输出: 十六进制：0xff

    return 0;
}
```

## 混合使用

### 右对齐并保留小数

如果你想将一个浮点数右对齐到8位，并保留三位小数，可以这样使用 `std::format`：

```cpp
#include <iostream>
#include <format>

int main() {
    double value = 123.456789;
    
    std::string output = std::format("值是：{:>8.3f}", value); // 右对齐，保留三位小数
    std::cout << output << std::endl; // 输出: 值是： 123.457

    return 0;
}
```

在这个例子中，`{:>8.3f}` 表示：

- `>`：右对齐
- `8`：总宽度为8个字符
- `.3`：小数点后保留三位
- `f`：格式为浮点数

## 自定义格式化

如果需要为自定义类型实现格式化，可以通过特化 `std::formatter` 类：

### 示例

```cpp
#include <iostream>
#include <format>

struct Point {
    int x, y;
};

// 自定义格式化
template <>
struct std::formatter<Point> : std::formatter<std::string> {
    auto format(const Point& p, std::format_context& ctx) {
        return std::formatter<std::string>::format("({}, {})", ctx.out(), p.x, p.y);
    }
};

int main() {
    Point p{3, 4};
    std::cout << std::format("Point: {}", p) << std::endl; // 输出: Point: (3, 4)
    return 0;
}
```

在这里，我们为 `Point` 结构体自定义了格式化方法，使其能够以 `(x, y)` 的形式输出。

## 与其他格式化库比较

### 类型安全

`std::format` 提供类型安全，避免了 `printf` 的格式字符串与参数类型不匹配的问题。使用 `std::format` 时，编译器会在编译时检查格式与参数的类型，确保安全性。

### 灵活性

`std::format` 支持更多的格式化选项，使用更加灵活。例如，它可以轻松处理复杂数据结构和自定义类型，使得代码更加整洁。

## 实际应用示例

### 日志记录

在开发中，日志记录是常见的需求。使用 `std::format`，我们可以轻松实现格式化的日志输出：

```cpp
#include <iostream>
#include <format>
#include <chrono>

void log(const std::string& message) {
    auto now = std::chrono::system_clock::now();
    auto time = std::chrono::system_clock::to_time_t(now);
    std::cout << std::format("[{}] {}", std::put_time(std::localtime(&time), "%F %T"), message) << std::endl;
}

int main() {
    log("Application started.");
    log("Processing data...");
    return 0;
}
```

在这个例子中，我们定义了一个简单的 `log` 函数，使用 `std::format` 来输出带有时间戳的日志信息。

## 总结

C++20 的格式化输出功能让我们的代码变得更加简洁、易读。通过使用 `<format>` 库，我们能够轻松地将变量格式化成我们想要的样子，无论是控制小数位数、对齐方式，还是其他样式。这不仅在程序开发中方便，也能让最终用户得到更加友好的输出结果。



# “R”

在C++中，`cout << R"()";` 这段代码看起来是想使用原始字符串字面量（Raw String Literal），但是没有正确地使用。原始字符串字面量的正确用法是 `R"(字符串)"`，其中字符串可以包含换行和特殊字符，不需要转义。

例如，如果你想输出一个包含换行的字符串，你可以这样写：



```cpp
#include <iostream>
using namespace std;

int main() {
    cout << R"(Hello,
World!)" << endl;
    return 0;
}
```

这段代码会输出：

```text
Hello,
World!
```

注意，原始字符串字面量中的字符串必须用双引号括起来，而且字符串的开始和结束处的双引号之间不能有任何字符（包括空格）。如果你只是想输出一个空的字符串，可以这样写：

```cpp
cout << R"()" << endl;
```

这将输出一个空行。
