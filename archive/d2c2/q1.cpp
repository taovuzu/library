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

  int n;
  cin>>n;
  int num=1,count=0,temp=n;
  for(int i=3;i*i<=n && count<2;i+=2){
    while(n%i==0 && count<2){
      n/=i;
      num*=i;
      count++;
    }
  }
  if(count==0) num=0,count=2;
  if(temp==num) count=0;
  if(count>=2){
    cout<<1<<"\n"<<num;
  }
  else{
    cout<<2;
  }

  return 0;
}
