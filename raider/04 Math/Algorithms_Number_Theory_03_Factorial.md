## 1. Factorial Basics

**Definition:**  
The factorial of a number `n` (written as `n!`) is the product of all positive integers from 1 to `n`. By definition, `0! = 1`.

**Recursive Example in C++:**
```cpp
long long factorial(int n) {
    if (n <= 1) return 1;
    return n * factorial(n - 1);
}
```

---

## 2. Computing Factorials for Large Numbers

For large numbers (e.g., `500!`), the result quickly exceeds standard data types. We can simulate multiplication by storing digits in a vector.

**C++ Pseudo-Code Example:**
```cpp
#include <vector>
using namespace std;

// Multiply a big number (represented as a vector of digits) by an integer.
vector<int> multiply(vector<int>& number, int multiplier) {
    int carry = 0;
    for (int &digit : number) {
        int product = digit * multiplier + carry;
        digit = product % 10;
        carry = product / 10;
    }
    while (carry) {
        number.push_back(carry % 10);
        carry /= 10;
    }
    return number;
}

vector<int> bigFactorial(int n) {
    vector<int> result = {1}; // Starting with 1
    for (int i = 2; i <= n; ++i) {
        result = multiply(result, i);
    }
    return result;
}
```
*Note:* The digits are stored in reverse order (least significant digit first).

---

## 3. Number of Digits in n!

Rather than computing `n!` directly, you can calculate its digit count using logarithms:
\[
\text{digits} = \lfloor \log_{10}(n!) \rfloor + 1
\]
Since:
\[
\log_{10}(n!) = \log_{10}(1) + \log_{10}(2) + \dots + \log_{10}(n)
\]

**C++ Pseudo-Code:**
```cpp
#include <cmath>

int factorialDigits(int n) {
    if (n <= 1) return 1;
    double digits = 0;
    for (int i = 2; i <= n; ++i) {
        digits += log10(i);
    }
    return static_cast<int>(digits) + 1;
}
```

---

## 4. Maximum Power of a Prime in n! (Legendre’s Formula) -> Very Important

To find the highest power `x` of a prime `p` that divides `n!`, use:
\[
x = \sum_{k=1}^{\infty} \left\lfloor \frac{n}{p^k} \right\rfloor
\]

**C++ Pseudo-Code:**
```cpp
int primePowerInFactorial(int n, int p) {
    int power = 0;
    for (int i = p; i <= n; i *= p) {
        power += n / i;
    }
    return power;
}
```
This loop runs in \(O(\log_p n)\) time.

---

## 5. Factorial Factorization O(nlog(n)loglog(n))

To factorize `n!` into its prime factors:
1. **Generate all primes** up to `n` (using the Sieve of Eratosthenes).
2. **Calculate the exponent** for each prime using the formula above.

**C++ Pseudo-Code:**
```cpp
#include <vector>
#include <iostream>
using namespace std;

// Sieve to generate primes up to n
vector<int> sievePrimes(int n) {
    vector<bool> isPrime(n + 1, true);
    vector<int> primes;
    for (int p = 2; p <= n; ++p) {
        if (isPrime[p]) {
            primes.push_back(p);
            for (int multiple = p * p; multiple <= n; multiple += p) {
                isPrime[multiple] = false;
            }
        }
    }
    return primes;
}

// Factorize n! into primes and print the result
void factorialFactorization(int n) {
    vector<int> primes = sievePrimes(n);
    for (int p : primes) {
        int exponent = primePowerInFactorial(n, p);
        cout << p << "^" << exponent << " ";
    }
    cout << endl;
}
```

---

## 6. Divisibility: Maximum `x` such that \(m^x\) Divides n!

Given a number `m` that factorizes as:
\[
m = p_1^{a_1} \times p_2^{a_2} \times \dots \times p_k^{a_k}
\]
Determine the maximum `x` so that \(m^x\) divides `n!` by computing for each prime factor:
\[
x = \min \left( \frac{\text{exponent in } n!}{a_i} \right)
\]

**C++ Pseudo-Code:**
```cpp

#include <map>
#include <algorithm>
#include <climits>
using namespace std;

// Factorize m into its prime factors.
map<int, int> factorize(int m) {
    map<int, int> factors;
    for (int p = 2; p * p <= m; ++p) {
        while (m % p == 0) {
            factors[p]++;
            m /= p;
        }
    }
    if (m > 1) factors[m]++;
    return factors;
}

// Compute maximum x such that m^x divides n!
int maxPowerDividingFactorial(int n, int m) {
    map<int, int> mFactors = factorize(m);
    int maxX = INT_MAX;
    for (auto [prime, exponent] : mFactors) {
        int powerInFactorial = primePowerInFactorial(n, prime);
        maxX = min(maxX, powerInFactorial / exponent);
    }
    return maxX;
}
```

---

## 7. Greatest Common Divisor (GCD) of Factorials

To compute `gcd(n!, m)`:
1. Factorize `m`.
2. For each prime factor `p`, use the minimum of the exponent in `n!` and in `m`.
3. Multiply together these factors.

**C++ Pseudo-Code:**
```cpp
long long gcdFactorial(int n, int m) {
    map<int, int> mFactors = factorize(m);
    long long result = 1;
    for (auto [prime, exponent] : mFactors) {
        int powerInFactorial = primePowerInFactorial(n, prime);
        int commonExp = min(exponent, powerInFactorial);
        // Multiply result by prime^commonExp
        for (int i = 0; i < commonExp; ++i) {
            result *= prime;
        }
    }
    return result;
}
```

---

## 8. Trailing Zeros in n!

Trailing zeros in `n!` are produced by factors of 10, and since 10 = 2 × 5, we count the number of 5's (because there are always more 2's than 5's).

**C++ Pseudo-Code:**
```cpp
int trailingZeros(int n) {
    int count = 0;
    for (int i = 5; i <= n; i *= 5) {
        count += n / i;
    }
    return count;
}
```

---

## 9. Last Non-Zero Digit of n!

To find the rightmost non-zero digit:
1. Remove the factors that contribute to trailing zeros.
2. Multiply the remaining factors modulo 10.

**C++ Pseudo-Code:**
```cpp
int lastNonZeroDigit(int n) {
    int result = 1;
    int count2 = 0, count5 = 0;
    for (int i = 1; i <= n; ++i) {
        int num = i;
        // Remove factors of 2
        while (num % 2 == 0) { 
            count2++; 
            num /= 2; 
        }
        // Remove factors of 5
        while (num % 5 == 0) { 
            count5++; 
            num /= 5; 
        }
        result = (result * num) % 10;
    }
    // Adjust for remaining 2's (more 2's than 5's)
    for (int i = 0; i < count2 - count5; ++i) {
        result = (result * 2) % 10;
    }
    return result;
}
```

---

## 10. Finding the Smallest N with M Trailing Zeros

To find the smallest `N` such that `N!` has exactly `M` trailing zeros, use binary search:
  
**C++ Pseudo-Code:**
```cpp
int smallestNWithMTrailingZeros(int M) {
    int low = 0, high = 5 * M;  // Upper bound: roughly 5 * M is sufficient
    int answer = -1;
    while (low <= high) {
        int mid = (low + high) / 2;
        int zeros = trailingZeros(mid);
        if (zeros < M) {
            low = mid + 1;
        } else {
            answer = mid;
            high = mid - 1;
        }
    }
    return answer;
}
```

---

## Conclusion

This explanation outlines multiple factorial-related concepts:
- **Basic computation** of factorials.
- **Handling big numbers** by using a vector to store digits.
- **Counting digits** in a factorial without full computation.
- **Determining prime factors** in `n!` using Legendre’s formula.
- **Divisibility queries, GCD** computations, trailing zeros, and the **last non-zero digit** of `n!`.
- **Binary search** for finding the smallest number with a given number of trailing zeros.