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

int n,m,q;
int a[1005][1005];
vector<vector<int>> dir = {{-1,0},{-1,1},{0,1},{1,1},{1,0},{1,-1},{0,-1},{-1,-1}};  //{x,y}

bool isValid(int x, int y){
  return (x<n && y<m && x>=0 && y>=0);
}

int bfs(int rs, int cs, int rd, int cd){
  vector<vector<int>> dis(n, vector<int>(m, LLONG_MAX));
  deque<pair<int,int>> dq;
  dq.push_back({rs,cs});
  dis[rs][cs]=0;
  
  while(!dq.empty()){
    auto [x, y] = dq.front();
    dq.pop_front();
    
    int cost = a[x][y];
    for(int i = 0; i < 8; i++){
      int x1 = x + dir[i][0], y1 = y + dir[i][1];
      if(!isValid(x1, y1)) continue;
      int temp = dis[x][y] + (i == cost ? 0 : 1);
      
      if(temp < dis[x1][y1]){
        dis[x1][y1] = temp;
        if(i == cost)
          dq.push_front({x1, y1});
        else
          dq.push_back({x1, y1});
      }
    }
  }
  
  return dis[rd][cd];
}

signed main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0); cout.tie(0);

  cin>>n>>m;
  for(int i=0;i<n;i++){
    for(int j=0;j<m;j++){
      char ch;
      cin>>ch;
      a[i][j]=(ch-'0');
    }
  }
  cin>>q;
  while(q--){
    int rs,cs,rd,cd;
    cin>>rs>>cs>>rd>>cd;
    cout<<bfs(rs-1,cs-1,rd-1,cd-1)<<"\n";
  }
  
  return 0;
}
