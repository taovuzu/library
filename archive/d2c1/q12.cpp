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
int n,p;
string s;


signed main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0); cout.tie(0);

  cin>>n>>p>>s;
  p--;
  int ans=0,l=-1,r=-1;
  for(int i=0;i<n/2;i++){
    if(s[i]!=s[n-1-i]){
      int diff = abs(s[i]-s[n-1-i]);
      ans+=min(diff,26-diff);
      if(l==-1){
        l=i;
      }
      r=i;
    }
  }

  p = p<n-1-p?p:n-1-p;

  if(ans>0){
    if(p>r){
      ans+=p-l;
    }
    else if(p<l){
      ans+=r-p;
    }
    else{
      ans+=(min(r-p,p-l)*2+max(r-p,p-l));
    }
  }

  cout<<ans<<"\n";

  return 0;
}
