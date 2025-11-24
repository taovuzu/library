/*
 * We want The Minimum M emplyee such that each employee is able to process a group of tasks
 * So simply, We need Minimum path cover of employees to cover tasks
 */

#include<set>
#include<map>
#include<iomanip>
#include<cmath>
#include<string>
#include<vector>
#include<queue>
#include<stack>
#include<numeric>
#include<sstream>
#include<iostream>
#include<algorithm>
using namespace std;

#define all(v)				((v).begin()), ((v).end())
#define sz(v)				((int)((v).size()))
#define clr(v, d)			memset(v, d, sizeof(v))
#define repit(i, c)       	for(it(c) i = (c).begin(); i != (c).end(); ++i)
#define repi(i, j, n) 		for(int i=(j);i<(int)(n);++i)
#define repd(i, j, n) 		for(int i=(j);i>=(int)(n);--i)
#define repa(v)				repi(i, 0, sz(v)) repi(j, 0, sz(v[i]))
#define rep(i, v)			repi(i, 0, sz(v))
#define lp(i, cnt)			repi(i, 0, cnt)
#define lpi(i, s, cnt)		repi(i, s, cnt)
#define P(x)				cout<<#x<<" = { "<<x<<" }\n"
#define pb					push_back

typedef vector<int>       vi;
typedef vector<double>    vd;
typedef vector<string>    vs;	
// typedef long long         ll;   // comment for PKu
typedef long double   	  ld;
const int OO = (int)1e8;	// Note, IF Small may be WRONG, Large may generate OVERFLOW

bool canMatch(vector< vi > & adjMax, vi & vis, vi & L, vi & R, int i) // O(m*n)
{
	rep(j, adjMax[i]) if(adjMax[i][j] && !vis[j]) {
		vis[j] = 1;
		if( L[j] < 0 || canMatch(adjMax, vis, L, R, L[j]) ) {
			L[j] = i, R[i] = j;
			return true;
		}
	}
	return false;
}

int bipartiteMatching(vector< vi > adjMax)
{	// Return two lists of maximum matching indices in O(m*n^2).
	int maxFlow = 0, n = sz(adjMax), m = sz(adjMax[0]);
	vi vis, L(n, -1), R(m, -1);
	lp(i, n) {
		vis = vi(n, 0);
		if( canMatch(adjMax, vis, L, R, i)  )
			maxFlow++;
	}
	// Construct the matching, 0-based.
	vector< pair<int, int> > matches;
	lp(i, n) if(R[i] != -1)
		matches.push_back( make_pair(i, R[i]) );

	return n-maxFlow;
}

void floydWarshal(vector< vi > & adjMax, int src = 0, int dest = -1)	// O(n^3)
{
	int n = sz(adjMax);
	vector< vi > prev(n);
	rep(i, prev)	prev[i] = vi(n, i);
	
	lp(k, n) lp(i, n) lp(j, n) 
	if(adjMax[i][j] > adjMax[i][k] + adjMax[k][j]) {
		adjMax[i][j] = adjMax[i][k] + adjMax[k][j];
		prev[i][j] = prev[k][j];
	}
}

int main() {
	int Q, M;
	
	while(cin>>Q>>M) {
		if(!Q && !M)	break;
		
		vector< vi > costMax = vector< vi >(Q, vi(Q));
		
		lp(i, Q) lp(j, Q)	{
			cin>>costMax[i][j];
			if(costMax[i][j] == -1)	costMax[i][j] = OO;
		}
		
		floydWarshal( costMax );
		
		vector< vi > adjMax = vector< vi >(M, vi(M, 0));
		
		vector< pair< int, pair<int, int> > > list(M);
		
		lp(i, M) {
			int p, t, d;
			cin>>p>>t>>d;
			p--;
			list[i] = make_pair(p, make_pair(t, d));
		}
		
		// Construct DAG between tasks
		rep(i, list) {
			rep(j, list) {
				if(i != j) {
					int p1 = list[i].first, t1 = list[i].second.first, d1 = list[i].second.second;
					int p2 = list[j].first, t2 = list[j].second.first;
					
					if( t1+d1+costMax[p1][p2] <= t2 ) adjMax[i][j] = 1;
				}
			}
		}
		
		cout<< bipartiteMatching( adjMax )<<"\n"; 
		
	}
	return 0;
}
