#include<iostream>
#include<string>
#include<cmath>
using namespace std;

#define M 200
#define N 200

bool cap[M][N];
bool seen[N];
int matchL[M], matchR[N];
int n, m;

bool bpm( int u )
{
    for( int v = 0; v < n; v++ )
		if( cap[u][v] )
		{
			if( seen[v] ) continue;
			seen[v] = true;
			
			if( matchR[v] < 0 || bpm( matchR[v] ) )
			{
				matchL[u] = v;
				matchR[v] = u;
				return true;
			}
		}
    return false;
}
// cnt contains the number of happy pigeons
// matchL[i] contains the hole of pigeon i or -1 if pigeon i is unhappy
// matchR[j] contains the pigeon in hole j or -1 if hole j is empty

int Bipartite()
{
	memset( matchL, -1, sizeof( matchL ) );
    memset( matchR, -1, sizeof( matchR ) );

	int i, cnt = 0;
    for( i = 0; i < m; i++ )
    {
        memset( seen, 0, sizeof( seen ) );
        if( bpm( i ) ) 
			cnt++;
    }
	return cnt;
}


double xg[M], yg[M], xh[N], yh[N];	//g:gopher, h:hole

double hypot2(double x, double y)
{
	return sqrt(x*x + y*y);
}

int main()
{
	int i, j;
	double s, v, dist;
	
	while(cin>>n>>m>>s>>v)
	{		
		for(i=0;i<n;i++)
			cin>>xg[i]>>yg[i];

		for(j=0;j<m;j++)
			cin>>xh[j]>>yh[j];

				
		for(i=0;i<n+m+2;i++)
		{
			for(j=0;j<n+m+2;j++)
				cap[i][j] = 0;
		}

		for(i=0;i<n;i++)
		{
			for(j=0;j<m;j++)
			{
				dist = hypot2(xg[i]-xh[j], yg[i]-yh[j]);
				
				if(dist <= v*s) //Is this right
					cap[i][j]=1;
			}
		}
		cout<<n-Bipartite()<<endl;	//Minimum
	}
	return 0;
}