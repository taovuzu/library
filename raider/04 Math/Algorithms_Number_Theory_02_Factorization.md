# **Factorization and Prime Factorization**
Factorization is the process of breaking a number into its factors.

### **Example:**
Factorizing **300** gives:  
\( 300 = 2 \times 2 \times 3 \times 5 \times 5 \)  
Or, using exponents:  
\( 300 = 2^2 \times 3^1 \times 5^2 \)

### **Fundamental Theorem of Arithmetic**
Every integer \( n > 1 \) is either:
1. A **prime number** (only divisible by 1 and itself).
2. A **unique product of prime numbers** (prime factorization).

For example:
- \( 7 \) is a **prime**.
- \( 12 = 2^2 \times 3^1 \) is **composite**.

---

# **Generating Divisors**
To find all divisors of a number \( n \), we iterate from \( 1 \) to \( \sqrt{n} \). 
**Why \( \sqrt{n} \)?**
Divisors come in **pairs**. If \( d \) is a divisor of \( n \), then \( \frac{n}{d} \) is also a divisor.

For example, divisors of **36**:
- \( 1 \times 36 \)
- \( 2 \times 18 \)
- \( 3 \times 12 \)
- \( 4 \times 9 \)
- \( 6 \times 6 \) (only counted once)

### **Implementation**
```cpp
vector<ll> generate_divisors(ll n) // O(sqrt(n))
{
    vector<ll> v;
    for(ll i = 1; i * i <= n; ++i) {
        if(n % i == 0) {  
            v.push_back(i);      // Store the divisor
            if(i != n / i)       // Avoid duplicate if n is a perfect square
                v.push_back(n / i);
        }
    }
    return v;  // List of divisors (unordered)
}
```

### **Example Run**
For **n = 36**:
- \( i = 1 \) → \( v = [1, 36] \)
- \( i = 2 \) → \( v = [1, 36, 2, 18] \)
- \( i = 3 \) → \( v = [1, 36, 2, 18, 3, 12] \)
- \( i = 4 \) → \( v = [1, 36, 2, 18, 3, 12, 4, 9] \)
- \( i = 6 \) → \( v = [1, 36, 2, 18, 3, 12, 4, 9, 6] \)

**Final Output:** \( [1, 2, 3, 4, 6, 9, 12, 18, 36] \)

---

# **Prime Factorization**
The goal is to express \( n \) as a product of prime numbers.

### **Algorithm:**
1. **Try dividing by small primes** starting from \( 2 \).
2. **Divide out each prime factor completely**.
3. **Move to the next prime**.
4. **If anything remains after \( \sqrt{n} \), it's a prime number**.

### **Implementation**
```cpp
vector<ll> factorization(ll n) // O(sqrt(n))
{
    vector<ll> primes;
    for (ll i = 2; i * i <= n; ++i) {  
        while (n % i == 0) {  
            primes.push_back(i);  
            n /= i;
        }
    }
    if (n > 1)  
        primes.push_back(n); // Remaining prime factor

    return primes;
}
```

### **Example Run**
For **n = 300**:
- \( i = 2 \): \( 300 \div 2 = 150 \), \( 150 \div 2 = 75 \) → Store \( [2, 2] \)
- \( i = 3 \): \( 75 \div 3 = 25 \) → Store \( [2, 2, 3] \)
- \( i = 5 \): \( 25 \div 5 = 5 \), \( 5 \div 5 = 1 \) → Store \( [2, 2, 3, 5, 5] \)

**Final Output:** \( [2, 2, 3, 5, 5] \)

---

# **Counting the Number of Divisors**
Using **prime factorization**, we can compute the total number of divisors.

If:
\[
n = p_1^{a_1} \times p_2^{a_2} \times p_3^{a_3} \dots
\]
Then, the total number of divisors is:
\[
\text{divisors}(n) = (a_1 + 1) \times (a_2 + 1) \times (a_3 + 1) \dots
\]

### **Example**
For \( 12 = 2^2 \times 3^1 \):
\[
(2+1) \times (1+1) = 3 \times 2 = 6
\]
Divisors: \( [1, 2, 3, 4, 6, 12] \).

---

# **Summing Divisors Over a Range**
### **Brute Force (Slow)**
Loop through \( 1 \) to \( n \), calling `generate_divisors()`.

```cpp
int rangeFactorization1(int n) // O(n * sqrt(n))
{
    int s = 0;
    for (int i = 1; i <= n; i++)
        s += generate_divisors(i).size();
    return s;
}
```

**Problem:** Too slow for large \( n \).

---

### **Optimized Approach: Using a Sieve**
Instead of factorizing each number, we count divisors efficiently.

```cpp
int rangeFactorization2(int n) // O(n log n)
{
    vector<int> numFactors(n + 1, 0);
    for (int i = 1; i <= n; i++) {  
        for (int k = i; k <= n; k += i)  
            numFactors[k]++;  // Increment divisor count
    }

    int s = 0;
    for (int i = 1; i <= n; i++)
        s += numFactors[i];

    return s;
}
```

### **Explanation**
- For each number \( i \), add \( i \) as a divisor to all its multiples.
- Runs in **\( O(n \log n) \)** instead of \( O(n \sqrt{n}) \).

### **Example Run for \( n = 6 \)**
```
i = 1:  [1, 1, 1, 1, 1, 1] (1 divides all)
i = 2:  [1, 2, 1, 2, 1, 2] (2 divides 2, 4, 6)
i = 3:  [1, 2, 2, 2, 1, 3] (3 divides 3, 6)
i = 4:  [1, 2, 2, 3, 1, 3] (4 divides 4)
i = 5:  [1, 2, 2, 3, 2, 3] (5 divides 5)
i = 6:  [1, 2, 2, 3, 2, 4] (6 divides 6)
```
Final sum: \( 1 + 2 + 2 + 3 + 2 + 4 = 14 \).

---

# **Conclusion**
- **Brute force** divisor counting is slow (\( O(n \sqrt{n}) \)).
- **Using a sieve**, we get **\( O(n \log n) \)** efficiency.
- **Prime factorization** helps count divisors easily.


# Segmented Sieve Algorithm (Range \([a, b]\))  

This implementation finds all prime numbers in a given range \([a, b]\), where \( b \leq 10^{12} \) and \((b-a) \leq 10^6\).  

## Approach:
1. **Find primes up to \(\sqrt{b}\):**  
   - Use the simple Sieve of Eratosthenes to find all primes in the range \([1, \sqrt{b}]\).
2. **Mark non-primes in range \([a, b]\):**  
   - Use the found primes to mark their multiples as non-prime in \([a, b]\).

## Implementation:

```cpp
#include <bits/stdc++.h>
using namespace std;

vector<bool> primes_A_B;

template <typename T>
void primesFinder(T a, T b) {
  int limit = sqrtl(b);
  vector<bool> mark(limit + 1, true);
  primes_A_B.assign(b - a + 1, true);

  for (int i = 2; i <= limit; i++) {
    if (mark[i]) {
      for (int j = i * i; j <= limit; j += i) {
        mark[j] = false;
      }
      T start = max((T)i * i, ((a + i - 1) / i) * i);
      for (T j = start; j <= b; j += i) {
        primes_A_B[j - a] = false;
      }
    }
  }

  if (a == 1) {
    primes_A_B[0] = false;
  }
}
```
- **Overall Complexity**: Approximately \( O((b - a + \sqrt{b}) \log \log b) \)



For large numbers, sieve-based approaches are best for divisor-related problems. 🚀