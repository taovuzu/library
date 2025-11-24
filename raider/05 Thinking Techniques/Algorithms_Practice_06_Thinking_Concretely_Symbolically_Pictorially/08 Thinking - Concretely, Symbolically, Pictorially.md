-------------------------------------------- Thinking - Concretely, Symbolically, Pictorially --------------------------------

### Thinking/Solving **Concretely**
Thinking concretely means solving the problem using examples (e.g., evaluating the series).

- **Example**: You are given a formula **F(n)** for a sequence:  
  \[
  F(n) = \frac{3 \times (n+5) \times (n+6)}{2} + 4
  \]
- You start enumerating its values: **4, 67, 88**, then work on its values.
- Typically **easy and natural**.
- Helps a lot in **tough pattern problems**.
- **Bounds your mind** to given examples, so you must carefully consider **other examples** as well.

---

### Thinking/Solving **Symbolically**
Thinking symbolically means **representing everything with symbols** instead of working with actual objects.

- **Example**: Given the formula **F(n)** for a sequence:  
  \[
  F(n) = \frac{3 \times (n+5) \times (n+6)}{2} + 4
  \]
  - Let \( F_1(n) \) be:
    \[
    F_1(n) = \frac{F(n) - 4}{3} = \frac{(n+5) \times (n+6)}{2}
    \]
  - Let \( F_2(n) = F_1(n-5) \), then:
    \[
    F_2(n) = \frac{n \times (n+1)}{2}
    \]
    ...which is a **popular sequence**.

- Here, we work over **symbols, not concrete values**.  
  - E.g., **\( X[i-1] + X[i+1] \geq 2X[i] \) for every \( 1 \leq i \leq n-1 \)**.
- The more you **train over it**, the better you **recognize solutions**.
- Your **abstraction ability improves** too.
- Sometimes, you **can't recognize the solution without it**!

---

### Thinking/Solving **Pictorially**
Thinking pictorially means **drawing the problem elements, their relations, and figuring out properties through visualization**.

- In this approach, we **try to visualize**:
  - **Input elements** and their **relations**.
  - The **nature of the output**.
- Many times, it appears **alongside concrete or symbolic thinking**.
