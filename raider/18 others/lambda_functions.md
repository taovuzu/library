Lambda functions in C++ are a way to define **anonymous (unnamed)** functions directly in your code. They were introduced in **C++11** and are widely used in modern C++ programming for creating small, concise function objects, especially when passing them as arguments to algorithms (like `std::sort`, `std::for_each`, etc.).

---

## 📌 **What is a Lambda Function?**

A **lambda function** in C++ is essentially a syntactic shortcut to create a **function object** (i.e., an object that can be called like a function). It’s typically used when:

* You need a short function.
* You want to pass a function as an argument to another function.
* You want to define functionality inline, without polluting your namespace with function names.

---

## 🧱 **Syntax of Lambda Function**

```cpp
[capture_list](parameter_list) -> return_type {
    // function body
};
```

Let’s break this down:

### 1. **Capture List `[ ]`**

* Specifies which variables from the **surrounding scope** are available in the lambda.
* This is how the lambda "captures" external variables.

### 2. **Parameter List `( )`**

* Same as normal functions: arguments passed to the lambda.

### 3. **Return Type `->`**

* Optional. If omitted, the compiler will deduce the return type.

### 4. **Function Body `{}`**

* Contains the logic to execute when the lambda is called.

---

## ✅ **Basic Example**

```cpp
#include <iostream>

int main() {
    auto greet = []() {
        std::cout << "Hello, Lambda!" << std::endl;
    };

    greet(); // Calls the lambda
    return 0;
}
```

---

## 📦 **Using Parameters and Return Types**

```cpp
#include <iostream>

int main() {
    auto add = [](int a, int b) -> int {
        return a + b;
    };

    std::cout << "Sum: " << add(5, 3) << std::endl; // Output: Sum: 8
    return 0;
}
```

> Note: In this case, you could omit `-> int` because the compiler can deduce it.

---

## 📥 **Capture List in Detail**

### Example:

```cpp
#include <iostream>

int main() {
    int x = 10, y = 5;

    auto print = [x, y]() {
        std::cout << "x = " << x << ", y = " << y << std::endl;
    };

    print();
    return 0;
}
```

### 📋 Types of Capture:

| Syntax    | Meaning                                             |
| --------- | --------------------------------------------------- |
| `[ ]`     | Capture nothing.                                    |
| `[=]`     | Capture all automatic variables by **value**.       |
| `[&]`     | Capture all automatic variables by **reference**.   |
| `[x]`     | Capture variable `x` by **value**.                  |
| `[&x]`    | Capture variable `x` by **reference**.              |
| `[=, &x]` | Capture all by **value**, but `x` by **reference**. |
| `[&, x]`  | Capture all by **reference**, but `x` by **value**. |

---

### ⚠️ Value vs Reference Capture:

```cpp
#include <iostream>

int main() {
    int a = 5;

    auto valCapture = [a]() { std::cout << "By value: " << a << std::endl; };
    auto refCapture = [&a]() { std::cout << "By reference: " << a << std::endl; };

    a = 10;

    valCapture();   // Output: By value: 5
    refCapture();   // Output: By reference: 10
    return 0;
}
```

---

## 💡 **Lambda with STL Algorithms**

```cpp
#include <iostream>
#include <vector>
#include <algorithm>

int main() {
    std::vector<int> vec = {1, 5, 3, 2, 4};

    std::sort(vec.begin(), vec.end(), [](int a, int b) {
        return a > b; // Sort in descending order
    });

    for (int num : vec) {
        std::cout << num << " ";
    }
    // Output: 5 4 3 2 1

    return 0;
}
```

---

## ⚙️ **Mutable Lambda**

By default, lambdas that capture by value **cannot modify the captured variables**. To allow modification, use the `mutable` keyword.

```cpp
#include <iostream>

int main() {
    int x = 10;

    auto modify = [x]() mutable {
        x += 5;
        std::cout << "Modified x: " << x << std::endl;
    };

    modify(); // Output: Modified x: 15
    std::cout << "Original x: " << x << std::endl; // Output: Original x: 10

    return 0;
}
```

> `mutable` allows you to modify the **copy** of the variable captured by value.

---

## 🔄 **Generic Lambdas (C++14 and above)**

```cpp
auto generic = [](auto a, auto b) {
    return a + b;
};

std::cout << generic(3, 4) << "\n";      // int
std::cout << generic(2.5, 3.7) << "\n";  // double
std::cout << generic(std::string("Hi "), std::string("there")) << "\n"; // string
```

---

## 🧠 **Lambda as Function Arguments**

```cpp
void apply(int x, int y, const std::function<void(int, int)>& func) {
    func(x, y);
}

int main() {
    apply(5, 3, [](int a, int b) {
        std::cout << "Sum = " << a + b << std::endl;
    });

    return 0;
}
```

---

## 🧾 Summary

| Feature                         | Supported Since | Notes                                      |
| ------------------------------- | --------------- | ------------------------------------------ |
| Basic Lambdas                   | C++11           | Capturing, passing                         |
| Generic Lambdas                 | C++14           | Use `auto` in parameters                   |
| Init-capture                    | C++14 / C++20   | Capture and initialize inside capture list |
| constexpr lambdas               | C++17           | Used in constant expressions               |
| Lambdas in unevaluated contexts | C++20           | Use in `decltype`, `sizeof`, etc.          |

---

## 🚀 Real-world Uses

* Callback functions (e.g., GUI programming, event handling)
* Custom sort or filter logic
* Encapsulating logic without naming it
* Replacing small function objects or functors

---

