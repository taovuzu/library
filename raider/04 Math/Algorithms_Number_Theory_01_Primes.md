## 1. Introduction & Prime Number Facts

This section introduces prime numbers and some useful facts:

- **Definition:** A prime number is an integer greater than 1 that has no divisors other than 1 and itself.  
- **Examples:** The first few primes are 2, 3, 5, 7, 11, etc.  
- **Interesting Facts:**
  - The list of primes up to 100:  
    ```cpp
    int primelst[25] = {2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37, 41, 43, 47, 53, 59, 61, 67, 71, 73, 79, 83, 89, 97};
    ```
  - Large primes exist such as 2147483647 (which is \(2^{31}-1\)) and 2305843009213693951 (\(2^{61}-1\)).
  - The prime counting function approximates the number of primes below \(n\) as roughly \( \frac{n}{\log(n)} \).

Other interesting properties include Wilson’s theorem:  
\[
(p-1)! \mod p = p-1 \quad \text{if and only if } p \text{ is prime.}
\]

---

## 2. Primality Testing Algorithms

Several versions of a function to test if a number is prime are presented. Each version improves on time complexity or efficiency.

### **isprime1: Naïve Approach (O(n))**

Checks every integer from 2 to \( n-1 \).

```cpp
bool isprime1(long long n) { // O(n)
    if(n == 2)
        return true;
    if(n < 2)
        return false;
    for (int i = 2; i < n; i++)
        if(n % i == 0)
            return false;
    return true;
}
```

### **isprime2: Skip Even Numbers (O(n))**

After checking for 2 and even numbers, only odd divisors are examined.

```cpp
bool isprime2(long long n) { // O(n) but with fewer iterations
    if(n == 2)
        return true;
    if(n < 2 || n % 2 == 0)
        return false;
    for (int i = 3; i < n; i += 2)
        if(n % i == 0)
            return false;
    return true;
}
```

### **isprime3: Checking up to √n (O(√n))**

It is enough to check divisors up to the square root of \(n\), since if \( n = a \times b \) and \( a \le b \) then \( a \le \sqrt{n} \).

```cpp
#include <cmath>

bool isprime3(long long n) { // O(√n)
    if(n == 2)
        return true;
    if(n < 2 || n % 2 == 0)
        return false;
    // Check odd divisors up to sqrt(n)
    for (long long i = 3; i <= sqrt(n); i += 2)
        if(n % i == 0)
            return false;
    return true;
}
```

### **isprime4: Optimized with Integer Comparison and Operation Count**

Uses the condition \( i \times i \le n \) to avoid repeated sqrt computations. It also increments a global counter to track the number of operations.

```cpp
typedef long long ll;
int total_operations = 0;

bool isprime4(ll n) { // O(√n)
    total_operations++; // Count the operation for the check
    if(n == 2)
        return true;

    total_operations++;
    if(n < 2 || n % 2 == 0)
        return false;

    for (ll i = 3; i * i <= n; i += 2) {
        total_operations++;
        if(n % i == 0)
            return false;
    }
    return true;
}
```

---

## 3. Counting Primes in a Range

### **Forward Thinking Approach  O(n * √n)**

Loop from 1 to \( n \) and check each number using the `isprime4` function.

```cpp
int countPrimesInRange(int n) { // O(n * √n)
    total_operations = 0;
    int cnt = 0;
    for (int i = 1; i <= n; ++i)
        if(isprime4(i))
            ++cnt;
    return cnt;
}
```

### **Backward Thinking Approach: Sieve of Eratosthenes O(n log log n)**

A more efficient method to count primes up to \( n \) is to use the Sieve of Eratosthenes. This “backward” method marks multiples of each prime starting from 2.

```cpp

int countPrimesInRange_sieve(int n) { // O(n log log n)

    // Create a boolean vector, initializing all numbers as prime (true)
    vector<bool> isPrime(n + 1, true);
    isPrime[0] = isPrime[1] = false; // 0 and 1 are not prime

    // Sieve: mark multiples of each prime as non-prime
    for (ll i = 2; i * i <= n; ++i) {
        if(isPrime[i]) {
            for (int j = i * i; j <= n; j += i)
                isPrime[j] = false;
        }
    }

    int cnt = 0;
    for (int i = 0; i < (int)isPrime.size(); ++i)
        if(isPrime[i])
            cnt++;
    return cnt;
}
```