// raider Notes Below

#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long double ld;
typedef vector<int> vi;
typedef vector<double> vd;
typedef vector< vi > vvi;
typedef vector< vd > vvd;
typedef vector<string> vs;

// Constants
const double EPS = 1e-7;
const int OO = (int)1e6; // A value representing "infinity" for unreachable nodes
const int MAX = 20;      // Maximum number of nodes in the graph
int adj[MAX][MAX];       // Adjacency matrix for the graph
int dp[MAX + 1][MAX][MAX]; // 3D DP array for floyd1 memoization
int n; // Number of nodes in the graph

// Floating point comparison
int dcmp(double x, double y) {
    return fabs(x - y) <= EPS ? 0 : x < y ? -1 : 1;
}

// Initializes the adjacency matrix with proper base values
void initializeAdjMatrix() {
    for (int i = 0; i < n; ++i)
        for (int j = 0; j < n; ++j)
            adj[i][j] = (i == j ? 0 : OO); // 0 for self-loops, OO otherwise
}

/*
 * Recursive shortest path function (inefficient)
 * This version doesn't handle cycles well and lacks memoization.
 */
int shortestPath(int i, int j) {
    int mn = adj[i][j];

    for (int k = 0; k < n; ++k) if (k != i && k != j)
        mn = min(mn, shortestPath(i, k) + shortestPath(k, j));

    return mn;
}

/*
 * Recursive Floyd-Warshall implementation
 * Base case: when k == 0, return direct edge cost
 * Recurrence: decide whether to use k-th node in the path or not
 */
int floyd(int i, int j, int k) {
    if (k == 0)
        return adj[i][j];

    return min(floyd(i, j, k - 1), floyd(i, k, k - 1) + floyd(k, j, k - 1));
}

/*
 * Floyd-Warshall with full memoization (O(n^3) time and space)
 * dp[k][i][j] stores shortest path from i to j using nodes [0..k]
 */
void floyd1() {
    for (int k = 0; k <= n; ++k)
        for (int i = 0; i < n; ++i)
            for (int j = 0; j < n; ++j)
                dp[k][i][j] = OO; // initialize all to infinity

    for (int i = 0; i < n; ++i)
        for (int j = 0; j < n; ++j)
            dp[0][i][j] = adj[i][j]; // base case

    for (int k = 0; k < n; ++k)
        for (int i = 0; i < n; ++i)
            for (int j = 0; j < n; ++j)
                if (dp[k][i][k] < OO && dp[k][k][j] < OO)
                    dp[k + 1][i][j] = min(dp[k][i][j], dp[k][i][k] + dp[k][k][j]);
}

/*
 * Optimized Floyd-Warshall (in-place, O(n^3) time, O(1) extra space)
 * Updates the adjacency matrix directly
 */
void floyd2() {
    for (int k = 0; k < n; ++k)
        for (int i = 0; i < n; ++i)
            for (int j = 0; j < n; ++j)
                if (adj[i][k] < OO && adj[k][j] < OO)
                    adj[i][j] = min(adj[i][j], adj[i][k] + adj[k][j]);
}

/*
 * Transitive Closure using Floyd-Warshall
 * Converts adjacency matrix to binary reachability matrix
 */
void TransitiveClosure() {
    for (int i = 0; i < n; ++i)
        for (int j = 0; j < n; ++j)
            adj[i][j] = (adj[i][j] ? 1 : 0); // convert to boolean

    for (int k = 0; k < n; ++k)
        for (int i = 0; i < n; ++i)
            for (int j = 0; j < n; ++j)
                adj[i][j] |= (adj[i][k] & adj[k][j]);
}

// We treat adj[i][j] == 0 as no edge between nodes i and j.

/* Minimax path: path where the largest edge is minimized */
void minimax() {
    for (int i = 0; i < n; ++i)
        for (int j = 0; j < n; ++j)
            if (i != j && adj[i][j] == 0)
                adj[i][j] = OO;

    for (int k = 0; k < n; ++k)
        for (int i = 0; i < n; ++i)
            for (int j = 0; j < n; ++j)
                adj[i][j] = min(adj[i][j], max(adj[i][k], adj[k][j]));
}

/* Maximin path: path where the smallest edge is maximized */
void maximin() {
    for (int i = 0; i < n; ++i)
        for (int j = 0; j < n; ++j)
            if (i != j && adj[i][j] == 0)
                adj[i][j] = -OO;

    for (int k = 0; k < n; ++k)
        for (int i = 0; i < n; ++i)
            for (int j = 0; j < n; ++j)
                adj[i][j] = max(adj[i][j], min(adj[i][k], adj[k][j]));
}

/* Longest Path in a DAG (use with topological sort in DAGs) */
void longestPathDAG() {
	// Initialize non-existing edges to -OO
	for (int i = 0; i < n; ++i)
			for (int j = 0; j < n; ++j)
					if (i != j && adj[i][j] == 0)
							adj[i][j] = -OO;

	// Floyd-style triple loop for longest paths
	for (int k = 0; k < n; ++k)
			for (int i = 0; i < n; ++i)
					for (int j = 0; j < n; ++j)
							if (adj[i][k] > -OO && adj[k][j] > -OO)
									adj[i][j] = max(adj[i][j], adj[i][k] + adj[k][j]);
}


/* Count number of paths between all pairs of nodes */
void countPaths() {
    // Make sure matrix is properly initialized for counting
    for (int i = 0; i < n; ++i)
        for (int j = 0; j < n; ++j)
            if (i != j && adj[i][j] == 0)
                adj[i][j] = 0;

    for (int k = 0; k < n; ++k)
        for (int i = 0; i < n; ++i)
            for (int j = 0; j < n; ++j)
                adj[i][j] += adj[i][k] * adj[k][j];
}

/* Checks if there exists any negative weight cycle */
bool isNegativeCycle() {
    for (int i = 0; i < n; ++i)
        if (adj[i][i] < 0)
            return true;
    return false;
		// Checks if there's a node i with adj[i][i] < 0, meaning a negative cycle exists (cost to reach itself became negative).
}

/* Check if a negative cycle affects a specific source to destination path */
bool anyEffectiveCycle(int src, int dest) {
    for (int i = 0; i < n; ++i)
        if (adj[i][i] < 0 && adj[src][i] < OO && adj[i][dest] < OO)
            return true;
    return false;
}

/* Returns the longest shortest-path in the graph */
int graphDiameter() {
    floyd2(); // Ensure all-pairs shortest paths are computed
    int mx = 0;
    for (int i = 0; i < n; ++i)
        for (int j = 0; j < n; ++j)
            if (adj[i][j] < OO)
                mx = max(mx, adj[i][j]);
    return mx;
}

/* Strongly Connected Components using connectivity */
vector<vector<int>> SCC() {
		floyd2(); 
    vector<int> comp(n, -1);
    int cnt = 0;
    for (int i = 0; i < n; ++i) if (comp[i] == -1) {
        comp[i] = cnt++;
        for (int j = 0; j < n; ++j)
            if (adj[i][j] < OO && adj[j][i] < OO)
                comp[j] = comp[i];
    }

		// compGraph[u][v] = 1 means there's a directed edge from component u to component v.
    vector<vector<int>> compGraph(cnt, vector<int>(cnt));
    for (int i = 0; i < n; ++i)
        for (int j = 0; j < n; ++j)
            if (adj[i][j] < OO)
                compGraph[comp[i]][comp[j]] = 1;

    return compGraph;
}

int main() {
#ifndef ONLINE_JUDGE
    freopen("c.in", "rt", stdin);
#endif
    return 0;
}



// Mustafa Saad Notes Below

#include<bits/stdc++.h>
using namespace std;

#define all(v)				((v).begin()), ((v).end())
#define sz(v)				((int)((v).size()))
#define clr(v, d)			memset(v, d, sizeof(v))
#define rep(i, v)		for(int i=0;i<sz(v);++i)
#define lp(i, n)		for(int i=0;i<(int)(n);++i)
#define lpi(i, j, n)	for(int i=(j);i<(int)(n);++i)
#define lpd(i, j, n)	for(int i=(j);i>=(int)(n);--i)

typedef long long         ll;

const double EPS = (1e-7);
int dcmp(double x, double y) {	return fabs(x-y) <= EPS ? 0 : x < y ? -1 : 1;	}

#define pb					push_back
#define MP					make_pair
#define P(x)				cout<<#x<<" = { "<<x<<" }\n"
typedef long double   	  ld;
typedef vector<int>       vi;
typedef vector<double>    vd;
typedef vector< vi >      vvi;
typedef vector< vd >      vvd;
typedef vector<string>    vs;



const int OO = (int)1e6;

const int MAX = 20;
int adj[MAX][MAX];
int dp[MAX+1][MAX][MAX];
int n;








/*
 * Single source Shortest path
 * All Pairs Shortest path
 */














int shortestPath(int i, int j)	// cyclic recurrence
{
	int mn = adj[i][j];

	for(int k = 0; k < n; ++k) if(k != i && k != j)
		mn = min(mn, shortestPath(i, k) + shortestPath(k, j));

	return mn;
}










int floyd(int i, int j, int k)	// Recurrence redefinition
{
	if(k == 0)
		return adj[i][j];

	return min(floyd(i, j, k-1), floyd(i, k, k-1) + floyd(k, j, k-1));
}












// This is memoized in O(n^3)

void floyd1()
{
	lp(i, n) lp(j, n)
		dp[0][i][j] = adj[i][j];

	lp(k, n) lp(i, n) lp(j, n)
		if(dp[k][i][k] < OO && dp[k][k][j] < OO)
			dp[k+1][i][j] = min(dp[k+1][i][j], dp[k][i][k]+dp[k][k][j]);

	// dp[n] is the shortest path 2d array
}
























void floyd2()
{
	// 0 - Infinity MUST be larger than any path. Say we have n = 1000, and cost of edge max 5000, then min OO to = (1000-1) * 5000 + 1
	// 1- Set whole array to infinity:
	// 2- read input edges
	// 3- set diagonal to zeros: sometimes, if negative input you would like to leave them: e.g. adj[3][3] = -7 -> a self cycle

	// k: Incrementally add new node and update matrix
	lp(k, n) lp(i, n) lp(j, n)
		if(adj[i][k] < OO && adj[k][j] < OO)	// you could remove this line IFF 2*OO fit in the data type.
			adj[i][j] = min(adj[i][j], adj[i][k]+adj[k][j]);

	// an order lp(i, n) lp(j, n) lp(k, n)		is wrong translation

	// What if we need to get the path? 2 ways

	// Define path arr, initialize it to -1, which means direct
	// If path (i, j) has intermediate node k, then path[i][j] = k; means path from i to j pass with k
	// Write a recursive function be like:
	/*
	 void build_path(int src, int dest)
	{
		if( path[src][dest] == -1 )	//So this is the last way
		{
			// print
			return;
		}
		build_path( src, path[src][dest]);
		build_path( path[src][dest], dest);
	}
	 */

	// Other way is through previous of path: prev[i][j]: last node before j from i to j
	// Initialize repv[i][j] = i
	// If path (i, j) has intermediate node k, then prev[i][j] = prev[k][j];
	// Write a recursive function be like:
	/*
	 void printPath(int i, int j)
	 {
		if (i != j)
			printPath(i, prev[i][j]);
		printf(" %d", j);
	}
	*/
}
















void TransitiveClosure()
{
	// assume matrix is 0 for disconnect, 1 is connect
	// we only care if a path exist or not, not a shortest path value

	lp(k, n) lp(i, n) lp(j, n)
		adj[i][j] |= (adj[i][k] & adj[k][j]);
}

void minimax()
{
	// find path such that max value on road is minimum

	lp(k, n) lp(i, n) lp(j, n)
		adj[i][j] = min(adj[i][j], max(adj[i][k], adj[k][j]) );
}

void maximin()
{
	// find path such that min value on road is maximum

	lp(k, n) lp(i, n) lp(j, n)
		adj[i][j] = max(adj[i][j], min(adj[i][k], adj[k][j]) );
}

void longestPathDAG()
{
	lp(k, n) lp(i, n) lp(j, n)
		adj[i][j] = max(adj[i][j], max(adj[i][k], adj[k][j]) );
}

void countPaths()
{
	lp(k, n) lp(i, n) lp(j, n) 	// Floyd warshal for counting #of paths
		adj[i][j] += adj[i][k] * adj[k][j];

	// 1- assume graph is DAG
	/*
	 * k = 5, i = 1, j = 2 we will use adj[ 1 ][ 5 ] with old value
	 * k = 5, i = 1, j = 5 we will update adj[ 1 ] [ 5 ]
	 * k = 5, i = 1, j = 7 we will use adj[ 1 ][ 5 ] with new value
	 * Won't this give and incorrect result?
	 *
	 * NO. E.g. when k = 5, i = 1, j = 5:
	 * adj[1][5] += adj[1][5] * adj[5][5];
	 * adj[5][5] = 0, so no update happens. In general, when k = i or j, no updates happens, so in-placement update is fine.
	 */

	/*
	 * What if graph is not DAG.
	 * if(adj[i][i] > 0)	-> i has a cycle path on it
	 *
	 * Generally, for any node v that has a cycle,
	 * 		if i reaches v, and v reaches j, then count of (i, j) is useless as count is OO. Remain adj[][] is valid
	 */

}










/*
 * . If you had a cycle in a graph, the longest path wouldn't be
well defined, because you could keep going round and round the cycle
making the path longer.
 */

bool isNegativeCycle() {
	lp(i, n)
		if(adj[i][i] < 0)
			return true;	// then node i got to i with overall cost < 0.

	return false;
}

bool anyEffectiveCycle(int src, int dest)
{
	lp(i, n)
		if(adj[i][i] < 0 && adj[src][i] < OO && adj[i][dest] < OO)
			return true;

	return false;	// there is a finite path although cycles if any
}


























/*
 * Graph negative:
 * 	Shortest <-> Longest
 * 	Postive Cycle <-> Negative Cycle
 * 	Minimax <-> Maximin
 */























int graphDiameter()
{	// Longest path among all shortest ones

	floyd2();

	int mx = 0;
	lp(i, n) lp(j, n) if(adj[i][j] < OO)
		mx = max(mx, adj[i][j]);

	return mx;
}















vector< vector<int> > SCC()
{
	vector<int> comp(n, -1);

	int cnt = 0;
	lp(i, n) if(comp[i]==-1) {
		comp[i] = cnt++;
		lp(j, n) if(adj[i][j] < OO && adj[j][i] < OO)	// transitive clusre is enough
			comp[j] = comp[i];
	}

	vector< vector<int> > compGraph(cnt, vector<int>(cnt));

	lp(i, n) lp(j, n)	if(adj[i][j] < OO)
		compGraph[ comp[i] ][ comp[j] ] = 1;	// DAG

	return compGraph;
}




















int main()
{
#ifndef ONLINE_JUDGE
	freopen("c.in", "rt", stdin);
	//freopen(".txt", "wt", stdout);
#endif

	return 0;
}
