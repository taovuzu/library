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


int maxi(int num,int prime){
  int power=0;
  for(int i=prime;i<=num;i*=prime){
    power += num/i;
  }
  return power;
}

signed main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0); cout.tie(0);

  int n,m,x,y;
  while(cin>>n>>m){
    int i=2;
    x=n,y=m;
    bool flag=true;
    while(i*i<=y){
      int count=0;
      while(y%i==0){
        count++;
        y/=i;
      }
      if(count && maxi(x,i)<count){
        flag=false;
        break;
      }
      i++;
    }
    if(y>1){
      if(!maxi(x,y)){
        flag=false;
      }
    }
    if(flag){
      cout<<m<<" divides "<<n<<"!\n";
    }
    else{
      cout<<m<<" does not divide "<<n<<"!\n";
    }
  }

  return 0;
}
