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

vector<int> a;

void sieve(){
  vector<bool> primes(50000,1);
  for(int i=2;i*i<50000;i++){
    if(primes[i]){
      for(int j=i*i;j<50000;j+=i){
        primes[j]=false;
      }
    }
  }
  for(int i=2;i<50000;i++){
    if(primes[i]) a.push_back(i);
  }
}

signed main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0); cout.tie(0);
  sieve();
  while(true){
    int n,m;
    cin>>n;
    m=n;
    if(!n) return 0;
    vector<int> ans;
    if(n<0){
      ans.push_back(-1);
      n=-n;
    }
    for(int i=0;i<a.size();i++){
      if(n==1) break;
      int temp= a[i];
      if(temp*temp>n) break;
      while(n%temp==0){
       ans.push_back(temp);
       n/=temp;
      }
    }
    if(n!=1) ans.push_back(n);
    cout<<m<<" = "<<ans[0];
    for(int i=1;i<ans.size();i++){
      cout<<" x "<<ans[i];
    }
    cout<<"\n";
  }
  return 0;
}
