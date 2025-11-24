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
vector<string> a(52);
vector<vector<string>> b;

void solver(){
  // pr(b);
  while(b.back().empty()) b.pop_back();
  for(int i=0;i<b.size();i++){
    if(b[i].empty()){
      b.erase(b.begin()+i);
    }
    if(i>=3){
      string x= b[i].back();
      if(x[0]==b[i-3].back()[0] || x[1]==b[i-3].back()[1]){
        b[i].pop_back();
        b[i-3].push_back(x);
        solver();
        return ;
      }
    }
    else if(i>=1){
      string x= b[i].back();
      if(x[0]==b[i-1].back()[0] || x[1]==b[i-1].back()[1]){
        b[i].pop_back();
        b[i-1].push_back(x);
        solver();
        return ;
      }
    }
  }
}

signed main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0); cout.tie(0);
  while(true){
    cin>>a[0];
    if(a[0]=="#") break;
    for(int i=1;i<52;i++){
      cin>>a[i];
    }
    int j=1;
    b.clear();
    b.push_back({a[0]});
    while(j<52){
      while(b.back().empty()) b.pop_back();
      b.push_back({a[j]});
      solver();
      j++;
    }
    pr(b);
  }


  return 0;
}
