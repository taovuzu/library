## Thinking - Search Space and Output Analysis

One of the important ways to tackle a problem is to start from the output and analyze it and its space.

When we are solving a problem, there could be many candidate solutions for it.

- A candidate solution is a member of a set of possible solutions to a given problem.
- A candidate solution does not have to be the target solution to the problem – it is just part of the set that satisfies all constraints.
- The space of all candidate solutions is called the feasible region, feasible set, **SEARCH SPACE**, or solution space.
- Every candidate solution C is good **IFF** `satisfyConstraints(C) = TRUE`
- Every candidate solution C is mapped to `F(C)`, which is the evaluation of this C.

### Three Key Considerations:
Let:
- `S = {C1, C2, ...}` be the set of candidate solutions.
- `F(C)` be the function according to the problem statement.
- `F(C) = O`, the output of the function.

We need to think in terms of:
1. **Size of Cs** - Number of candidate solutions.
2. **Nature of F** - The function that generates the output.
3. **Output Bounding** - The output of the function.

---
## Search Space Size \(|S|\)

Sometimes, the entire search space \(|S|\) is small enough to brute-force it.

**Brute-force search (exhaustive search)** systematically enumerates all possible candidates for the solution and checks whether each candidate satisfies the problem's statement.

Example:
- Given an array of length `N = 1000`, what is the maximum difference between a pair of numbers?
- The search space consists of all pairs `(A, B)`, meaning we try every pair and maximize among them.
- The total number of pairs is `N^2 = 10^6`, which is doable! So brute force is enough.

#### Example Calculation:
Let’s say the array is: `2, 5, 1, 4`
- Candidate pairs: `(2,5), (2,1), (2,4), (5,1), (5,4), (1,4)`
- `F(C) = |A-B|`: `3, 1, 2, 4, 1, 3`
- The best pair is `(5,1)` with `F(C) = 4`.

#### What if `N = 100000`?
- We then have `10^10` pairs! Exhaustive search becomes impossible!
- We need a better algorithm.

#### Optimization:
**Observation**: The maximum difference will be between the smallest and largest numbers!
- Sorting the array: `[1, 2, 4, 5]`
- Solution: `max - min = 5 - 1 = 4`
- Sorting complexity: `O(N log N)`, which is feasible.

In some cases, we use brute-force but with tricks to optimize it, such as:
- **Search space pruning**
- **Branch and Bound**
- **Memoization**

---
## Nature of the Target Function

Understanding the function F helps determine how to approach solving the problem.

### Common Categories:
1. **Decision problems (True/False):**
   - Examples: `2-SAT, Bellman Difference Constraints, Graph Bipartiteness`.

2. **Optimization problems (Find min/max F()):**
   - First, consider known algorithms for optimization:
     - **Common:** Brute-force, DFS, BFS, DP, Greedy, Binary/Ternary Search, Divide & Conquer, Branch & Bound.
     - **Minimization Examples:** Min cut, MST, Dijkstra, Convex Hull.
     - **Maximization Examples:** Max flow, GCD, Max Independent Set.

3. **Counting problems:**
   - Examples: DP, Combinations, Permutations, Inclusion-Exclusion, Matrix Power.
   - Different approaches to counting may offer insights:
     - **Segment-based thinking**
     - **Layer-based modeling**
     - **Traversal order considerations**

---
## Output Bounding

Bounding the output of function `F` is crucial. This means establishing its **min/max values**.

- Sometimes, an approximate bound is sufficient.
- Example: If an `O(n log n)` algorithm can solve the problem for an estimated upper bound of `100000`, it is enough—even if the correct bound is actually `5000`.

### Example: SRM522-1-2 (CorrectMultiplication)
Given `a, b, c`, find the minimum value of:
\[ |A - a| + |B - b| + |C - c| \]
where `A, B, C` satisfy `A * B = C`.

#### Bounding Strategies:
- Best case: `A=a, B=b, C=c` → Result = `0`.
- Worst case: `A=1, B=1, C=1` → Result = `a + b + c - 3`.
- By exploiting multiplication properties:
  - Only check `A ≤ sqrt(Result + c)`, and swap `(a, b)` to guarantee all cases are tried.

---
### Example: SRM507-1-2 (CubePacking)
- `Ns` small cubes of size `1×1×1`.
- `Nb` large cubes of size `L×L×L`.
- Find the minimum volume of a box to pack all cubes.

Bounding approach:
- Consider synonymous boundings: `(X, Y, Z)` or `Result = X * Y * Z`.
- Sorting constraints: `X ≤ Y ≤ Z`.
- Using estimated upper bounds to limit search space (`O(n^3)`).

---
## Conclusion
Thinking in terms of **Search Space, Function Nature, and Output Bounding** helps optimize problem-solving strategies effectively. Applying known techniques like brute-force, heuristics, and mathematical properties often leads to efficient solutions.
