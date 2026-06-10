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
    int n,x,k;
    string s;
    cin>>n>>x>>k>>s;
    int cnt=0,pos=x,ans=0;
    bool flag=false;
    for(int i=0;i<n;i++){
      if(s[i]=='L') pos--;
      else pos++;
      if(pos==0){
        cnt=i+1;
        k-=cnt;
        ans++;
        for(int j=0;j<n;j++){
          if(s[j]=='L') pos--;
          else pos++;
          if(pos==0){
            flag=true;
            cnt=j+1;
            break;
          }
          // pr(pos,j);
        }
        break;
      }
      // pr(pos,i);
    }
    // pr(flag,cnt,k);
    if(flag){
      ans+=( k/cnt);
    }
    cout<<ans<<"\n";
  }

  return 0;
}
