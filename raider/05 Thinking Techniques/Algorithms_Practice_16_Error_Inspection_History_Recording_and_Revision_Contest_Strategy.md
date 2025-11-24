# General Inspection

- **Do you Terminate before reading whole input?** Do you break while reading, and test case is not fully read?  
- **Correct input file / Correct input copy**  
- **Correctly initialize between test cases**  
- **Correct reading:**  
  - E.g. `scanf("%d ", &cases);` Space is correct in this Input file?  
- **Tested corner cases?**  
- **If you take something from library, that does not mean it is 100% right**  
- **If you take something from library, revise its comments & prerequisites**  
- **Validate:**  
  - Input stopping conditions  
  - Functions base case / Problem Logic Lines.  
  - No TYPO  
  - Used data types enough to avoid overflow  
  - Operators `*`, `^`, `/`, `%`  
    - `/0`, `%0`, `/EPS`, `(n)%x`, `(-n)%x`, `+/- EPS`  
    - `*`, `^`, counting problems = Overflow  
  - Results fit in 32-bit operations, what about intermediate values?  
  - Correct OO Value. Initial value when you maximize & minimize  
  - `x%m` is X negative? Given Matrix A, find `(A^b)%M`, Make sure A is initialized correctly in case of negatives  
  - `if(x%2 == 1) ..` What if x negative value?  
  - **Set or Multiset?**  
  - **Wrong pair comparisons:** `pair1 > pair2` does not check both elements for larger  
  - **Truncate or approximate, double issues:**  
    - Watch out for `-0.0`, `Floor(-2.3) = -3` but `Floor(2.3) = 2`  
  - **Not a number (NAN)** which comes from `sqrt(-ve)`, `(0/0)`, or `cos(1.00000000001)` or `cos(-1.000000000001)`  
  - **Loops:**  
    - `lp(i, n) lp(j, i+1, n)`: is there at least 2 elements? Do you need special handling?  

## Precision Problems  

- **You should calculate the worst precision**  
  - E.g. `1 / 10^9 / 10^5`  
- **Avoid double operations if possible:**  
  - E.g. integer floor & ceil - even with in-depth replacement.  
- **Try to do double operations as locally as possible**  
  - E.g. sum all vs sum part + call(nxt)  
- **Counting the doubles changes little their value**  
- **Do binary search to 9 precision, and display `x*100`. Output is only 7 precision**  

## BFS with More Than One Start State  

- **Make sure they are all of same depth**  
- **Make sure, in case of lexicographical answer, that you use a priority queue**  
- **Do we need to validate the initial states?**  

---

# WA (Wrong Answer)

- **Pick a moderated example and do problem semantic tracing**  
- **Sometimes your added tricky code to make programming easier is just a KILLER BUG**  
  - TRY to validate your fancy added code to avoid debugging for silly mistakes  
  - E.g. appending a 2D strings array to make it a complete 2D.  
    - Take care, is the appended character part of input? Does it matter?  
- **If you have a direction array, does order matter?**  

### Overflow  

- **Read numbers `N < 2^M` where `M = 60`**  
- **Manipulating bit masks with `N >= 32`, E.g. `1<<40`**  
- **Multiplications (cross product) & powers & base conversions**  
- **Is whole code handled for OVERFLOW or is it a mix of `int` and `LL`?!**  
  - `1<<x` or `1LL<<x`  
- **Correct overflow handling:**  
  - E.g. use `if (a*b > OO)` or `if (a > OO/b)`  
  - E.g. use `if (a+b > OO)` or `if (a > OO-b)`  

### Wrong Stopping Conditions  

- **Test ends with `TestEnd` and input with `InputFinish`. What if such words inside the main input also?**  
- **Read until one of `x`, `y`, or `z` is zero**  
- **Each block will be terminated by a line containing `#`.**  
  - Is this a tricky `#`?  

### Geometry  

- **Is there duplicate points? Does it matter? Co-linearity?**  

### Graph  

- **Connected or disconnected?**  
- **Directed or Undirected?**  
- **SelfLoops?**  
- **Multiple edges & their effect (MaxFlow sum, SP min)**  

---

# TLE (Time Limit Exceeded)

- **May be a bug and just an infinite loop**  
- **Can results be precomputed in a table?**  
- **Function calls may need reference variables**  
- **`%` is used extensively? `memset` is used extensively?**  
- **What is the block of code that represents order? Do we just need to optimize it?**  

### Big Input File  

- Need `scanf` & `printf`  
- Optimize code operations  
- Switch to arrays and `char[]`  

### DP Problems  

- **Do you clear each time while it is not needed?**  
- **Clear only part of memory you need, not all of memo, or use boolean array**  
- **The base case order is not `O(1)`**  
- **Use effective base conditions**  
- **Return result `% 10^7`**  

### Backtracking  

- **If you have different ways to do it, try to do what minimizes stack depth**  

### Graph Problems  

- **Generate dynamic sub-states (edges) only when necessary**  

---

# RTE (Runtime Error)

- **Correct input file?**  
- **Array index out of boundary**  
  - Make sure to have correct array size.  
  - Make sure no wrong indexing `< 0 || x >= n`  
  - E.g. Find Primes in range `[-2, 3]`  
  - Find factorial `-5!`  
- **Stack overflow from infinite recursion**  
  - Visited array not marked correctly  
  - DP with cyclic/wrong recurrence  
- **You have data structures that require huge data**  
- **Division by zero (`/0`), modulo zero (`%0`)**  
- **Extensive memory allocating until RTE**  
- **Using incorrect compare function**  
- **Using uninitialized data**  
- **Watch out, if multiset contains `(3 3 3 3 6 9)` and you delete `3`, it will be `(6, 9)`**  
  - To delete one item, use iterator to find & delete it  

---


	
	--------------------------------------------------History Recording and Revision--------------------------------------

Imagine:
	After some years of hard practice, you solved like 1000 problems!
		1000 problems will typically be a great experience. Ideas from everywhere, different zone challenges.
		Imagine you were solving a problem that you solved before, but you did SAME mistakes you did before! 
			Or couldn't solve it without getting the same hint!
			Then, you did not fully utilize your experience from the 1000 problems!
			Following are some tips!

### History Recording

	It is very useful to record lots of statistics about what you solved. Maintain a file for all problems containing:
		- Problem Statement ID / URL
		- Problem Statement Text Level (Easy, Medium, Hard)
		- Idea Level
		- Code Level
		- Problem Solution Category (e.g. branch and bound Search)
		
	In the source code of a problem, write an Idea Sketch for hard problems. Make sure it is clear.
	Always name your source codes with problem IDs. E.g. TC problem `350_D1_3.cpp`. UVA with its ID (e.g. `10123.cpp`).
		
	Maintain 2 files for every category. E.g., for Graph Theory:
		- **Graph Theory Problems**: Cluster it into the above 3 levels. List the problems.
		- **Graph Theory Ideas**: Write down every hard problem you suffered from till AC. Write a problem ABSTRACT and solution sketch.
			
	In the future, you can practice whatever you want, just open your files and target a problem.

### History Revision
	
	One of the keys to success is **History Revision**. Through it, you may do:
	
	1. **Check some hard problems** for a category, then make sure that the idea is present in your mind.
		If needed, resolve the problem. This highly improves your level.
		
	2. **Think about improvement for code & idea.**	
		Many times a problem could be solved in many ways and written in many ways.	
		
	3. **Connecting Ideas.**
		When you revise abstracted problems in one of the categories and sketched solutions, try to think about idea relations.
		Even, try to think across categories. You could connect something from DP to a solution in max flow.
		Generally, when you learn something new, think about how it is connected to everything you learned! 
		
	4. **From experience to knowledge:**
		Typically, we study and then practice so we gain experience.
		It is very powerful to try to reorganize the experience into a knowledge format again.
		Two benefits for that: 
			1) You don't either lose the experience due to solving a lot, or feel messy due to lots of notes about problems.
			2) When learning new generations: You transfer basic knowledge + knowledge from experience -> Then they work on higher challenges.
				
		As an example, when you read textbooks for dynamic programming, you may read about 4 problems that represent 2 recurrence styles.
		When you solve, you will discover dozens of recurrences and challenges. Convert them as knowledge.

--------------------------------------------------Contest Strategy--------------------------------------

As a contestant, we should have discipline in tackling a problem.
	Teams too should have discipline in behavior.
		Every team should realize its skills, develop a strategy, and practice it.

E.g., the following is a **TerminalManStrategy** - one of the dozen strategies to try.
> Note: This was my team strategy in Regionals 2010.  
> TerminalManStrategy means the fast member (e.g. Meeda) is on PC and others are thinking and preparing stuff for him.  
> We used this plan to utilize the special skills in the team.

1. **Meeda** will set up the environment and write the template.
2. **Mostafa** will sort the problems, give a problem to Yasser, and read another one.
3. The team should manage reading all problems within the **1st hour**, and discussing all problems (except n+1's) within another **30 minutes**.
4. If **Mostafa** or **Yasser** finds an **ace** before Meeda finishes, they will give it to **Meeda** to solve.
5. If **Meeda** finishes before finding an ace, he will take the next problem to read.
6. **Mostafa** and **Yasser** will be thinking, and if they get a solution for a problem, they will add it to **Meeda's queue**.
7. Everyone should **estimate the size of code & time carefully** as much as possible.
8. **Meeda should utilize the scoreboard** as the main guide for solving problems, and in case of a tie, work on the shortest first.
9. Before writing any problem, **Meeda should read the problem statement, input, and output sections again**.
10. If **Meeda** finishes writing a problem, **Mostafa** or **Yasser** will join him to review his code and put some corner cases.
11. **Yasser pipeline** if: 
    - Meeda got stuck in a problem, or  
    - Other teams can beat our score in case of a tie in problems.
12. Once **Meeda's queue is empty**, he joins the team and works in **pair style** or **triple in the last 1.5 hours**.
13. **Yasser and Mostafa** keep working to sketch problem solutions until discovering **n+1's problems**.
14. **Yasser and Mostafa** work hard to find the easiest **n+1**, write its code & revise it very well.
15. Once **Meeda** finishes all medium problems, the **whole team** works on writing the **n+1 problem together**.
16. After **each hour**, a **break-point** is done to check team status and other teams' scores & accepted problems.

### In Case of WA Status:
1. **Fast revision** for:
   - Corner Cases
   - Limits
   - Output Format (may be the original reader of the problem joins that) **[10 Min]**.
2. If no bugs, and **if a Stress Test is effective, DO IT**. **[Max 10 min]**.
3. The **original reader of the problem should get a printed copy and debug**, while **Meeda navigates to the next** **[10 Min]**.
4. If no bugs, **pend the problem**, and later, the **3rd member** may debug the code or rewrite it from scratch.

### Notes:
- Don't let a problem **kill the team's time**.