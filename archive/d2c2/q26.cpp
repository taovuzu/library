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

signed main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0); cout.tie(0);

  while(true){
    int n ,w;
    vector<vector<char>> a(30, vector<char> (30, 'X'));
    cin >> n >> w;
    if(n == 0 && w == 0) break;
    int sri, srj, dsi, dsj;
    for(int i = 1; i <= w; i++ ){
      for(int j = 1; j <= n; j++){
        cin >> a[i][j] ;
        if(a[i][j] == 'S'){
          a[i][j] = '0';
          sri = i;
          srj = j;
        }
        if(a[i][j] == 'D'){
          a[i][j] = '0';
          dsi = i;
          dsj = j;
        }
      }
    }
  
    vector<vector<int>> dist(30, vector<int> (30, LLONG_MAX));
    dist[sri][srj] = 0;
    set<array<int,3>> xt; // dis, i, j;
    xt.insert({0, sri, srj});
    while(!xt.empty()){
      int i = (*xt.begin())[1], j = (*xt.begin())[2];
      xt.erase(xt.begin());
      if(a[i - 1][j] != 'X' ){
        if(dist[i - 1][j] > dist[i][j] + (a[i - 1][j] - '0')){
          xt.erase({dist[i - 1][j], i - 1, j});
          dist[i - 1][j] =  dist[i][j] + (a[i - 1][j] - '0');
          xt.insert({dist[i - 1][j], i - 1, j});
        }
      }
      if(a[i + 1][j] != 'X' ){
        if(dist[i + 1][j] > dist[i][j] + (a[i + 1][j] - '0')){
          xt.erase({dist[i + 1][j], i + 1, j});
          dist[i + 1][j] =  dist[i][j] + (a[i + 1][j] - '0');
          xt.insert({dist[i + 1][j], i + 1, j});
        }
      }
      if(a[i][j - 1] != 'X' ){
        if(dist[i][j - 1] > dist[i][j] + (a[i][j - 1] - '0')){
          xt.erase({dist[i][j - 1], i, j - 1});
          dist[i][j - 1] =  dist[i][j] + (a[i][j - 1] - '0');
          xt.insert({dist[i][j - 1], i, j - 1});
        }
      }
      if(a[i][j + 1] != 'X' ){
        if(dist[i][j + 1] > dist[i][j] + (a[i][j + 1] - '0')){
          xt.erase({dist[i][j + 1], i, j + 1});
          dist[i][j + 1] =  dist[i][j] + (a[i][j+ 1] - '0');
          xt.insert({dist[i][j + 1], i, j + 1});
        }
      }
    }
    
    cout << dist[dsi][dsj] << "\n";
  }

  return 0;
}
