The entire concept boils down to one simple, non-negotiable rule.

***

### 💡 The Trick

The one and only rule you need to remember is:

**"Going Down? Pay Your Dues."**

That's it. Before you recursively travel down from a parent node to its children for *any* reason (whether for a query or an update), you **must** first push the parent's lazy value down to its children.

***

### 🗣️ The Quote

To remember the philosophy of being lazy vs. the necessity of pushing:

**"Be lazy as long as you can, but always pay your debts before asking for more."**

* **"Be lazy as long as you can..."**: When an update covers a node's entire range, just tag the node and stop. Don't go down.
* **"...but always pay your debts before asking for more."**: When you need to go deeper into that node's children (asking for more information), you must first resolve your tag (pay your debt) by pushing it down.

***

### 🏗️ The Framework (The Mental Algorithm)

For any recursive function (`query` or `range_update`) that travels down the tree, the structure is always the same.

Let's say you are at a `currentNode`.

1.  **(Pay Your Dues) PUSH:**
    * **Check `currentNode` for a lazy tag.** If it has one, apply the update to its immediate children. Pass the lazy tag down to them (they might need to pass it further later).
    * Clear the lazy tag on `currentNode`.
    * This is the `push()` function. **It is the very first thing you do.**

2.  **(Check Overlap) ACT:** Now that the lazy values are cleared for this level, proceed as usual.
    * **No Overlap:** The current node's range is completely outside your target range. Return immediately.
    * **Full Overlap:** The current node's range is completely inside your target range.
        * If it's an **update**, apply the new update to `currentNode` with a **lazy tag** and return. **Do not go down further.** (This is the "be lazy" part).
        * If it's a **query**, return the value stored in `currentNode`. **Do not go down further.**
    * **Partial Overlap:** The current node's range partially overlaps your target range.
        * Recursively call the function on the left child.
        * Recursively call the function on the right child.
        * Combine their results and update `currentNode`'s value.



This framework applies to both `update` and `query` functions. The only difference is what you do in the "Full Overlap" case.

***

Of course. Here is a simple and heavily commented C++ implementation for a **Range Sum** lazy segment tree that supports **Range Add** updates.

This code directly follows the framework we discussed. Pay close attention to the comments, especially where the `"Going Down? Pay Your Dues"` rule is applied.

### The Problem

We have an array, and we want to perform two operations:

1.  `update(L, R, val)`: Add `val` to every element in the range `[L, R]`.
2.  `query(L, R)`: Find the sum of all elements in the range `[L, R]`.

-----

### C++ Implementation

```cpp
#include <iostream>
#include <vector>

using namespace std;

const int MAXN = 100005;

// The array that stores the segment tree's sums
long long tree[4 * MAXN];

// The array that stores the lazy updates (the "sticky notes")
long long lazy[4 * MAXN];

// The initial array of numbers
int arr[MAXN];

/**
 * @brief Builds the segment tree from the initial array.
 * This is a standard segment tree build function. No lazy logic here.
 * @param node The index of the current node in the 'tree' array.
 * @param start The starting index of the range this node represents.
 * @param end The ending index of the range this node represents.
 */
void build(int node, int start, int end) {
    if (start == end) {
        // Leaf node: store the single element's value
        tree[node] = arr[start];
        return;
    }
    int mid = (start + end) / 2;
    // Recurse on the left and right children
    build(2 * node, start, mid);
    build(2 * node + 1, mid + 1, end);
    // Internal node's value is the sum of its children
    tree[node] = tree[2 * node] + tree[2 * node + 1];
}


/**
 * @brief Pushes the lazy update from a parent node to its children.
 * This is the "Pay Your Dues" function.
 * @param node The index of the current (parent) node.
 * @param start The starting index of the parent node's range.
 * @param end The ending index of the parent node's range.
 */
void push(int node, int start, int end) {
    // If there's no pending update for this node, do nothing.
    if (lazy[node] == 0) {
        return;
    }

    // Apply the lazy update to the current node's value.
    // The sum increases by (value_to_add * number_of_elements_in_range).
    tree[node] += (long long)(end - start + 1) * lazy[node];

    // If it's not a leaf node, pass the lazy update down to its children.
    if (start != end) {
        lazy[2 * node] += lazy[node];
        lazy[2 * node + 1] += lazy[node];
    }

    // Clear the lazy update for the current node as it has been processed.
    lazy[node] = 0;
}


/**
 * @brief Updates a range [l, r] with a given value.
 * @param node Current node index.
 * @param start Start of current node's range.
 * @param end End of current node's range.
 * @param l Start of the update range.
 * @param r End of the update range.
 * @param val The value to add to the range.
 */
void updateRange(int node, int start, int end, int l, int r, int val) {
    // 💡 STEP 1: (Pay Your Dues) PUSH!
    // Before doing anything, process any pending updates for the current node.
    push(node, start, end);

    // STEP 2: (Check Overlap) ACT
    // Case 1: No Overlap
    // The current node's range is completely outside the target range. Do nothing.
    if (start > end || start > r || end < l) {
        return;
    }

    // Case 2: Full Overlap
    // The current node's range is completely inside the target range.
    if (l <= start && end <= r) {
        // Be lazy! Apply the update to this node and mark its children.
        tree[node] += (long long)(end - start + 1) * val;
        
        // If not a leaf, pass the update value to children's lazy array.
        if (start != end) {
            lazy[2 * node] += val;
            lazy[2 * node + 1] += val;
        }
        return;
    }

    // Case 3: Partial Overlap
    // The current node's range partially overlaps with the target range.
    // Recurse on children.
    int mid = (start + end) / 2;
    updateRange(2 * node, start, mid, l, r, val);
    updateRange(2 * node + 1, mid + 1, end, l, r, val);

    // After recursion, update the current node's sum based on its children's updated sums.
    tree[node] = tree[2 * node] + tree[2 * node + 1];
}


/**
 * @brief Queries the sum of a range [l, r].
 * @param node Current node index.
 * @param start Start of current node's range.
 * @param end End of current node's range.
 * @param l Start of the query range.
 * @param r End of the query range.
 * @return The sum of the elements in the range [l, r].
 */
long long queryRange(int node, int start, int end, int l, int r) {
    // 💡 STEP 1: (Pay Your Dues) PUSH!
    // Before querying, ensure the current node's value is up-to-date.
    push(node, start, end);

    // STEP 2: (Check Overlap) ACT
    // Case 1: No Overlap
    if (start > end || start > r || end < l) {
        return 0; // Return 0 as it contributes nothing to the sum.
    }

    // Case 2: Full Overlap
    // The current node's value is now correct (thanks to push), so we can return it.
    if (l <= start && end <= r) {
        return tree[node];
    }

    // Case 3: Partial Overlap
    // Recurse on children and add their results.
    int mid = (start + end) / 2;
    long long p1 = queryRange(2 * node, start, mid, l, r);
    long long p2 = queryRange(2 * node + 1, mid + 1, end, l, r);
    
    return (p1 + p2);
}


int main() {
    // Example usage
    int n = 8;
    int initial_arr[] = {0, 1, 2, 3, 4, 5, 6, 7, 8}; // Using 1-based indexing for arr
    for(int i = 1; i <= n; ++i) arr[i] = initial_arr[i];

    // Build the tree for the range 1 to n
    build(1, 1, n);

    cout << "Initial array sum for range [1, 5]: " << queryRange(1, 1, n, 1, 5) << endl; // 1+2+3+4+5 = 15

    // Add 10 to every element in the range [2, 5]
    // arr becomes: 1, 12, 13, 14, 15, 6, 7, 8
    cout << "Adding 10 to range [2, 5]..." << endl;
    updateRange(1, 1, n, 2, 5, 10);

    cout << "New sum for range [1, 5]: " << queryRange(1, 1, n, 1, 5) << endl; // 1 + 12+13+14+15 = 55
    cout << "New sum for range [3, 4]: " << queryRange(1, 1, n, 3, 4) << endl; // 13+14 = 27
    cout << "New sum for range [5, 8]: " << queryRange(1, 1, n, 5, 8) << endl; // 15+6+7+8 = 36

    return 0;
}
```

### How to Understand the Code

1.  **`build`**: This is standard. It just sets up the tree with the initial sums. `lazy` array is all zeros here.
2.  **`push`**: This is the key. Notice it first applies the `lazy[node]` value to `tree[node]`, and *then* passes the `lazy[node]` value down to its children `lazy[2*node]` and `lazy[2*node+1]`. Finally, it clears its own `lazy[node]`, signifying its "debt is paid".
3.  **`updateRange` and `queryRange`**: Look at the very first line of both functions. It's `push(node, start, end)`. This is the rule in action. Before we do *any* logic (no overlap, full overlap, partial overlap), we first ensure the current node is up-to-date by paying its dues. The rest of the logic then works with correct values.