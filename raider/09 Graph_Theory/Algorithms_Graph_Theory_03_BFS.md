Below is a Markdown file structure that you can use to explain the BFS algorithms to your students. The complete code is provided in a code block, followed by detailed explanations for each part.

---

# Breadth-First Search (BFS) Algorithms in C++

This document explains several variations of the BFS algorithm implemented in C++ for graph problems. It covers:

- Basic BFS for computing distances.
- Level-by-level BFS (BFS2).
- BFS for finding the shortest path between two nodes (BFSPath).

The code is written in a competitive programming style using macros and helper functions.

---

## Table of Contents

1. [Introduction](#introduction)
2. [Preliminaries and Macros](#preliminaries-and-macros)
3. [BFS Variants](#bfs-variants)
   - [BFS: Compute Distances](#bfs--compute-distances)
   - [BFS2: Level-by-Level BFS](#bfs2--level-by-level-bfs)
   - [BFSPath: Shortest Path Reconstruction](#bfspath--shortest-path-reconstruction)
4. [Main Function and Graph Input](#main-function-and-graph-input)
5. [Conclusion](#conclusion)
6. [References](#references)

---

## Introduction

Breadth-First Search (BFS) is a fundamental graph traversal algorithm used to compute the shortest path in an unweighted graph, determine distances from a source node, and solve various other graph problems. This document demonstrates three BFS functions:

- **BFS:** Returns a vector of distances from a source node.
- **BFS2:** An alternative implementation using a level-by-level loop.
- **BFSPath:** Finds and reconstructs the shortest path between two nodes.

---

## Preliminaries and Macros

The code uses several macros and type definitions to simplify common tasks. These include macros for iterating through vectors and shortcuts for common functions.

```cpp
#include<bits/stdc++.h>
using namespace std;

#define all(v)             ((v).begin()), ((v).end())
#define sz(v)              ((int)((v).size()))
#define clr(v, d)          memset(v, d, sizeof(v))
#define rep(i, v)          for(int i=0;i<sz(v);++i)
#define lp(i, n)           for(int i=0;i<(int)(n);++i)
#define lpi(i, j, n)       for(int i=(j);i<(int)(n);++i)
#define lpd(i, j, n)       for(int i=(j);i>=(int)(n);--i)

typedef long long         ll;
const int OO = (int)1e6;
const double EPS = (1e-7);
int dcmp(double x, double y) { return fabs(x-y) <= EPS ? 0 : x < y ? -1 : 1; }

#define pb                  push_back
#define MP                  make_pair
#define P(x)                cout<<#x<<" = { "<<x<<" }\n"
typedef long double       ld;
typedef vector<int>       vi;
typedef vector<double>    vd;
typedef vector< vi >      vvi;
typedef vector< vd >      vvd;
typedef vector<string>    vs;
```

### Explanation

- **Macros:**  
  Simplify operations such as iterating through vectors (`rep`, `lp`, etc.) and working with containers (`all`, `sz`).
- **Constants and Types:**  
  `OO` is used to represent a large number (infinity), and custom types are defined for ease of use.

---

## BFS Variants

### BFS: Compute Distances

The `BFS` function computes the shortest distance from a source node `s` to all other nodes in the graph represented by an adjacency list.

```cpp
vector<int> BFS(int s, vector<vector<int> > & adjList) {
    vector<int> len(sz(adjList), OO);
    queue< pair<int, int> > q;
    q.push(MP(s, 0)), len[s] = 0;

    int cur, dep;
    while(!q.empty()) {
        pair<int, int> p = q.front();   q.pop();
        cur = p.first, dep = p.second;

        rep(i, adjList[cur]) if (len[adjList[cur][i]] == OO)
            q.push(MP(adjList[cur][i], dep+1)), len[adjList[cur][i]] = dep+1;
    }

    return len; // 'len' contains distances from node s.
}
```

#### Explanation

- **Initialization:**  
  The distance vector `len` is initialized with a large value (`OO`), and the source node `s` is set to distance 0.
- **Queue:**  
  A queue stores pairs of nodes and their current distance.
- **BFS Loop:**  
  The algorithm processes nodes level by level, updating distances for unvisited neighbors.
- **Return:**  
  It returns the vector of distances.

---

### BFS2: Level-by-Level BFS

The `BFS2` function is a variation that processes nodes in a level-order manner using a for-loop and the queue’s size to determine levels.

```cpp
vector<int> BFS2(int s, vector<vector<int> > & adjList) {
    vector<int> len(sz(adjList), OO);
    queue<int> q;
    q.push(s), len[s] = 0;

    int dep = 0, cur = s, sz = 1;
    for (; !q.empty(); ++dep, sz = q.size()) {
        while (sz--) {
            cur = q.front(), q.pop();
            rep(i, adjList[cur]) if (len[adjList[cur][i]] == OO)
                q.push(adjList[cur][i]), len[adjList[cur][i]] = dep+1;
        }
    }
    return len; // 'len' contains the distances.
}
```

#### Explanation

- **Level Processing:**  
  Instead of processing one node at a time, this function processes all nodes at the current depth (`dep`) by using the size of the queue.
- **Advancing Levels:**  
  After processing all nodes at the current level, the depth is incremented.
- **Return:**  
  Returns the vector of distances from the source.

---

### BFSPath: Shortest Path Reconstruction

The `BFSPath` function finds the shortest path from a source `s` to a destination `d` and reconstructs that path.

```cpp
vector<int> BFSPath(int s, int d, vector<vector<int> > & adjList) {
    vector<int> len(sz(adjList), OO);
    vector<int> par(sz(adjList), -1);
    queue<int> q;
    q.push(s), len[s] = 0;

    int dep = 0, cur = s, sz = 1;
    bool ok = true;

    for ( ; ok &&  !q.empty();  ++dep, sz = q.size()) {
        while (ok && sz--) {
            cur = q.front(), q.pop();
            rep(i, adjList[cur]) if (len[adjList[cur][i]] == OO)
            {
                q.push(adjList[cur][i]), len[adjList[cur][i]] = dep+1, par[ adjList[cur][i] ] = cur;

                if(adjList[cur][i] == d) { // Found target, stop BFS.
                    ok = false;
                    break;
                }
            }
        }
    }

    vector<int> path;
    while(d != -1) {
        path.push_back(d);
        d = par[d];
    }

    reverse(all(path));
    return path;
}
```

#### Explanation

- **Parent Array:**  
  The `par` array keeps track of each node's parent to allow path reconstruction.
- **Target Check:**  
  When the destination node `d` is encountered, the loop breaks.
- **Path Reconstruction:**  
  Starting from the destination, the parent links are followed back to the source, and the path is reversed.
- **Return:**  
  Returns the shortest path as a vector of node indices.

---

## Main Function and Graph Input

The `main()` function demonstrates how to read a graph, call the BFSPath function, and output the resulting path.

```cpp
int main()
{
#ifndef ONLINE_JUDGE
    freopen("c.in", "rt", stdin);
    //freopen(".txt", "wt", stdout);
#endif

    int n, e;
    cin >> n >> e;

    vector<vector<int> > adj(n);
    lp(i, e) {
        int from, to;
        cin >> from >> to;
        adj[from-1].push_back(to-1);
    }

    vector<int> p = BFSPath(0, 4, adj);
    rep(i, p)
        cout << p[i]+1 << " ";

    return 0;
}
```

#### Explanation

- **Graph Input:**  
  Reads the number of nodes `n` and edges `e`, then constructs the graph using an adjacency list (converting 1-based input to 0-based indexing).
- **BFSPath Usage:**  
  Calls `BFSPath` to find the shortest path from node `0` to node `4`.
- **Output:**  
  The resulting path is printed, converting node indices back to 1-based for output.

---

## Conclusion

This code sample demonstrates various BFS algorithms:

- **BFS:** Computes distances from a source node.
- **BFS2:** Processes nodes level-by-level.
- **BFSPath:** Finds and reconstructs the shortest path between two nodes.

These functions illustrate how BFS can be used for different purposes in graph problems and are written in a style typical of competitive programming. Understanding these BFS variations is essential for solving shortest path and connectivity problems efficiently.

---

## References

- [Breadth-First Search – Wikipedia](https://en.wikipedia.org/wiki/Breadth-first_search)
- [Shortest Path Algorithms](https://en.wikipedia.org/wiki/Shortest_path_problem)
- [Competitive Programming Resources](https://www.spoj.com/)

---

This Markdown document provides a clear and organized explanation to help students understand the code and the underlying BFS concepts. Feel free to modify or expand it as needed for your teaching sessions.