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

  int n,q,ptr=0,total=0;
  cin>>n>>q;
  vector<queue<int>> a(n);
  vector<int> b;
  while(q--){
    int t,x;
    cin>>t>>x;
    x--;
    if(t==1){
      b.push_back(x);
      a[x].push(b.size()-1);
      total++;
    }
    else if(t==2){
      while(!a[x].empty()){
        b[a[x].front()]=-1;
        a[x].pop();
        total--;
      }
    }
    else{
      while(ptr<=x){
        if(b[ptr]==-1){
          ptr++;
          continue;
        }
        a[b[ptr]].pop();
        ptr++;
        total--;
      }
    }
    cout<<total<<"\n";
  }

  return 0;
}
