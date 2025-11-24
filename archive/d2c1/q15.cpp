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

  int n,x,y,last=0,lp=1;
  cin>>n;
  map<int,int> mp,mp3;
  vector<int> b(n,-1);
  for(int i=0;i<n;i++){
    cin>>x>>y;
    mp[x]=y;
    mp3[x]++;
    mp3[y]++;
  }

  while(lp<n){
    last = mp[last];
    b[lp]=last;
    lp+=2;
  }

  for(auto it:mp3){
    if(it.second==1 && mp.find(it.first)!=mp.end()){
      mp[-1]=it.first;
      break;
    }
  }
  lp=0,last=-1;

  while(lp<n){
    last = mp[last];
    b[lp]=last;
    lp+=2;
  }


  for(int i=0;i<n;i++){
    cout<<b[i]<<" \n"[i==n-1];
  }

  return 0;
}
