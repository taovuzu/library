Below is a structured explanation of the two TopCoder problems—RGBStreet and MaximalProduct—illustrating how dynamic programming (DP) with memoization is applied to solve them. The explanation is broken into clear sections with commentary and C++–style pseudo-code.

---

## 1. Overview of Dynamic Programming & Memoization

Dynamic Programming is used when a problem can be broken into overlapping subproblems. Instead of recomputing the same subproblems repeatedly (which may lead to exponential time), we store their results (memoization) or build a table iteratively (bottom-up DP).  
In these examples, a top-down memoized approach is used:
- **Memoization:** Store computed results in a table so that each unique state is processed only once.
- **Recursive formulation:** The solution is defined in terms of smaller subproblems.

---

## 2. Problem 1: RGBStreet

### **Problem Context**

- **Goal:**  
  Paint a row of houses using three colors—red, green, and blue—at minimum cost.
  
- **Constraint:**  
  Two adjacent houses cannot have the same color.

### **Approach and Key Ideas**

- **State Definition:**  
  Let `minCost(i, lastColor)` be the minimum cost to paint houses from index `i` to `n-1`, given that the previous house was painted with `lastColor`.  
  - Colors are represented by indices 0 (red), 1 (green), 2 (blue).  
  - An initial state of `lastColor = 3` indicates that no color has been chosen yet, so any color is allowed.

- **Recurrence:**  
  At each house `i`, for every color different from `lastColor`, choose that color and add its cost to the minimum cost for the remaining houses.

- **Memoization:**  
  Use a 2D array `mem[i][lastColor]` to store results and avoid re-calculations.

### **Pseudo-code**

```cpp
const int MAX = 21;
int r[MAX], g[MAX], b[MAX];
int n;
const int OO = 1e6; // A large constant for initialization
int mem[MAX][4];    // 4 for lastColor: 0,1,2 or 3 (none chosen)

int minCost(int i, int lastColor) {
    if (i == n) 
        return 0; // Base case: no houses left to paint.
    
    int &ret = mem[i][lastColor];
    if (ret != -1)
        return ret;
    
    ret = OO;
    // For each color, if it's not equal to lastColor, try that color.
    if (lastColor != 0)
        ret = min(ret, r[i] + minCost(i + 1, 0));
    if (lastColor != 1)
        ret = min(ret, g[i] + minCost(i + 1, 1));
    if (lastColor != 2)
        ret = min(ret, b[i] + minCost(i + 1, 2));
    
    return ret;
}

class RGBStreet {
public:
    // Input: vector of strings; each string contains costs for red, green, blue.
    int estimateCost(vector<string> houses) {
        for (int i = 0; i < houses.size(); i++) {
            istringstream iss(houses[i]);
            iss >> r[i] >> g[i] >> b[i];
        }
        n = houses.size();
        memset(mem, -1, sizeof(mem)); // Initialize memoization table with -1.
        // Start with lastColor = 3, meaning no color has been used yet.
        return minCost(0, 3);
    }
};
```

---

## 3. Problem 2: MaximalProduct

### **Problem Context**

- **Goal:**  
  Given a total sum `s` and a number of parts `k`, partition `s` into `k` positive integers (each at least 1) so that their product is maximized.

### **Approach and Key Ideas**

- **State Definition:**  
  Let `maxProd(k, rem)` denote the maximum product obtainable by partitioning a remaining sum `rem` using parts from index `k` to `maxK - 1`.  
  - `maxK` is the total number of parts to be formed.
  
- **Recurrence:**  
  For each part, try all possible values `i` (from 1 to `rem`), then recursively compute the maximal product for the remaining parts with the remaining sum `rem - i`. Multiply `i` with the result of the subproblem.
  
- **Memoization:**  
  Use a 2D table `mem[k][rem]` to cache results for a given state `(k, rem)`.

### **Pseudo-code**

```cpp
typedef long long ll;
const int MAX = 21;
int maxK;
ll mem[21][101];  // Dimensions: up to 20 parts, and sum up to 100 (adjust as needed)

// Returns the maximal product for partitioning 'rem' using parts starting from index 'k'.
ll maxProd(int k, int rem) {
    if (k == maxK) {
        // Base case: if no remainder, product is 1; otherwise, partitioning fails.
        return (rem == 0) ? 1 : 0;
    }
    if (rem == 0)
        return 0;  // Invalid state if no sum remains.
    
    ll &ret = mem[k][rem];
    if (ret != -1)
        return ret;
    
    ret = 0;
    // Try every possible value for the current partition.
    for (int i = 1; i <= rem; ++i) {
        ll sol = maxProd(k + 1, rem - i) * i;
        ret = max(ret, sol);
    }
    return ret;
}

class MaximalProduct {
public:
    long long maximalProduct(int s, int k) {
        maxK = k;
        memset(mem, -1, sizeof(mem)); // Initialize memo table with -1.
        return maxProd(0, s);
    }
};
```

---

## 4. Conclusion

Both problems illustrate the power of dynamic programming with memoization:

- **RGBStreet:**  
  A minimization problem where the goal is to choose colors for houses under adjacency constraints. The state is defined by the current house and the last color chosen, and the solution recursively computes the minimum cost with memoization.

- **MaximalProduct:**  
  A partitioning problem where a sum is split into parts to maximize their product. Here, the state is defined by the current part index and the remaining sum, and a recursive exploration over all valid partitions is memoized to achieve efficiency.

These examples demonstrate:
- How overlapping subproblems can be handled efficiently.
- The importance of defining a clear state and recurrence.
- The dramatic reduction in time complexity—from exponential (naïve recursion) to polynomial with memoization.

Feel free to ask if you need further clarification or additional examples on these dynamic programming techniques!