Certainly! Let’s walk through a full derivation of the generalized formula for the sum of all pairwise absolute differences, using 1-based indexing.

---

### 🧮 Problem Statement

Given a sorted array of n elements (indexed from 1):

$$
A = [x_1, x_2, ..., x_n] \quad \text{with } x_1 \le x_2 \le \cdots \le x_n
$$

You want to compute:

$$
S = \sum_{1 \le i < j \le n} |x_j - x_i| = \sum_{1 \le i < j \le n} (x_j - x_i)
$$

Note: Since the array is sorted, we can drop the absolute value and directly compute $x_j - x_i$ where $i < j$.

---

### ✂️ Step 1: Rewriting the double sum

$$
S = \sum_{1 \le i < j \le n} (x_j - x_i)
= \sum_{1 \le i < j \le n} x_j - \sum_{1 \le i < j \le n} x_i
$$

Let’s examine these two terms separately.

---

### 🔍 Step 2: Count how many times each element appears

Let’s fix some element $x_k$, and count:

* How many times does $x_k$ appear as a subtrahend (i.e., as $x_i$)?
  ⟶ When $i = k$, it appears in all pairs where $k < j \le n$, so in $n - k$ pairs.

* How many times does $x_k$ appear as a minuend (i.e., as $x_j$)?
  ⟶ When $j = k$, it appears in all pairs where $1 \le i < k$, so in $k - 1$ pairs.

So its total contribution is:

$$
(k - 1)\cdot x_k \text{ (added)} - (n - k)\cdot x_k \text{ (subtracted)} = (2k - n - 1) \cdot x_k
$$

---

### 🧾 Step 3: Final formula

Now sum this over all $k = 1$ to $n$:

$$
S = \sum_{k=1}^{n} (2k - n - 1) \cdot x_k
$$

Thus,

$$
\boxed{
\sum_{1 \le i < j \le n} |x_j - x_i| = \sum_{k=1}^{n} (2k - n - 1) \cdot x_k
}
$$

—

✅ This is the general formula for the total sum of all pairwise absolute differences when the array is sorted and 1-based indexed.

Let me know if you want a geometric interpretation or code implementation too!
