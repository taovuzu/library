## Thinking - Misc

### 1. The Brute Force Solution
One of the best ways to think about a problem is the Brute Force (BF) solution.
- Even if you think it won't be the final solution or is not practical at all, start with it.
- In many cases, the solution is the BF one but improved based on observations or clever coding.
- It requires minimal thinking, which helps avoid overestimation and starts from trivial to complex.
- In the worst case, BF allows your mind to explore the problem rather than getting stuck.

Think in both **BF Iterative and Recursive** approaches. Consider the **search space** and **search state**.

### 2. The Similar Problems - Advantages & Cautions
- Sometimes, you recognize that you've encountered a **similar problem** before.
- This can be an advantage as you might recall useful properties from previous problems.
- However, **do not blindly use your old solution**; instead, ask:
  - What exactly was the same in the old problem?
  - What is different? How do these changes affect the solution?
- Don't let a similar problem **mislead** you.

### 3. Still Stuck? Try These Approaches
- **Re-state the problem definition** in 2 or 3 different ways to gain new insights.
- **Write the impractical BF solution** and observe patterns or useful facts.
- **Use Guess & Check:** Make assumptions and verify them extensively with test cases.
- **Iterate on your algorithm list** and see if any could be the solution.

### 4. Be Careful in Analyzing Solutions
- You might discard a correct solution due to incorrect analysis.
  - Example: You estimated complexity as **O(n³)** when it was actually **O(n² log n)**.
  - Example: You miscalculated recursion depth, making DFS seem like TLE/RTE.

### 5. Handling Large `N` or High Complexity
- **Check exact # of operations**, not just the order.
- **Look for reduced variables & constrained input combinations**.
- **Identify sparsity & symmetry** (e.g., matrix exponentiation often results in repeated values).
- **Locality tricks:**
  - Order loops so that they don't traverse arrays inefficiently.
  - Avoid column-order access if row-order is faster.
  - Duplicate memory if needed to improve access patterns.
- **Pre-computation & Preprocessing:**
  - Consider full or partial pre-computation.
  - If `N < 500` or values are small, explore pre-computation benefits.
  - Sort queries for optimization.
- **Clever Tricks:**
  - If loops involve `2.5 × 10⁸` operations (beyond the `10⁸` limit), check for:
    - **Early termination conditions**.
    - **Sorting/reordering** input to optimize loop breaks (e.g., SRM421-1-2 CakesEqualization).

## Thinking - Solution Verification
### Found a Solution? Wait!
- Many rush to code before verifying their solution.
- **Before verification, consider KISS (Keep It Simple, Stupid).** Could a simpler approach work?

### Steps for Verifying a Solution
1. **Test Cases Verification** (Use provided cases, boundary cases, and your own custom cases).
2. **Analyze Time & Memory Complexity**.
3. **Full Logical & Intuitive Review**.
4. **Check Correctness & Assumptions**.
5. **For recursive solutions:** Ensure depth limits are reasonable.
6. **For arithmetic operations (`*`, `+`, `^`)**: Watch for overflows in intermediate or final results.
7. **For division (`/`)**: Ensure precision is sufficient.

## Thinking - Solution Implementation
### Key to Improvement: Discipline + Stepping Out of Your Comfort Zone
- By now, you should have a verified idea.
- Before coding, ensure you have a **full vision of the code structure**.

### Before Coding
1. **Plan code blocks**: Identify repetitive sections and order them logically.
2. **Explore alternative approaches**: Optimize sub-targets.
3. **For difficult blocks, write full code on paper first**.

### After Implementation
1. **Revise code structure & logic**: Ensure it aligns with your intended approach.
2. **Challenge every code block**: Read carefully, ensuring every character is correct.
3. **Check edge cases for failures** (e.g., division by zero in `A/B`).
4. **Review data types**, especially in overflow-prone scenarios.
5. **Watch out for dangerous operations (`/`, `%`, `+`, `*`)** that may cause runtime errors or overflows.
6. **For floating-point calculations**, ensure precision is adequate (`(int)(a ± EPS)`).

### Testing Checklist
- **Special Cases & Boundaries**:
  - Given `X` → Test `-a`, `0`, `+a`, and max/min values.
  - Given a board `N × M` → Test sizes like `1×1`, `2×2`, `N×1`, etc.
  - Given a sequence → Test empty, full-length, all positive, all negative, mixed values.

### What If It Fails?
- **Check the Error Inspection List** to debug efficiently.

### Got Accepted? How to Improve Further
1. **Shorten your code**: Learn from top coders (e.g., TC, CF, AtCoder solutions).
2. **Optimize execution time**: Compare against fastest solutions on platforms like SPOJ and UVA.
3. **Explore alternate approaches**: Read forums and editorial discussions to gain new perspectives.