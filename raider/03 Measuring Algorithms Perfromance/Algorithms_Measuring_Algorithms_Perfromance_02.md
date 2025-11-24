## 1. Evaluating the Order of Recursive Functions

When analyzing recursive functions, we consider two main factors:
- **Number of operations per recursive level.**
- **Maximum recursion depth (height).**

The overall work is often computed as the sum of the work done at each level. For example, if each level performs twice as many operations as the previous one and there are about \( \log_2(k) \) levels, then the total work can be bounded by a geometric series.

---

## 2. Examples of Recursion Orders

### 2.1 Linear Recursion

A simple recursive function that makes one recursive call per level has linear order.

**Example:** Printing a message repeatedly.

```cpp
// O(n) recursion: one recursive call per level.
void SayIamTopCoder(int cnt) {
    if(cnt < 1)
        return;
    cout << "I am TopCoder.\n";
    SayIamTopCoder(cnt - 1);
}
```

### 2.2 Collatz-like Recursion

A recursion that chooses between two cases (depending on parity) is still linear with respect to the length of the sequence.

```cpp
// F3n_1 computes the number of steps for the 3n+1 problem.
int F3n_1(int n) {  // Complexity: proportional to the length of the sequence.
    if(n == 1)
        return 1;
    if(n % 2 == 0)
        return 1 + F3n_1(n / 2);
    return 1 + F3n_1(3 * n + 1);
}
```

### 2.3 Divide and Conquer Recursion

When a problem is split into multiple smaller subproblems, the total work is the sum over the levels of recursion.

For example, in mergesort:
- The recurrence is:  
  \[
  T(n) = 2T\left(\frac{n}{2}\right) + O(n)
  \]
- This gives a total of \( O(n \log n) \).

```cpp
// Mergesort: Divides the array and then merges sorted halves.
void mergesort(vector<int> &arr, int low, int high) {
    if(low < high) {
        int mid = (low + high) / 2;
        mergesort(arr, low, mid);
        mergesort(arr, mid + 1, high);
        // Merge the sorted halves in O(n) time.
    }
}
```

### 2.4 Exponential Recursion

Recursions that branch out in multiple directions at each level can have exponential complexity.

**Example 1: Generating Binary Sequences**

```cpp
// Generate all binary strings of a given length.
// Branching factor is 2, and depth is len, so overall complexity is O(2^len).
void generateBinary(int len, string cur = "") {
    if(len == 0) {
        cout << cur << "\n";
        return;
    }
    generateBinary(len - 1, cur + "0");
    generateBinary(len - 1, cur + "1");
}
```

**Example 2: Generating Ternary Sequences**

```cpp
// Generate all ternary strings of a given length.
// Here the branching factor is 3, so the complexity is O(3^len).
void generateTernary(int len, string cur = "") {
    if(len == 0) {
        cout << cur << "\n";
        return;
    }
    generateTernary(len - 1, cur + "0");
    generateTernary(len - 1, cur + "1");
    generateTernary(len - 1, cur + "2");
}
```

### 2.5 Exponential Recursion in Fibonacci

A classic example where each call generates two further calls (with overlapping subproblems) exhibits exponential complexity.

```cpp
// Naïve recursive Fibonacci (exponential time).
int fib(int n) {
    if(n <= 1)
        return 1;
    return fib(n - 1) + fib(n - 2);
}
```

### 2.6 Permutations (Factorial Order)

Generating all permutations of \( n \) elements produces \( n! \) outcomes.

```cpp
// Permutations: recursive function to print all permutations of numbers [0, n-1].
// Time Complexity: O(n!)
void perm(int i, int n, int vis[], int cur[]) {
    if(i == n) {
        // Print the current permutation.
        return;
    }
    for (int j = 0; j < n; ++j) {
        if(!vis[j]) {
            vis[j] = 1;
            cur[i] = j;
            perm(i + 1, n, vis, cur);
            vis[j] = 0;
        }
    }
}
```

### 2.7 Other Recurrence Examples

#### 2.7.1 Custom Recurrence Combining Loops and Recursive Calls

Consider a function that does \( O(n^3) \) work in loops and makes several recursive calls on subproblems of size roughly \( n/2 \):

```cpp
int playRec(int n) {
    if(n <= 1) return 1;
    int cnt = 0;
    for(int i = 0; i < n; i += 2)
        for(int j = 2 * i; j < n - 1; ++j)
            for(int k = (i + j) / 2; k < n; k++)
                cnt++;
    int a = playRec(n / 2);
    int b = playRec(n / 2 - 1);
    int c = playRec(n / 2 - 2);
    return cnt + a + b + c;
}
```

A detailed derivation using geometric series shows that even with multiple recursive calls, the dominant work may end up as \( O(n^3) \) if the constant factors from recursive calls form a convergent geometric series.

---

## 3. Flood Fill and Graph Traversals

### 3.1 Flood Fill (DFS)

Flood fill is a typical recursive algorithm used to visit connected cells in a grid. The complexity is proportional to the number of cells reached.

```cpp
// Flood Fill: Count reachable cells from a given position in a maze.
const int MAX = 100;
char maze[MAX][MAX];
bool vis[MAX][MAX];

bool valid(int i, int j) { 
    return true; // For demonstration; usually check bounds.
}

int cnt = 0;
void cntReachableCells(int r, int c) {
    if(!valid(r, c) || maze[r][c] == 'X' || vis[r][c])
        return; // Out-of-bound or already visited or blocked.
    vis[r][c] = true;
    cnt++;
    // Explore the four neighbors.
    cntReachableCells(r, c - 1);
    cntReachableCells(r, c + 1);
    cntReachableCells(r - 1, c);
    cntReachableCells(r + 1, c);
}
```

### 3.2 Counting Connected Components

By repeatedly applying flood fill on unvisited cells, you can count the number of connected components in a grid. The overall complexity is \( O(R \times C) \).

```cpp
// Count connected components in a grid of R rows and C columns.
void cntComponents(int R, int C) {
    int comps = 0;
    for(int i = 0; i < R; ++i) {
        for(int j = 0; j < C; ++j) {
            cnt = 0;
            cntReachableCells(i, j);  // Runs in O(component size)
            if(cnt > 0)
                comps++;
        }
    }
}
```

---

## 4. Sieve Algorithm Order

### 4.1 Sieve of Eratosthenes

The Sieve of Eratosthenes is used to mark non-prime numbers. Its complexity is not strictly \( O(n \log n) \) but can be tightly bounded by \( O(n \ln \ln n) \) using analysis from the prime harmonic series.

```cpp
// Sieve of Eratosthenes: Mark non-prime numbers in the range [0, n].
void sieve(int n) {
    vector<bool> isPrime(n + 1, true);
    isPrime[0] = isPrime[1] = false;
    for (long long i = 2; i * i <= n; ++i) {
        if(isPrime[i]) {
            for (int j = i * 2; j <= n; j += i)
                isPrime[j] = false;
        }
    }
}
```

### 4.2 Approximation and Analysis

Using the Prime Number Theorem, one can estimate:
- The count of primes in a range \( n \) is approximately \( \frac{n}{\ln n} \).
- The sum over the reciprocals of primes approximates \( \ln \ln n \).

This leads to an overall complexity of the sieve as:
\[
O\left(n \cdot \ln \ln n\right)
\]
where \( \ln \ln n \) is a very slowly growing function.

---

## 5. Additional Topics and Exercises

- **Recursion Method:**  
  Evaluate the number of operations by summing the work per level (e.g., \( 1 + 2 + 4 + \dots \)) up to \( \log_2(k) \) levels.
  
- **Exercise 1:**  
  Prove that in the sieve, the inner loop can start at \( i \times i \) rather than \( i \times 2 \) without changing the asymptotic complexity.
  
- **Exercise 2:**  
  Show that starting at \( i \times i \) does not enhance the asymptotic order even though it reduces the constant factor.

---

## 6. Conclusion

This section provided:
- A step-by-step analysis of different recursion orders (linear, exponential, divide and conquer).
- Examples of exponential recursion in generating binary/ternary sequences and in naive Fibonacci computation.
- Discussion of recursion in permutation generation and divide and conquer strategies like mergesort.
- An overview of flood fill (graph traversal) and connected component counting.
- A detailed look at the Sieve of Eratosthenes and its asymptotic complexity derived from properties of primes.