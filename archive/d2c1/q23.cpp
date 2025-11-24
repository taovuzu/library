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

int a[105];
int g[105][100005];
queue<int> q;
int n, r1, c1, r2, c2;

int bfs(){
  g[r1][c1]=1;
  q.push(r1),q.push(c1);
  while(!q.empty()){
    int x = q.front();
    q.pop();
    int y= q.front();
    q.pop();
    // Up 
    if(x>1){
      int y1 = min(a[x-1],y);
      if(g[x-1][y1]==0){
        g[x-1][y1]=g[x][y]+1;
        q.push(x-1);
        q.push(y1);
      }
    }
    // Down
    if(x<n){
      int y1 = min(a[x+1],y);
      if(g[x+1][y1]==0){
        g[x+1][y1]=g[x][y]+1;
        q.push(x+1);
        q.push(y1);
      }
    }
    // Left
    if(y>1){
      if(g[x][y-1]==0){
        g[x][y-1]=g[x][y]+1;
        q.push(x);
        q.push(y-1);
      }
    }
    // Right
    if(y<a[x]){
      if(g[x][y+1]==0){
        g[x][y+1]=g[x][y]+1;
        q.push(x);
        q.push(y+1);
      }
    }
  }
  return g[r2][c2]-1;
}

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);

    cin >> n;
    for(int i = 1; i <= n; i++) {
        cin >> a[i];
        a[i]++;
    }
    cin >> r1 >> c1 >> r2 >> c2;

    int ans = bfs();
    cout << ans << "\n";

    return 0;
}