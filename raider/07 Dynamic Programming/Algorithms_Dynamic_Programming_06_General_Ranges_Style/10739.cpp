			/* Modified Edit distance */
#include<iostream>
#include<string>
using namespace std;

int min(int a, int b, int c)
{
	if(b < a)		a = b;
	if(c < a)		a = c;
	return a;
}

int A[1001][1001]; /* The cost of substring A[i][j] */

int main() 
{
	int i, j, k, len, cases, diag;
	string str;
	
	cin>>cases;
	for (k = 1; k <= cases; k++)
	{		
		cin>>str;

		for (i=0; i<str.size(); i++) /* Base case in diagonal */
			A[i][i] = 0; /* Empty string */

		for (len = 2; len <= str.size(); len++)	/* O(n^2) */
		{	/* when len = 2 --> Special case */
			for (i = 0; i+len<=str.size(); i++)
			{
				j = i + len - 1, diag = 0;

				if (str[i] != str[j])
					diag = 1;

				if( i+1 <= j-1 ) /* at least j-i > 1 */
					A[i][j] = min(A[i+1][j]+1, A[i][j-1]+1, A[i+1][j-1]+diag);

				else	/* Undefined Stage (Not in base case) i = j+1 */
					A[i][j] = diag; /* j=i+1Tow char string */
			}
		}
		cout<<"Case "<<k<<": "<<A[0][str.size()-1]<< "\n";
	}
	return 0;
}