### **Thinking – Incremental Approach**  

Incremental algorithms **process input step by step**, updating the solution as new elements are added. This approach is powerful when problems can be **built progressively** from smaller solutions.  

---

## **1. Understanding Incremental Thinking**  
🔹 The key idea: **"If we have solved for the first m elements, how do we efficiently solve for m+1?"**  
🔹 Often, **sorting the input first** helps in structuring the incremental update process.  
🔹 In some cases, **randomizing input order** can improve efficiency.  

---

## **2. Examples of Incremental Thinking**  

### **🟢 Example 1: Insertion Sort (Building Sorted Order Step by Step)**  
💡 **Problem:** Given an unordered list of numbers, sort them.  

🔹 **Incremental Approach:**  
1. Assume the first `m` elements are **already sorted**.  
2. Insert the `m+1` element in its **correct position** by shifting elements.  

📌 **Example:** Sorting `{10, 2, 7, 4, 15}` step by step:  
- `{2, 7, 10}` → sorted first 3 elements  
- Insert `4`:  
  - `{2, 7, 10, 4}` (initially)  
  - `{2, 7, 4, 10}` (shift 10)  
  - `{2, 4, 7, 10}` (shift 7) ✅  
- This is **Insertion Sort**!  

---

### **🟢 Example 2: Expected Value of an Array with Random Swaps**  
💡 **Problem:** An array undergoes `K` random swaps. What is the expected result?  

🔹 **Incremental Approach:**  
1. Assume the **expected values** after `m` swaps are known.  
2. Update the values for `m+1` swaps by **adjusting probabilities**:  
   - A position has some probability to **stay unchanged**.  
   - A position has some probability to be **swapped with another value**.  
3. Use **mathematical expectation formulas** to update step by step.  

📌 **Example formula update for an element:**  
- `a'  = a*prop(unchanged) + b*prop(swap) + c*prop(swap) + ...`  
- `b'  = a*prop(swap) + b*prop(unchanged) + c*prop(swap) + ...`  

✅ **This method was used in SRM 575 Div1 250pts problem!**  

---

### **🟢 Example 3: Convex Hull Construction (Sorting Before Incremental Processing)**  
💡 **Problem:** Given `N` points in 2D space, construct their **Convex Hull** (the smallest enclosing polygon).  

🔹 **Naïve Incremental Approach (Fails!):**  
- If we have the hull for `m` points, adding `m+1` **does not guarantee an efficient update**.  
- Why? The hull might have to be **completely reconstructed**!  

🔹 **Better Approach:**  
1. **Sort points** relative to a reference corner.  
2. Process points **in sorted order**, maintaining the hull incrementally.  
3. New points are **added in order**, ensuring we only update the **hull boundary efficiently**.  

✅ **Sorting first makes the incremental updates work!**  

---

### **🟢 Example 4: Bomb Power in Random Squares (Sorting Helps!)**  
💡 **Problem:** Given multiple squares `{(-R, -R), (R, R)}`, each containing a bomb at a random location, compute the **expected power**.  

🔹 **Incremental Approach:**  
1. **Sort squares** based on `R`.  
2. Compute the **expected power for the first `m` squares**.  
3. Update for `m+1` by **adding new contributions efficiently**.  

✅ **This was used in SRM 526.5 Div1 250pts problem!**  

---

## **3. When Incremental Algorithms Struggle**  

1️⃣ **When the update operation is too expensive**  
   - If updating from `m` to `m+1` is costly, it might **not be a good approach**.  
   - Try **alternative data structures** (Segment Trees, Fenwick Trees, etc.).  

2️⃣ **When input order matters**  
   - **Randomizing input order** might help balance the algorithm’s complexity.  

3️⃣ **When updates follow a systematic pattern**  
   - Use **matrix exponentiation** to apply multiple updates in one step.  

---

## **4. Key Takeaways**  

✅ **Incremental Thinking** helps break a problem into **step-by-step updates**.  
✅ Sorting before incremental processing can **make updates efficient**.  
✅ Consider **alternative approaches** if updates are expensive.  
✅ When updates are structured, **matrix exponentiation** can compress multiple steps.  

🚀 **"Think one step ahead—build solutions progressively!"**