## 1. Overview: Dynamic Programming and Memoization

Dynamic Programming (DP) is a method used to solve problems with overlapping subproblems and optimal substructure. The idea is to avoid recomputation by saving answers to subproblems. There are two common approaches:

- **Memoization (Top-Down):**  
  Write a recursive solution and store (cache) results of subproblems to avoid repeated work.
  
- **DP (Bottom-Up):**  
  Build the solution iteratively by solving all smaller subproblems first and then combining their solutions.

These techniques are particularly useful when the naïve recursive solution has exponential time complexity due to repeated calculations.

---

## 2. Fibonacci Series Example

### 2.1 Naïve Recursive Approach

The Fibonacci sequence is defined as:  
\[
\text{Fib}(n) = \text{Fib}(n-1) + \text{Fib}(n-2) \quad \text{with } \text{Fib}(0) = \text{Fib}(1) = 1.
\]

A naïve recursive implementation recalculates many subproblems multiple times, leading to exponential time complexity (approximately \( O(2^n) \)).

```cpp
int fib(int n) {
    if (n <= 1)
        return 1;
    return fib(n - 2) + fib(n - 1);
}
```

### 2.2 Memoized (Top-Down) Approach

By saving already computed Fibonacci numbers, we reduce the time complexity to \( O(n) \).

```cpp
const int MAX = 100;
int savedAnswers[MAX];  // Initialized to -1 elsewhere to denote 'not computed'

int fibSave(int n) {
    if (n <= 1)
        return 1;
    if (savedAnswers[n] != -1)
        return savedAnswers[n];
    return savedAnswers[n] = fibSave(n - 2) + fibSave(n - 1);
}
```

### 2.3 Bottom-Up DP Approach

An iterative DP solution builds the Fibonacci sequence from the base cases upward.

```cpp
int dp_fib(int n) {
    int fib[MAX];
    fib[0] = fib[1] = 1;
    for (int i = 2; i <= n; ++i)
        fib[i] = fib[i - 1] + fib[i - 2];
    return fib[n];
}
```

---

## 3. Grid Path Sum Problem

### **Problem Statement**

Given a grid of positive numbers, start at the top-left corner (0, 0) and move only to the right or down. The goal is to find the path that maximizes the sum of numbers along the way to the bottom-right corner.

### **Recursive Approach**

Define a function `F(i, j)` that returns the maximum path sum starting from cell \((i, j)\). At each cell, you have two choices: move right or move down.

```cpp
int maxPathSum(int r, int c) {
    if (!valid(r, c))
        return 0;
    if (r == n - 1 && c == n - 1)
        return grid[r][c];  // Base case: bottom-right corner.
    
    int path1 = maxPathSum(r, c + 1);  // Move right.
    int path2 = maxPathSum(r + 1, c);  // Move down.
    
    return grid[r][c] + max(path1, path2);
}
```

### **Memoized Version**

To avoid redundant calculations, store the result for each cell in a memoization table.

```cpp
int mem[MAX][MAX];  // Should be initialized with -1.

int maxPathSum_save(int r, int c) {
    if (!valid(r, c))
        return 0;
    if (r == n - 1 && c == n - 1)
        return grid[r][c];  // Base case.
    if (mem[r][c] != -1)
        return mem[r][c];
    
    int path1 = maxPathSum_save(r, c + 1);  // Right.
    int path2 = maxPathSum_save(r + 1, c);  // Down.
    
    return mem[r][c] = grid[r][c] + max(path1, path2);
}
```

---

## 4. Divisibility of an Arithmetic Expression (DP on Expressions)

### **Problem Statement**

Given a sequence of integers, insert either a '+' or '-' between them so that the resulting expression is divisible by a given integer \( k \).  
For example, the sequence {17, 5, -21, 15} is divisible by 7 because \( 17 + 5 + (-21) - 15 = -14 \), which is divisible by 7.

### **Naïve Recursive Approach**

The recursive function explores both choices (adding or subtracting each number) and checks if any complete expression is divisible by \( k \).

```cpp
int tryAll1(int i, int sum) {
    if (i == n)
        return sum % k == 0;
    
    if (tryAll1(i + 1, sum + v[i]) || tryAll1(i + 1, sum - v[i]))
        return 1;
    return 0;
}
```

### **Memoized DP Approach**

By using DP (memoization), we store intermediate results to avoid re-calculating the same states. A helper function `fix` is used to correctly handle modulo operations (ensuring non-negative remainders).

```cpp
int fix(int a) {
    return (a % k + k) % k;
}

int tryAll2(int i, int mod) {
    int &ret = mem[i][mod];  // Using a 2D DP table: mem[i][mod]
    if (ret != -1)
        return ret;
    if (i == n)
        return ret = (mod == 0);
    
    if (tryAll2(i + 1, fix(mod + v[i])) || tryAll2(i + 1, fix(mod - v[i])))
        return ret = 1;
    return ret = 0;
}
```

---

## 5. Summary and General Principles

- **Memoization vs. DP:**  
  When recursive subproblems overlap, store their answers (memoization) or build solutions bottom-up (DP) to avoid exponential time complexity.

- **Fibonacci Example:**  
  A classic example where the naïve solution is exponential, but with memoization or iterative DP, the complexity reduces to \( O(n) \).

- **Grid Path Sum:**  
  Problems such as finding the maximum path sum in a grid are solved by breaking the problem into subproblems and using DP to avoid re-computation.

- **Expression Divisibility:**  
  In problems where choices (such as inserting '+' or '-' between numbers) lead to different outcomes, recursive exploration combined with DP (memoization) efficiently explores the exponential search space.

- **General DP Tips:**  
  - Identify overlapping subproblems.
  - Ensure the state space is small enough to be memorized.
  - Choose memoization (top-down) when natural recursion exists; use bottom-up DP when you can build the solution iteratively.