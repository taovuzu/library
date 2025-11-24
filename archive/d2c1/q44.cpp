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

vector<int> topo(vector<vector<bool>>& graph, int n) {
  vector<int> inDeg(n, 0);
  
  for (int i = 0; i < n; i++) {
      for (int j = 0; j < n; j++) {
          if (graph[i][j]) {
              inDeg[j]++;
          }
      }
  }

  queue<int> qu;
  for (int i = 0; i < n; i++) {
      if (inDeg[i] == 0) {
          qu.push(i);
      }
  }

  vector<int> ans;
  while (!qu.empty()) {
      int node = qu.front();
      qu.pop();
      ans.push_back(node + 1);
      for (int i = 0; i < n; i++) {
          if (graph[node][i]) {
              inDeg[i]--;
              if (inDeg[i] == 0) {
                  qu.push(i);
              }
          }
      }
  }
  if(ans.size()!=n) return {};
  return ans;
}




signed main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0); cout.tie(0);

  int tt=1;  cin>>tt;
  while (tt--) {
    int n,m,val0,val1; 
    cin>>n;
    vector<vector<bool>> graph(n,vector<bool> (n));
    vector<int> a(n);
    for(int i=0;i<n;i++){
      cin>>a[i];
      a[i]--;
    }
    for(int i=0;i<n;i++){
      for(int j=i+1;j<n;j++){
        graph[a[i]][a[j]]=true;
      }
    }
    cin>>m;
    for(int i=0;i<m;i++){
      cin>>val0>>val1;
      val0--,val1--;
      swap(graph[val0][val1],graph[val1][val0]);
    }
    vector<int> ans = topo(graph,n);
    if(ans.empty()){
      cout<<"IMPOSSIBLE"<<"\n";
      continue;
    }
    for(int i=0;i<n;i++){
      cout<<ans[i]<<" \n"[i==n-1];
    }
  }

  return 0;
}
