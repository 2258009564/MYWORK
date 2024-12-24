# 类的创建与构造

## 构造

在 C++ 中，**构造函数**和**析构函数**是类的特殊成员函数，用于在对象创建和销毁时自动进行初始化和清理操作。它们在对象的生命周期内扮演着重要的角色。

### 1. 构造函数 (Constructor)

构造函数是一个特殊的成员函数，用于初始化类的对象。它在对象创建时自动被调用。构造函数的名字与类名相同，并且没有返回类型。

#### 特性：

- 构造函数没有返回类型。
- 可以有多个构造函数（构造函数重载），根据不同的参数来初始化对象。
- 构造函数可以是默认的，也可以是带参数的。

#### 1.1 默认构造函数

如果没有提供任何参数，它将自动被调用，并初始化对象的成员变量。

```cpp
class Person {
public:
    std::string name;
    int age;

    // 默认构造函数
    Person() {
        name = "Unknown";
        age = 0;
    }
};
```

#### 1.2 带参数的构造函数

通过传递参数来初始化对象。可以使用初始化列表来更高效地初始化类的成员。

```cpp
class Person {
public:
    std::string name;
    int age;

    // 带参数的构造函数
    Person(const std::string &n, int a) : name(n), age(a) {}
};
```

#### 1.3 构造函数重载

可以定义多个构造函数，允许使用不同数量或类型的参数来创建对象。

```cpp
class Person {
public:
    std::string name;
    int age;
	// 什么都不传递
    Person() {
        name = "Unknown";
        age = 0;
    }
	// 传递一个string 作为name
    Person(const std::string &n) {
        name = n;
        age = 0;
    }
	// 传递string作为name， 传递int作为age
    Person(const std::string &n, int a) {
        name = n;
        age = a;
    }
};
```

#### 1.4 委托构造函数

构造函数可以委托给其他构造函数来减少重复代码。

使用委托构造函数和直接写两个不带参数的构造函数以及带两个参数的构造函数的效果是一样的，它们都会实现类似的功能：初始化对象的成员变量。不过，使用委托构造函数可以使代码更简洁和避免重复。

我们可以通过一个对比来理解它们的区别和效果：

##### 1. 直接写两个构造函数（不使用委托构造函数）

```cpp
class Person {
public:
    std::string name;
    int age;

    // 默认构造函数
    Person() {
        name = "Unknown";
        age = 0;
    }

    // 带参数的构造函数
    Person(const std::string &n, int a) {
        name = n;
        age = a;
    }
};
```

- `Person()` 是默认构造函数，它直接将 `name` 设置为 `"Unknown"`，`age` 设置为 `0`。
- `Person(const std::string &n, int a)` 是带参数的构造函数，它接受一个名字和一个年龄，并用它们初始化类的成员变量。

##### 2. 使用委托构造函数（避免重复代码）

```cpp
class Person {
public:
    std::string name;
    int age;

    // 默认构造函数，通过委托构造函数
    Person() : Person("Unknown", 0) {}  // 委托给带参数的构造函数

    // 带参数的构造函数
    Person(const std::string &n, int a) : name(n), age(a) {}
};
```

- `Person()` 这个默认构造函数委托给了带参数的构造函数 `Person("Unknown", 0)`，从而避免了重复的成员初始化代码。
- `Person(const std::string &n, int a)` 是带参数的构造函数，直接初始化 `name` 和 `age`。

##### 对比效果：

- **功能相同**：无论你使用直接写两个构造函数还是使用委托构造函数，效果都是一样的：你可以创建一个没有参数的 `Person` 对象（`name = "Unknown"`, `age = 0`），或者传递参数来初始化 `name` 和 `age`。
- **简洁性**：使用委托构造函数可以让代码更简洁和更易于维护。如果以后需要修改初始化逻辑，你只需要修改带参数的构造函数，而不需要修改每个构造函数。
- **减少冗余**：直接写两个构造函数会有一些冗余的代码，尤其是当你有多个构造函数时，这些构造函数会有很多相似的代码。委托构造函数可以将相似的代码集中到一个地方，避免重复。

##### 总结：

- **效果**：从功能上来看，两种方法的效果是相同的。
- **优雅性**：使用委托构造函数会让代码更加简洁、优雅，并减少冗余。
- **可维护性**：委托构造函数更易于维护，尤其是当类的构造函数逻辑复杂时。如果多个构造函数需要初始化成员变量相同的部分，委托构造函数可以避免多次编写相同的初始化代码。

因此，虽然两种方法都可以实现相同的功能，但使用委托构造函数通常是更推荐的做法，特别是在构造函数逻辑重复时。

### 2. 析构函数 (Destructor)

析构函数是一个特殊的成员函数，它在对象销毁时被自动调用，用于释放对象占用的资源（例如内存、文件句柄等）。析构函数的名字与类名相同，并且前面加一个波浪线（`~`）。

#### 特性：

- 析构函数没有返回类型和参数。
- 析构函数是自动调用的，一般不需要显式调用。
- 如果类有虚函数，则析构函数通常也应该是虚函数，确保派生类的析构函数会被正确调用。

#### 示例：

```cpp
class Person {
public:
    std::string name;
    int age;

    // 构造函数
    Person(const std::string &n, int a) : name(n), age(a) {}

    // 析构函数
    ~Person() {
        std::cout << "Person " << name << " is being destroyed." << std::endl;
    }
};
```

在上面的代码中，`Person` 类有一个构造函数和一个析构函数。每当 `Person` 对象销毁时，析构函数会被调用，并输出一条信息。

#### 为什么需要虚析构函数？

如果一个类有虚函数，那么它的析构函数也应该是虚析构函数，这样通过基类指针删除派生类对象时，会确保先调用派生类的析构函数，再调用基类的析构函数，从而避免资源泄漏。

```cpp
class Base {
public:
    virtual ~Base() {
        std::cout << "Base destructor called!" << std::endl;
    }
};

class Derived : public Base {
public:
    ~Derived() override {
        std::cout << "Derived destructor called!" << std::endl;
    }
};
```

### 3. 创建类成员的更多技巧

在 C++ 中，创建类成员时有一些技巧和优化方法，以提高效率、可维护性和代码可读性。以下是一些常见技巧：

#### 3.1 初始化列表

初始化列表是类构造函数的一个重要部分，可以直接在构造函数定义时初始化成员变量。使用初始化列表比在构造函数体内逐一赋值更高效。

```cpp
class Person {
public:
    std::string name;
    int age;

    // 使用初始化列表
    Person(const std::string &n, int a) : name(n), age(a) {}
};
```

#### 3.2 常量成员和引用成员

- **常量成员**：如果类中有常量成员，必须在初始化列表中进行初始化，因为常量成员不能在构造函数体内赋值。

```cpp
class Person {
public:
    const std::string name;
    int age;

    Person(const std::string &n, int a) : name(n), age(a) {}
};
```

- **引用成员**：引用成员必须在初始化列表中初始化，不能在构造函数体内赋值。

```cpp
class Person {
public:
    const std::string &name;
    int age;

    Person(const std::string &n, int a) : name(n), age(a) {}
};
```

#### 3.3 默认参数值

在类的构造函数中可以为某些参数提供默认值，这样可以让构造函数更加灵活。

```cpp
class Person {
public:
    std::string name;
    int age;

    // 提供默认参数值
    Person(const std::string &n = "Unknown", int a = 0) : name(n), age(a) {}
};
```

#### 3.4 拷贝构造函数 (Copy Constructor)

拷贝构造函数用于通过另一个同类型对象初始化一个新对象。它通常用于深拷贝操作，尤其是在对象中包含动态分配的内存时。

```cpp
class Person {
public:
    std::string name;
    int age;

    Person(const std::string &n, int a) : name(n), age(a) {}

    // 拷贝构造函数
    Person(const Person &other) : name(other.name), age(other.age) {
        std::cout << "Copy constructor called!" << std::endl;
    }
};
```

#### 3.5 移动构造函数 (Move Constructor)

在 C++11 及以后的版本中，可以使用移动构造函数来避免不必要的拷贝，特别是对于大型对象或资源管理类，移动构造函数可以提高性能。

```cpp
class Person {
public:
    std::string name;
    int age;

    Person(std::string n, int a) : name(std::move(n)), age(a) {}

    // 移动构造函数
    Person(Person &&other) noexcept : name(std::move(other.name)), age(other.age) {
        std::cout << "Move constructor called!" << std::endl;
    }
};
```

#### 3.6 静态成员变量

类的静态成员变量不属于某个特定对象，而是属于整个类的所有对象。静态成员变量通常用于存储类的共享数据。

```cpp
class Person {
public:
    static int count;  // 静态成员变量

    Person() {
        count++;  // 每次创建一个对象，计数加1
    }
};

// 必须在类外定义静态成员变量
int Person::count = 0;
```

#### 3.7 类的友元函数 (Friend Function)

有时你可能希望某个函数可以访问类的私有和保护成员，这时可以使用 **友元函数**。友元函数并不是类的成员，但它可以访问类的私有和保护成员。

```cpp
class Person {
private:
    std::string name;
    int age;

public:
    Person(const std::string &n, int a) : name(n), age(a) {}

    // 声明友元函数
    friend void display(const Person &p);
};

void display(const Person &p) {
    std::cout << "Name: " << p.name << ", Age: " << p.age << std::endl;
}
```

### 总结

- **构造函数**和**析构函数**是对象生命周期的关键，负责对象的初始化和资源的清理。
- 使用**初始化列表**来高效地初始化类成员，尤其是对于常量和引用成员。
- 通过构造函数重载、委托构造函数等技巧，可以使类的构造更加灵活。
- 使用**拷贝构造函数**和**移动构造函数**可以在需要时实现对象的深拷贝或优化性能。
- 静态成员和友元函数是类设计中常用的高级技巧，可以帮助你在需要时处理类的特殊需求。



# 类的继承

### 继承（Inheritance）

**继承** 是面向对象编程中的一个重要特性，它允许我们创建一个新类（派生类），并让它继承一个已有类（基类）的属性和方法。继承的主要目的是代码复用和扩展现有的功能。

#### 基本概念：

- **基类（父类）**：是被继承的类，它提供了一些基本的属性和方法。
- **派生类（子类）**：是从基类派生出来的类，它可以继承基类的属性和方法，并且可以根据需要进行扩展或重载。

#### 语法：

```cpp
class BaseClass {
public:
    int x;
    void show() {
        std::cout << "BaseClass show() function\n";
    }
};

class DerivedClass : public BaseClass {
public:
    int y;
    void display() {
        std::cout << "DerivedClass display() function\n";
    }
};
```

在这个例子中，`DerivedClass` 继承了 `BaseClass`，所以 `DerivedClass` 可以访问 `BaseClass` 中的属性和方法。

#### 使用方式：

```cpp
int main() {
    DerivedClass d;
    d.x = 10;  // 继承了 BaseClass 的成员变量 x
    d.y = 20;  // DerivedClass 自己的成员变量 y
    d.show();  // 调用 BaseClass 的成员函数 show()
    d.display();  // 调用 DerivedClass 的成员函数 display()

    return 0;
}
```

#### 继承的类型：

- **公有继承（`public`）**：派生类继承基类的公有成员和保护成员，基类的私有成员无法访问。
- **私有继承（`private`）**：派生类继承基类的所有成员，但所有基类的公有和保护成员都变成派生类的私有成员。
- **保护继承（`protected`）**：派生类继承基类的公有和保护成员，但它们在派生类中变成保护成员。

# 类的多态

### 多态（Polymorphism）

**多态** 是面向对象编程的一个重要概念，它允许对象以多种形式出现。简单来说，多态允许不同类型的对象通过相同的接口进行操作，具体执行哪种方法取决于对象的实际类型。

#### 多态的类型：

1. **静态多态（编译时多态）**：通常通过函数重载（Function Overloading）和运算符重载（Operator Overloading）实现，编译器在编译阶段决定调用哪个函数。
2. **动态多态（运行时多态）**：通过虚函数（Virtual Functions）和继承关系来实现，运行时根据对象的实际类型来决定调用哪个函数。

#### 语法：

在 C++ 中，**虚函数**（`virtual`）是实现动态多态的关键。通过在基类中声明虚函数，派生类可以重写这个函数，并且通过基类指针或引用来调用派生类的重写版本。

```cpp
class Base {
public:
    virtual void show() {  // 虚函数
        std::cout << "Base show() function\n";
    }
};

class Derived : public Base {
public:
    void show() override {  // 重写基类的 show() 函数
        std::cout << "Derived show() function\n";
    }
};
```

#### 使用虚函数实现多态：

```cpp
int main() {
    Base* b = new Derived();  // 基类指针指向派生类对象
    b->show();  // 调用的是 Derived 类的 show()，而不是 Base 类的

    delete b;  // 释放内存
    return 0;
}
```

- **`virtual` 关键字**：在基类中声明虚函数，表示此函数在派生类中可能会被重写，并且可以通过基类指针或引用来调用派生类中的重写版本。
- **`override` 关键字**：在派生类中重写基类的虚函数时，建议使用 `override`，它可以确保你确实是重写了基类的虚函数，并避免一些错误（例如函数签名不匹配）。

#### 为什么使用虚函数？

- **实现运行时多态**：通过基类指针或引用调用派生类的方法，而具体调用哪个方法由对象的实际类型决定，而不是由指针或引用的类型决定。
- **提高代码的灵活性**：可以用统一的接口操作不同的派生类对象。

# 继承和多态的结合

通过继承和多态，我们可以设计更加灵活的程序。例如，如果我们有一个基类 `Shape`，派生类 `Circle` 和 `Rectangle` 可以各自重写 `draw()` 方法，而我们可以用一个统一的接口来处理所有形状的绘制。

#### 例子：

```cpp
#include <iostream>
#include <vector>

class Shape {
public:
    virtual void draw() {  // 基类的虚函数
        std::cout << "Drawing a shape\n";
    }
    virtual ~Shape() {}  // 虚析构函数，确保正确销毁派生类对象
};

class Circle : public Shape {
public:
    void draw() override {  // 重写基类的 draw()
        std::cout << "Drawing a circle\n";
    }
};

class Rectangle : public Shape {
public:
    void draw() override {  // 重写基类的 draw()
        std::cout << "Drawing a rectangle\n";
    }
};

int main() {
    std::vector<Shape*> shapes;
    shapes.push_back(new Circle());
    shapes.push_back(new Rectangle());

    for (Shape* shape : shapes) {
        shape->draw();  // 动态多态，根据实际对象类型调用相应的 draw() 方法
    }

    // 清理内存
    for (Shape* shape : shapes) {
        delete shape;
    }

    return 0;
}
```

#### 解释：

- `Shape` 是基类，包含一个虚函数 `draw()`。
- `Circle` 和 `Rectangle` 是派生类，分别重写了 `draw()` 函数。
- 在 `main()` 中，我们使用一个 `Shape` 类型的指针来存储 `Circle` 和 `Rectangle` 对象，并通过 `draw()` 来绘制它们。
- 由于 `draw()` 是虚函数，所以 `shape->draw()` 调用的是 `Circle` 或 `Rectangle` 类的重写版本，而不是 `Shape` 类的版本。这就是多态的体现。

### 总结：

1. **继承**：允许我们通过基类创建派生类，派生类可以继承和扩展基类的功能。
2. **派生类**：继承自基类的类，可以访问基类的公共和保护成员，并可以添加新的成员或重写基类的方法。
3. **多态**：使得同一个接口可以根据对象的实际类型表现出不同的行为。通过虚函数和继承关系，我们可以实现动态多态。

这些特性组合在一起，使得面向对象编程能够非常灵活地构建和管理代码，增强了代码的可扩展性和可维护性。