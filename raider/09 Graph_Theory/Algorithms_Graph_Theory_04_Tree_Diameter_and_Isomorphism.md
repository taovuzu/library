# Tree Algorithms: Diameter, Isomorphism, and Canonical Forms

## Table of Contents

1. [Introduction](#introduction)
2. [Tree Diameter](#tree-diameter)
3. [Tree Canonical Form via DFS](#tree-canonical-form-via-dfs)
4. [Tree Shrinking Algorithm for Centers and Canonical Form](#tree-shrinking-algorithm-for-centers-and-canonical-form)
5. [References](#references)

---

## Introduction

- **Tree Diameter:** The longest path between any two nodes in a tree.
- **Tree Isomorphism:** Determining if two trees are structurally the same using canonical forms.
- **Tree Center:** The center(s) of a tree minimize the maximum distance to all other nodes.
- **Tree Shrinking:** A method to obtain a canonical representation by iteratively removing leaves.

---

## Tree Diameter

The `diameter` function calculates the diameter (longest path) of a tree. It returns a pair consisting of the diameter and the height of the subtree.

```cpp
#include <vector>
#include <algorithm>
#include <utility>
using namespace std;

vector< vector<int> > adjLst;

// Returns a pair: (diameter, height)
pair<int, int> diameter(int i, int par = -1)
{
    int diam = 0;
    int mxHeights[3] = {-1, -1, -1};   // To store the top 2 heights

    for (int j = 0; j < adjLst[i].size(); ++j) {
        if (adjLst[i][j] != par) {
            pair<int, int> p = diameter(adjLst[i][j], i);
            diam = max(diam, p.first);

            mxHeights[0] = p.second + 1;
            sort(mxHeights, mxHeights + 3);
        }
    }

    for (int k = 0; k < 3; ++k) {
        if (mxHeights[k] == -1)
            mxHeights[k] = 0;
    }

    diam = max(diam, mxHeights[1] + mxHeights[2]);
    return make_pair(diam, mxHeights[2]);
}
```

```cpp
/*
 	One of popular algorithms, although no formal source for proving is 2 BFS idea:

    1- Select a random node A
    2- Run BFS on this node to find furthermost node from A. name this node as S.
    3- Now run BFS starting from S, find the furthermost node from S, name it D.
    4- Path between S and D is diameter of the tree.

 */

 
 // BFS function to return the farthest node and its distance
 pair<int, int> bfs(int start, const vector<vector<int>>& graph) {
		 int n = graph.size();
		 vector<bool> visited(n, false);
		 queue<pair<int, int>> q;  // {node, distance}
		 q.push({start, 0});
		 visited[start] = true;
 
		 int farthestNode = start;
		 int maxDist = 0;
 
		 while (!q.empty()) {
				 auto [node, dist] = q.front();
				 q.pop();
 
				 if (dist > maxDist) {
						 maxDist = dist;
						 farthestNode = node;
				 }
 
				 for (int neighbor : graph[node]) {
						 if (!visited[neighbor]) {
								 visited[neighbor] = true;
								 q.push({neighbor, dist + 1});
						 }
				 }
		 }
 
		 return {farthestNode, maxDist};
 }
 
 int treeDiameter(int n, const vector<pair<int, int>>& edges) {
		 vector<vector<int>> graph(n);
 
		 // Build the adjacency list
		 for (auto& [u, v] : edges) {
				 graph[u].push_back(v);
				 graph[v].push_back(u);
		 }
 
		 // First BFS to find one endpoint of the diameter
		 int farNode = bfs(0, graph).first;
 
		 // Second BFS from that endpoint to find the diameter
		 int diameter = bfs(farNode, graph).second;
 
		 return diameter;
 }
```

---

## Tree Canonical Form via DFS

To determine if two trees are isomorphic, we can compare their canonical forms. The following function computes a canonical string for a tree rooted at node `i`.

```cpp
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

string treeCanonicalForm(int i, int par)
{
    vector<string> children;

    for (int j = 0; j < adjLst[i].size(); ++j) {
        if (adjLst[i][j] != par) {
            children.push_back(treeCanonicalForm(adjLst[i][j], i));
        }
    }

    string nodeRep = "(";
    sort(children.begin(), children.end());

    for (int k = 0; k < children.size(); ++k) {
        nodeRep += children[k];
    }

    nodeRep += ")";
    return nodeRep;
}
```

---

## Tree Shrinking Algorithm for Centers and Canonical Form

This algorithm finds the tree centers (1 or 2 nodes) and produces a canonical form based on the "shrinking" of leaves.

```cpp
#include <string>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

string getNodeCanonicalForm(int v, vector< vector<string> > &subCan)
{
    string nodeRep = "(";
    sort(subCan[v].begin(), subCan[v].end());
    for (int i = 0; i < subCan[v].size(); ++i) {
        nodeRep += subCan[v][i];
    }
    nodeRep += ")";
    return nodeRep;
}

string treeCanonicalForm()
{
    int n = adjLst.size();

    queue<int> LeafNodes;
    vector<int> deg(n, -1);
    int remNodes = n;

    for (int i = 0; i < adjLst.size(); ++i) {
        if (adjLst[i].size() <= 1) {
            LeafNodes.push(i);
        } else {
            deg[i] = adjLst[i].size();
        }
    }

    vector< vector<string> > subCan(n);

    while (remNodes > 2) {
        int levelSize = LeafNodes.size();
        while (levelSize--) {
            int v = LeafNodes.front();
            LeafNodes.pop();

            string nodeRep = getNodeCanonicalForm(v, subCan);

            for (int j = 0; j < adjLst[v].size(); ++j) {
                int to = adjLst[v][j];
                subCan[to].push_back(nodeRep);
                if (--deg[to] == 1) {
                    LeafNodes.push(to);
                }
            }

            --remNodes;
        }
    }

    int v1 = LeafNodes.front(); LeafNodes.pop();
    int v2 = LeafNodes.empty() ? -1 : LeafNodes.front();

    string str1 = getNodeCanonicalForm(v1, subCan);
    string str2 = (v2 == -1) ? "" : getNodeCanonicalForm(v2, subCan);

    if (v2 == -1)
        return str1;

    subCan[v1].push_back(str2);
    subCan[v2].push_back(str1);

    return min(getNodeCanonicalForm(v1, subCan), getNodeCanonicalForm(v2, subCan));
}
```

---

## References

- [Tree Isomorphism and Canonical Forms](http://www.spoj.com/problems/TREEISO/)
- [Graph Problems on SPOJ](http://www.spoj.com/problems/TRANSL/)
- [Tree Center and Diameter](http://www.spoj.com/problems/PT07Z/)

---