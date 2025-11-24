Below is a structured explanation summarizing the key ideas about dynamic programming (DP) and greedy algorithms, along with illustrative examples and proof ideas. This overview captures the principles, practical tips, and examples provided in the text.

---

## 1. Dynamic Programming (DP) – Remember the Essentials

### **Key Points**

- **Purpose:**  
  DP is used for problems where you need to perform maximization or minimization (e.g., the Knapsack problem).  
- **State Formulation:**  
  - Define each state (or subproblem) clearly.  
  - A state (S_root) often branches into multiple substates (S_child1, S_child2, S_child3, …).  
  - The goal is to try every substate and choose the one that gives the optimal (maximum or minimum) result.
- **Overlapping Subproblems:**  
  When subproblems repeat, store (memoize) the result to avoid redundant calculations.  
- **Bottom-Up vs. Top-Down (Memoization):**  
  Both approaches rely on the same recurrence, but memoization is more natural when you already have a recursive solution.

### **General DP Strategy**

1. **Identify the Optimal Substructure:**  
   Recognize how the optimal solution can be built from the optimal solutions of its subproblems.
2. **Define the State:**  
   For example, in a grid path problem, the state might be the current cell \((i, j)\).
3. **Establish the Recurrence:**  
   Write a relation that expresses the solution in terms of solutions to smaller subproblems.
4. **Memoize or Build Iteratively:**  
   Save results for reuse (top-down memoization) or fill a table iteratively (bottom-up DP).

---

## 2. Greedy Algorithms – The One-Choice-at-a-Time Approach

### **Key Concepts**

- **Greedy Choice:**  
  At each step, make the choice that seems best at the moment (locally optimal) without reconsidering previous decisions.
- **Heuristic/Intuition:**  
  Greedy algorithms rely on a heuristic that, if proven, guarantees that the local optimum leads to a global optimum.
- **Global vs. Approximate Optimum:**  
  In contests, the goal is usually to find the global optimum. In real-world applications, an approximate solution might be acceptable.
- **Proof and Intuition:**  
  - It is crucial to be able to prove that a greedy choice indeed leads to an optimal solution.
  - In contests, you might rely on intuition and test cases, but post-contest, studying the proof is important for deeper understanding.

### **General Greedy Strategy**

1. **Select the Greedy Criterion:**  
   Decide what measure or ratio to optimize at every step.
2. **Sort or Order Data:**  
   Many greedy algorithms require sorting by the greedy criterion.
3. **Iterate Once:**  
   Make a single pass through the data, choosing the best option at each step.
4. **Verify Optimality:**  
   When possible, provide a proof or counterexamples to validate the greedy strategy.

---

## 3. Examples

### **Example 1: Activity Selection Problem**

- **Problem Statement:**  
  Given a set of activities with start time \( S[i] \) and finish time \( F[i] \), select the maximum number of activities that do not overlap. An activity can start exactly when another finishes.
  
- **DP Approach:**  
  - You could consider every subset (pick or leave each activity) after sorting the activities.  
  - However, this leads to a complex state-space where you must decide on non-overlapping choices.
  
- **Greedy Approach:**  
  - **Intuition:**  
    Select the activity that finishes earliest because it leaves the most room for subsequent activities.
  - **Proof Sketch:**  
    1. **Sort** the activities by finish time.
    2. **Assume** an optimal solution does not include the earliest finishing activity.
    3. **Show** that replacing the first activity with the earliest finishing one still produces an optimal solution.
    4. **Conclude** that the greedy solution is optimal.
  
- **Outcome:**  
  The greedy algorithm for activity selection is both simple and optimal.

---

### **Example 2: Fractional Knapsack Problem**

- **Problem Statement:**  
  Given a knapsack with a fixed capacity \( R \) and materials with given values and weights, choose fractions of materials to maximize the total value.
  
- **DP Approach:**  
  - A typical DP (similar to the coin-change problem) would consider taking items piece by piece.
  - However, since fractions are allowed, DP is less efficient compared to the greedy method.
  
- **Greedy Approach:**  
  - **Criterion:**  
    Calculate the value per unit weight for each item.
  - **Algorithm:**  
    1. **Sort** the items in decreasing order of value per unit weight.
    2. **Pick** as much as possible from the item with the highest ratio until the knapsack is full, then move to the next.
  - **Result:**  
    This yields the optimal solution in \( O(n \log n) \) time due to sorting.
  
- **Proof Consideration:**  
  Although the idea is intuitive, the proof requires careful analysis (typically a page-long mathematical argument).

---

## 4. Final Thoughts

- **Comparison Between DP and Greedy:**  
  - **DP:**  
    Suitable when you need to explore every possibility (maximize/minimize) and when subproblems overlap.
  - **Greedy:**  
    Fast and simple when a locally optimal choice leads to a global optimum; however, it requires rigorous proof for optimality.
- **Contest Implications:**  
  - In contests, you must often focus on finding a globally optimal solution quickly. Greedy solutions are preferred when applicable, but knowing DP is essential for problems where greedy does not suffice.
  - Understanding the proofs behind these strategies is important for long-term improvement even if contest strategies sometimes rely on intuition.

### **Additional Links for Further Reading**

- [Greedy Algorithm – Wikipedia](http://en.wikipedia.org/wiki/Greedy_algorithm)
- [Heuristic (Computer Science) – Wikipedia](http://en.wikipedia.org/wiki/Heuristic_%28computer_science%29)
- [Activity Selection Problem – TopCoder Tutorial](http://community.topcoder.com/tc?module=Static&d1=tutorials&d2=greedyAlg)
- [Fractional Knapsack – Theory and Proof Techniques](http://en.wikipedia.org/wiki/Activity_selection_problem)

---

This summary emphasizes the contrasting approaches of dynamic programming and greedy algorithms, provides concrete examples (Activity Selection and Fractional Knapsack), and outlines the necessary proof and intuition aspects to ensure a deeper understanding.