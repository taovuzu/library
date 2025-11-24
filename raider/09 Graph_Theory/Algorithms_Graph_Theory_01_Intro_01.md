## 1. Overview

The provided code demonstrates several common ways to represent graphs in C++ for algorithmic problems and competitive programming. It shows how to use:

- **Adjacency Matrices:**  
  - Boolean matrices for simple connectivity.
  - Integer matrices for weighted graphs.
  - Extended structures to store multiple edges.

- **Map-Based Representation:**  
  Useful for sparse graphs where the number of nodes is large but edges are few.

- **Adjacency Lists:**  
  - A basic list for unweighted (or boolean) relationships.
  - A list with pairs to represent weighted edges.

- **Edge Lists:**  
  A simple structure to store and sort individual edges, which is useful in algorithms like Kruskal’s Minimum Spanning Tree.

---

## 2. Macros and Data Types

The code begins by defining several macros to simplify common operations:

- **Iteration Macros:**  
  - `rep(i, v)` loops through all elements of vector `v`.
  - `lp(i, n)` loops from `0` to `n-1`.
  - `lpi(i, j, n)` and `lpd(i, j, n)` handle loops with custom start and decrement.
  
- **Container Helpers:**  
  - `all(v)` expands to `v.begin(), v.end()`.
  - `sz(v)` returns the size of a vector.
  - `clr(v, d)` uses `memset` for initialization.

These shortcuts are common in competitive programming to reduce verbosity.

---

## 3. Graph Representations

### **3.1 Adjacency Matrices**

- **Boolean Matrix:**  
  `bool adjMatrixBool[N][N];`  
  This matrix stores a simple yes/no value indicating whether an edge exists between two nodes.

- **Cost Matrix:**  
  `int adjMatrix[N][N];`  
  Stores the weight (or cost) of the edge between nodes.

- **Multiple Edges:**  
  `vector<int> adjMatrixAll[N][N];`  
  This 2D array of vectors holds all edges between two nodes (useful when there are multiple edges).

### **3.2 Map Representation**

- **Sparse Graphs:**  
  `map< pair<int, int>, int> adjMatrixMap;`  
  In graphs with many nodes but few edges, a map can efficiently store only the existing edges.

### **3.3 Adjacency Lists**

- **Unweighted Graph (Boolean Relation):**  
  `vector< vector<int> > adjList1;`  
  Each node stores a vector of its neighboring nodes.

- **Weighted Graph:**  
  `vector< vector< pair<int, int> > > adjList2;`  
  Each node’s list contains pairs `(neighbor, cost)`, representing the edge weight.

### **3.4 Edge List Representation**

A simple struct to represent an edge:

```cpp
struct edge {
    int from, to, w;
    edge(int from, int to, int w): from(from), to(to), w(w) {}
    bool operator < (const edge & e) const {
        return w > e.w;  // Sort with smaller weight first.
    }
};
vector<edge> edgeList;
```

Edge lists are useful for sorting edges by weight, which is a common step in algorithms like Kruskal’s MST.

---

## 4. Input Processing Examples

The code then demonstrates how to read different graph representations from input:

### **4.1 Reading an Adjacency Matrix (Boolean)**
```cpp
int n;
cin >> n;
lp(i, n) lp(j, n) {
    int b;
    cin >> b;
    adjMatrixBool[i][j] = b;
}
```

### **4.2 Reading an Adjacency Matrix (Weighted)**
```cpp
cin >> n;
lp(i, n) lp(j, n) {
    int b;
    cin >> b;
    adjMatrix[i][j] = b;
}
```

### **4.3 Reading Edge Data and Updating an Adjacency Matrix**
```cpp
int edges;
cin >> n >> edges;
lp(i, edges) {
    int from, to, cost;
    cin >> from >> to >> cost;
    // For directed graphs, update the edge cost:
    adjMatrix[from][to] = min(adjMatrix[from][to], cost);
    // For undirected graphs, update both directions:
    adjMatrix[to][from] = adjMatrix[from][to];
}
```

### **4.4 Reading an Unweighted Adjacency List**
```cpp
cin >> n;
adjList1 = vector< vector<int> >(n);
lp(i, n) {
    int cnt;
    cin >> cnt;
    lp(j, cnt) {
        int to;
        cin >> to;
        adjList1[i].push_back(to);
    }
}
```

### **4.5 Reading a Weighted Adjacency List**
```cpp
cin >> n;
adjList2 = vector< vector< pair<int, int> > >(n);
lp(i, n) {
    int cnt;
    cin >> cnt;
    lp(j, cnt) {
        int to, cost;
        cin >> to >> cost;
        adjList2[i].push_back(make_pair(to, cost));
    }
}
```

---

## 5. Conclusion

This code provides a comprehensive overview of various graph representations in C++:

- **Adjacency Matrix:** Best for dense graphs.
- **Map Representation:** Ideal for sparse graphs with many nodes but few edges.
- **Adjacency List:** Efficient for most practical graph problems, both weighted and unweighted.
- **Edge List:** Useful for sorting and algorithms like MST.