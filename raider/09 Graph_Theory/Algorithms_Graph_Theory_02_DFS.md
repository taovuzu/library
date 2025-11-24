Below is a Markdown file structure that explains the code to your students. The code is included exactly as provided, followed by detailed section-by-section explanations.

---

# Graph Algorithms: DFS for Cycle Detection and Flood Fill

This document explains key graph traversal techniques using Depth-First Search (DFS) for cycle detection (via edge classification) and for flood fill (to count connected components). The code is written in a competitive programming style and uses various macros to simplify operations.

---

## Table of Contents

1. [Introduction](#introduction)
2. [Preliminaries and Global Setup](#preliminaries-and-global-setup)
3. [DFS for Cycle Detection](#dfs-for-cycle-detection)
4. [Flood Fill for Connected Components](#flood-fill-for-connected-components)
5. [Main Function and Input Processing](#main-function-and-input-processing)
6. [Conclusion](#conclusion)
7. [References](#references)

---

## Introduction

In this code sample, we demonstrate:
- **DFS Traversal:** Standard DFS for exploring a graph and obtaining a topological sort.
- **Edge Classification:** Using DFS to classify edges and detect cycles in a directed graph.
- **Flood Fill:** A recursive algorithm to count reachable cells in a maze (i.e., connected components).

These techniques are essential for many graph problems in competitive programming.

---

## Preliminaries and Global Setup

The code begins by including standard libraries and defining several macros and types that simplify the code. Global arrays and variables are also declared for managing the graph and DFS state.

```cpp
#include<bits/stdc++.h>
using namespace std;

#define all(v)              ((v).begin()), ((v).end())
#define sz(v)               ((int)((v).size()))
#define clr(v, d)           memset(v, d, sizeof(v))
#define rep(i, v)           for(int i=0;i<sz(v);++i)
#define lp(i, n)            for(int i=0;i<(int)(n);++i)
#define lpi(i, j, n)        for(int i=(j);i<(int)(n);++i)
#define lpd(i, j, n)        for(int i=(j);i>=(int)(n);--i)

typedef long long         ll;
const int OO = (int)1e6;
const double EPS = (1e-7);
int dcmp(double x, double y) {    return fabs(x-y) <= EPS ? 0 : x < y ? -1 : 1;   }

#define pb                  push_back
#define MP                  make_pair
#define P(x)                cout<<#x<<" = { "<<x<<" }\n"
typedef long double       ld;
typedef vector<int>       vi;
typedef vector<double>    vd;
typedef vector< vi >      vvi;
typedef vector< vd >      vvd;
typedef vector<string>    vs;

const int MAX = 100;
bool valid(int i, int j) {    return 1;   }
char maze[MAX][MAX];
bool vis[MAX][MAX];

int n, e;
vector< vector<int> > adj;
vector<bool> visited;

vector<int> topsort;
vector<int> start, finish;
bool anyCycle = 0;
int timer = 0;
```

### Explanation

- **Macros:**  
  Macros such as `all`, `sz`, `clr`, `rep`, etc., simplify iteration and container operations.
- **Global Variables:**  
  Variables for graph representation (`adj`), visitation status (`visited`), DFS start/finish times (`start`, `finish`), and cycle detection flag (`anyCycle`) are declared.
- **Constants:**  
  `OO` represents a large number used in initialization, and `MAX` is the maximum size for arrays.

---

## DFS for Cycle Detection

Two DFS functions are implemented: one for obtaining a topological sort and another for edge classification to detect cycles.

### Standard DFS (for Topological Sort)

```cpp
void dfs(int node)
{
    visited[node] = true;

    rep(i, adj[node])
    {
        int child = adj[node][i];
        if (!visited[child])    // To avoid cyclic behavior
            dfs(child);
    }

    topsort.push_back(node);    // DAG // Other way Indegree / Outdegree
}
```

#### Explanation

- **Visitation:**  
  Marks each node as visited.
- **Recursion:**  
  Recursively visits unvisited adjacent nodes.
- **Topological Order:**  
  After exploring all children, the node is added to the `topsort` vector. This is useful for Directed Acyclic Graphs (DAGs).

### DFS with Edge Classification

```cpp
void dfs_EdgeClassification(int node)
{
    start[node] = timer++;

    rep(i, adj[node])
    {
        int child = adj[node][i];
        if (start[child] == -1)    // Not visited Before. Treed Edge
            dfs_EdgeClassification(child);
        else {
            if(finish[child] == -1)// then this is ancestor that called us and waiting us to finish. Then Cycle. Back Edge
                anyCycle = 1;
            else if(start[node] < start[child])    // then you are my descendant
                ;   // Forward Edge
            else
                ;   // Cross Edge
        }
    }

    finish[node] = timer++;
}
```

#### Explanation

- **Start Time:**  
  Records when a node is first visited.
- **Edge Classification:**  
  - **Tree Edge:** When a child is visited for the first time.
  - **Back Edge:** Indicates a cycle (child visited but not finished).
  - **Forward/Cross Edges:** Distinguished by start times, though not further processed here.
- **Finish Time:**  
  Recorded after all adjacent nodes are processed.
- **Cycle Detection:**  
  The global flag `anyCycle` is set to true if a back edge (cycle) is found.

---

## Flood Fill for Connected Components

The flood fill algorithm recursively counts the number of reachable cells (connected component) in a maze.

```cpp
int cnt = 0;
void cntReachalbleCells(int r, int c)
{
    if( !valid(r, c) || maze[r][c] == 'X' || vis[r][c] == 1)
        return;       // Invalid position or block position

    vis[r][c] = 1;    // Mark as visited
    cnt++;

    // Explore the 4 neighbor cells
    cntReachalbleCells(r, c-1);
    cntReachalbleCells(r, c+1);
    cntReachalbleCells(r-1, c);
    cntReachalbleCells(r+1, c);
}
```

#### Explanation

- **Validation:**  
  Checks if the cell is valid, not blocked (i.e., not `'X'`), and not already visited.
- **Marking and Counting:**  
  Marks the cell as visited and increments the counter.
- **Recursion:**  
  Calls itself for all four neighbors (left, right, up, down) to traverse the connected component.

---

## Main Function and Input Processing

The `main()` function reads the input, builds the graph, performs DFS edge classification to detect cycles, and outputs the result.

```cpp
int main()
{
#ifndef ONLINE_JUDGE
    freopen("c.in", "rt", stdin);
    //freopen(".txt", "wt", stdout);
#endif

    cin >> n >> e;

    adj = vector< vector<int> >(n);
    visited = vector<bool>(n);
    start = vector<int>(n, -1);
    finish = vector<int>(n, -1);

    lp(i, e) {
        int from, to;
        cin >> from >> to;
        adj[from-1].push_back(to-1);
    }

    lp(i, n) if(start[i] == -1)
        dfs_EdgeClassification(i);

    cout << anyCycle;

    return 0;
}
```

#### Explanation

- **Input Reading:**  
  Reads the number of nodes (`n`) and edges (`e`), then populates the adjacency list. Node indices are converted from 1-based to 0-based.
- **Initialization:**  
  Resets visitation and DFS timing arrays.
- **Cycle Detection:**  
  Runs DFS edge classification on every unvisited node to detect cycles.  
- **Output:**  
  Outputs the boolean flag `anyCycle`, which indicates if a cycle exists (1 for true, 0 for false).

---

## Conclusion

This code demonstrates essential graph algorithms:
- **DFS for Topological Sorting and Cycle Detection:**  
  Using DFS and edge classification to identify cycles in a graph.
- **Flood Fill for Connected Components:**  
  A recursive method for counting reachable cells in a maze.
- **Input and Graph Representation:**  
  Efficiently reading a graph and processing it using 0-based indexing.

Understanding these techniques is vital for solving a variety of graph problems in competitive programming.

---

## References

- [Depth-First Search – Wikipedia](https://en.wikipedia.org/wiki/Depth-first_search)
- [Cycle Detection in Graphs](https://en.wikipedia.org/wiki/Cycle_detection)
- [Flood Fill Algorithm](https://en.wikipedia.org/wiki/Flood_fill)

---

This document can be used to present the code and its underlying concepts to students in a clear, organized manner. Feel free to expand or modify sections as needed for your teaching sessions.