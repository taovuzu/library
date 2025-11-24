## 1. Why Measure Algorithm Performance?

- **Purpose:**  
  - To evaluate and compare algorithms independent of machine specifics.
  - To predict scalability as input size increases.
- **Challenges with Empirical Metrics:**  
  - Measured run times depend on the machine and environment.
  - Counting the number of operations (steps) provides a machine-independent metric.

---

## 2. Theoretical Background

- **Asymptotic Complexity:**  
  - Focuses on the running time or memory usage of an algorithm as a function of the input size \( n \) for large \( n \).
- **Cases:**  
  - **Worst-case:** The maximum number of steps required.
  - **Average-case:** The expected number of steps over all inputs.
  - **Best-case:** The minimum steps needed.
- **Note:**  
  - Worst-case complexity is most commonly used (e.g., in quicksort, worst-case is \(O(n^2)\) even though average-case is \(O(n \log n)\)).

---

## 3. Big O Notation

- **Definition:**  
  - \( G(n) \) is \( O(F(n)) \) if there exist constants \( c \) and \( n_0 \) such that for all \( n \geq n_0 \),  
    \[
    G(n) \leq c \times F(n)
    \]
  - It provides an asymptotic upper bound on the growth rate of an algorithm.
- **Key Idea:**  
  - Big O notation ignores constant factors and lower-order terms. For example, an algorithm doing \( n + 2n + 5n^2 \) operations is \( O(n^2) \) since for sufficiently large \( n \), the \( n^2 \) term dominates.
- **Observation:**  
  - An algorithm that is \( O(n^2) \) is also \( O(n^3) \) or \( O(n^4 \log n) \) but these bounds are less tight.

---

## 4. Examples of Complexity Orders

### 4.1 Constant Order – \(O(1)\)

The running time does not depend on \( n \).  
**Example:**

```cpp
void ConstantOrder1() {
    int start = 6;
    int end = 100;
    int mid = (end - start) / 2;
    if(mid % 2 == 0)
        --mid;
}

void ConstantOrder2() {
    int start = 7;
    int end = 0;
    // A fixed number of iterations regardless of input variables
    for (int i = 0; i < 1000; ++i)
        end += end * 2 + start;
}
```

---

### 4.2 Logarithmic Order – \(O(\log n)\)

The problem size is halved (or reduced by a constant factor) in each step.  
**Example:**

```cpp
void logn1() {
    int n = 1048576;  // 2^20
    int steps = 0;
    while(n > 1) {
        n /= 2;  // Reducing n by a factor of 2 each time
        steps++;
    }
}

void logn2(int val) {
    vector<int> v(1000000);
    // Fill and sort array (for demonstration purposes)
    for (int i = 0; i < 1000000; ++i)
        v[i] = rand();
    sort(v.begin(), v.end());

    int start = 0, end = 1000000 - 1;
    bool found = false;
    // Binary Search: Each iteration reduces the range by half.
    while(start <= end) {
        int mid = (start + end) / 2;
        if(v[mid] == val) {
            found = true;
            break;
        }
        if(val < v[mid])
            end = mid - 1;
        else
            start = mid + 1;
    }
}
```

---

### 4.3 Fractional Power – \(O(\sqrt{n})\)

Used in algorithms that divide data into blocks (e.g., block decomposition, some searching techniques).  
**Example Outline:**

```cpp
void sqrtn() {
    int n = 1000000;
    vector<int> v(n);
    for (int i = 0; i < n; ++i)
        v[i] = rand();
    sort(v.begin(), v.end());

    int m = sqrt(n);  // Number of blocks ~ sqrt(n)
    vector<int> blockMin(m), blockMax(m);
    // Further operations would process these sqrt(n) blocks
}
```

---

### 4.4 Linear Order – \(O(n)\)

The running time increases linearly with \( n \).  
**Examples:**

```cpp
void linear1() {
    int n = 10000;
    for(int i = 0; i < n; i++) {
        ConstantOrder1();
        ConstantOrder2();
    }
}

void linear2() {
    int n = 10000;
    for(int i = 0; i < n; i++)
        ConstantOrder1();
    for(int i = 0; i < 5 * n; i++)
        ConstantOrder1();
    // Overall: O(n) + O(5n) = O(n)
}
```

---

### 4.5 Log-Linear Order – \(O(n \log n)\)

Common in efficient sorting algorithms.  
**Example:**

```cpp
void loglinear1() {
    int n = 1000;
    for (int i = 0; i < n; ++i) {
        logn2(i);  // Each iteration takes O(log n)
    }
}
```

---

### 4.6 Polynomial Order – \(O(n^c)\) for \(c > 1\)

**Quadratic \(O(n^2)\):**

```cpp
void nPow2_1() {
    int n = 1000;
    int cnt = 0;
    for (int i = 0; i < n; ++i)
        for (int j = 0; j < n; ++j)
            cnt++;
}

void nPow2_2() {
    int n = 1000;
    int cnt = 0;
    for (int i = 0; i < n; ++i)
        for (int j = i; j < n; ++j)
            cnt++;
    // Additional loops can be combined with constants, still O(n^2)
}
```

**Cubic \(O(n^3)\):**

```cpp
void nPow3_1() {
    int n = 1000;
    int cnt = 0;
    for (int i = 0; i < n; ++i)
        for (int j = 0; j < n; ++j)
            for (int k = 0; k < n; ++k)
                cnt++;
}

void nPow3_2() {
    int n = 1000;
    int cnt = 0;
    for (int i = 0; i < n; ++i)
        for (int j = i; j < n; ++j)
            for (int k = j; k < n; ++k)
                cnt++;
    cout << cnt;
}
```

---

### 4.7 Factorial Order – \(O(n!)\)

Used when iterating through all permutations of a set.  
**Example:**

```cpp
#include <algorithm>
#include <string>
#include <iostream>
using namespace std;

void factorialn1() {
    string str = "abcd";  // 4! permutations
    do {
        cout << str << "\n";
    } while(next_permutation(str.begin(), str.end()));
}
```

---

### 4.8 Tight Order Example

Determining the running time by counting occurrences in a sorted array (expected to be \(O(n)\)):

```cpp
void what_is_my_tight_Order() {
    const int n = 15;
    int arr[n] = {4, 4, 4, 5, 5, 5, 5, 5, 9, 11, 11, 13, 13, 16, 18};
    for (int i = 0; i < n; ++i) {
        int cnt = 0;
        for (int j = i; j < n && arr[i] == arr[j]; ++j)
            cnt++;
        cout << arr[i] << " appeared " << cnt << " times\n";
        i = i + cnt - 1;
    }
    // Overall complexity: O(n)
}
```

---

## 5. Memory Complexity

Memory usage can also be expressed in orders of \( n \). Here are some examples:

```cpp
void memory() {
    int n = 100;
    vector<int> v1(n);                      // O(n) memory
    vector< vector<bool> > v2(n, vector<bool>(20)); // O(n)
    int a = 1, b = 2, c = a + b;              // O(1)
    const int MAX = 15;
    int arr1[MAX][MAX][MAX];                  // O(1) with constant dimensions, but could be considered O(n^3) if dimensions were variable
    char arr2[n][(int)log(n)];                // O(n log n)
    string str = "abcdef";                    // O(length)
    vector<string> vstr(n);                   // O(n) strings
}
```

---

## 6. Practical Limits Based on Complexity

Below is an approximate table for maximum input size \( N \) that can be handled within typical contest time limits:

| Complexity     | Maximum \( N \)          |
|----------------|--------------------------|
| \( O(\log n) \)      | \( 10^{18} \)             |
| \( O(n) \)           | \( 100\,000\,000 \)       |
| \( O(n \log n) \)    | \( 40\,000\,000 \)        |
| \( O(n^2) \)         | \( 10\,000 \)             |
| \( O(n^3) \)         | \( 500 \)                |
| \( O(n^4) \)         | \( 90 \)                 |
| \( O(2^n) \)         | \( 20 \)                 |
| \( O(n!) \)          | \( 11 \)                 |

---

## 7. Conclusion

- **Understanding performance:**  
  - Measuring algorithm performance using Big O notation helps compare and choose the right algorithm.
- **Asymptotic Analysis:**  
  - Focuses on growth rates for large \( n \) while ignoring machine-dependent constants.
- **Variety of Orders:**  
  - From constant and logarithmic to polynomial, exponential, and factorial, each order gives insight into scalability.
- **Memory vs. Time:**  
  - Both time and memory complexities are critical when designing algorithms for contests.