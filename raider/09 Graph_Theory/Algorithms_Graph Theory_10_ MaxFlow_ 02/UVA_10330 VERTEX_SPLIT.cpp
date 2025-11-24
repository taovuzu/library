//Maximum flow algorithm (using modified Dijkstra)
// O(n^2 * n); n: # of nodes, but usually much faster
#include<iostream>
#include<iomanip>
#include<string>
#include<algorithm>
using namespace std;

const int MAXN = 300;
const int OO   = 100000000;

int cap[MAXN][MAXN];
bool visited[MAXN];
int path[MAXN], prev[MAXN], ds[MAXN];

int n, src, sink, pathLength;

int min(int a,int b)
{
	return a < b ? a : b ;
}
//Run a Dijkstra's varient[MaxMin] to find maximum augmenting path
int getPath(int StartNode,int TargetNode)
{
	int i, maxd, maxi, cur;
	memset(visited,0,sizeof(bool)*n);

	cur=StartNode;
	visited[cur]=true;

	for(i=0;i<n;i++)
		ds[i] = cap[StartNode][i], prev[i]=cur;

	while(1)
	{
		maxd=0;		maxi=-1;

		for(i=0;i<n;i++)
		{	//Find Longest Path
			if (!visited[i] && ds[i]>maxd) 
			{
				maxd=ds[i];
				maxi=i;
			}
		}
		
		if (maxd==0)			break;		
		if (maxi == TargetNode) break;

		cur = maxi;
		visited[cur] = true;

		
		for(i=0;i<n;i++)							//update
		{
			if (min(ds[cur], cap[cur][i]) > ds[i])	//Max Min
			{
				ds[i]   = min(ds[cur],cap[cur][i]);
				prev[i] = cur;
			}
		}
	}

	//Generate path
	int pi=TargetNode;
	pathLength=0;

	while(1)
	{
		path[pathLength++]=pi;
		if (pi==StartNode) 
			break;
		pi=prev[pi];
	}
	reverse(path,path+pathLength);

	return ds[TargetNode];
}

int maxFlow()
{
	int tf=0;//total flow

	int newflow;

	while(newflow = getPath(src,sink))
	{		
		for(int i=1;i<pathLength;i++)
		{
			int m=path[i-1], n=path[i];	//Look carefully

			cap[m][n]-=newflow;
			cap[n][m]+=newflow;

		}
		tf+=newflow;
	}
	return tf;
}

void main()
{
	int i, links, ins, outs, from, to, vertex_cap;
	while(cin>>n)
	{
		memset(cap, 0, sizeof(cap));
		for(i=1;i<=n;i++)
		{
			cin>>vertex_cap;
			cap[i][i+n] = vertex_cap; /* Vertex Splitting method */

		}
		
		cin>>links;
		for(i=0;i<links;i++)
		{
			int a,b,c;
			cin>>a>>b>>c;
			cap[a+n][b] = c;
		}

		src  = 0;	sink = 2*n+1; /* Multiple src - Multiple dest method */

		cin>>ins>>outs;

		for(i=0;i<ins;i++)
		{
			cin>>to;
			cap[src][to] = OO;
		}
		
		for(i=0;i<outs;i++)
		{
			cin>>from;
			cap[from+n][sink] = OO;
		}

		n = sink+1;

		cout<<maxFlow()<<endl;

	}
}
/*
This is the input to MAX_FLOW after reducing the input

9 12
0 1 200
0 3 200
0 4 200
8 9 300
1 2 10
2 7 13
4 5 20
5 3 5
5 7 7
3 6 30
6 7 20
7 8 40

*/