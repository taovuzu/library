#include <bits/stdc++.h>

using namespace std;

#define int long long

#ifndef ONLINE_JUDGE
#include "pr.h"
#else
#define pr(...) {}
#define debarr(a, n) {}
#define debmat(mat, row, col) {}
#endif

int n,m,k;
char a[505][505];
bool vis[505][505];

bool block(int i,int j,int pi,int pj){
  if(i+1<n && i+1!=pi && a[i+1][j]=='.') return false;
  if(i-1>=0 && i-1!=pi && a[i-1][j]=='.') return false;
  if(j+1<m && j+1!=pj && a[i][j+1]=='.') return false;
  if(j-1>=0 && j-1!=pj && a[i][j-1]=='.') return false;
  return true;
}

void dfs(int i,int j,int pi,int pj){
  if(i>=n || j>=m || i<0 || j<0 || a[i][j]=='#' || a[i][j]=='X'  ) return;
  // pr(i,j);
  // if(vis[i][j] && k){
  //   a[i][j]='X';
  //   k--;
  // }
  if(vis[i][j]) return ;
  vis[i][j]=1;
  if((i!=pi || j+1 !=pj))
  dfs(i,j+1,i,j);
  if((i!=pi || j-1 !=pj))
  dfs(i,j-1,i,j);
  if((i-1!=pi || j !=pj))
  dfs(i-1,j,i,j);
  if((i+1!=pi || j !=pj))
  dfs(i+1,j,i,j);


  if(k && block(i,j,pi,pj)){
    pr(i,j);
    debmat(a,n,m);
    a[i][j]='X';
    k--;
  }

}

signed main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0); cout.tie(0);

  cin>>n>>m>>k;
  for(int i=0;i<n;i++){
    for(int j=0;j<m;j++){
      cin>>a[i][j];
    }
  }

  for(int i=0;i<n;i++){
    for(int j=0;j<m;j++){
      if(a[i][j]=='.'){
        dfs(i,j,-1,-1);
        break;
      }
    }
  }

  for(int i=0;i<n;i++){
    for(int j=0;j<m;j++){
      cout<<a[i][j];
    }
    cout<<"\n";
  }

  return 0;
}
