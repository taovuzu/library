//Maximum flow algorithm using recursion  for path generation
//good for matching problems and flow where max path capacity=1.
// O(mf); m: maximum flow, f: # of arcs (links)

#include<iostream>
#include<algorithm>
#include<cmath>
#include<string>
using namespace std;

#define MAXN 700     //maximum number of nodes
int flow[MAXN][MAXN];	 //flow
int cap[MAXN][MAXN]; //capacity
int n;//number of nodes
int src,sink;//source, sink(target)

//Internal use by Path generation
int path[MAXN];
int pathLength;//length of path
bool visited[MAXN];

int min(int i1,int i2){return i1<i2?i1:i2;}

//return path flow of any path exits, not shortest one
int getPath(int StartNode,int TargetNode,int cur,int maxcap)
{
	path[cur]=StartNode;
	if (StartNode==TargetNode) 
	{
		pathLength=cur+1;
		return maxcap;
	}
	int ret=0;
	visited[StartNode]=true;
	for(int i=0;i<n;i++)
	{
		if (i==StartNode) continue;
		if (visited[i] || cap[StartNode][i]<=0) continue;
		ret = getPath(i,TargetNode,cur+1,min(maxcap,cap[StartNode][i]));
		if (ret>0) break;
	}
	return ret;
}

//Pre:	n:	the number of nodes
//		capacity: an n*n matrix contains the capacity, a directed graph
//		src:the index of the source node
//		sink: the index of sink node
//Post:	
//		flow matrix will contain the flow between each 2 nodes
//return: the total flow from source to sink
int maxFlow()
{
	int tf=0;//total flow
	memset(flow,0,sizeof(flow));
	while(1)
	{
		memset(visited,0,sizeof(visited));
		int newflow=getPath(src,sink,0,INT_MAX);
		if (!newflow) break;
		for(int i=1;i<pathLength;i++)
		{
			int m=path[i-1],n=path[i];
			cap[m][n]-=newflow;
			cap[n][m]+=newflow;

			flow[m][n]+=newflow;
			flow[n][m]=-flow[m][n];
		}
		tf+=newflow;
	}
	return tf;
}

double xg[MAXN], yg[MAXN], xh[MAXN], yh[MAXN];	//g:gopher, h:hole

double hypot2(double x, double y)
{
	return sqrt(x*x + y*y);
}

int main()
{
	int i, j, cn, sn;
	double s, v, dist;
	
	while(cin>>cn>>sn>>s>>v)
	{
		src = 0;
		sink = cn+sn+1;
		n = cn+sn+2;
		
		memset(cap,0,sizeof(cap));
		
		for(i=0;i<cn;i++)
			cin>>xg[i]>>yg[i];
		
		for(i=0;i<cn;i++)
			cap[src][i+1] = 1;			//For Dest

		for(j=0;j<sn;j++)
			cin>>xh[j]>>yh[j];
		
		for(j=0;j<sn;j++)
			cap[cn+j+1][sink] = 1;		//For Sink
		
		for(i=0;i<cn;i++)
		{
			for(j=0;j<sn;j++)
			{
				dist = hypot2(xg[i]-xh[j], yg[i]-yh[j]);
				
				if(dist <= v*s) //Is this right
					cap[i+1][cn+j+1]=1;
			}
		}		
		cout<<cn-maxFlow()<<endl;	//Minimum
	}
	return 0;
}
