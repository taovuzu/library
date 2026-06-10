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

  int tt=1;  cin>>tt;
  while (tt--) {
    int n,m,k;
    cin>>n>>m>>k;
    if(abs(n-m)>k || k>max(n,m)){
      cout<<"-1\n";
    }
    else{
      int i=n,j=m;
      string ans="";
      bool flag1=true;
      while(i>0 && j>0){
        if(i>=j && flag1){
          for(int l=0;l<k && i>0;l++){
            ans+="0";
            i--;
            // pr(i,l);
          }
          flag1=false;
        }
        else {
          for(int l=0;l<k && j>0;l++){
            ans+="1";
            j--;
            // pr(l,j);
          }
          flag1=true;
        }
        // pr(i,j,'.');
      }
      while(i>0){
        ans+="0";
        i--;
      }
      while(j>0){
        ans+="1";
        j--;
      }
      // pr(i,j,'*');
      cout<<ans<<"\n";
    }
  }

  return 0;
}
