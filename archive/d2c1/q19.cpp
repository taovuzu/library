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

long long binpow(long long a, long long b, long long m = 0) {
  long long res = 1;
  if (m != 0)
    a %= m;
  while (b > 0)
  {
    if (b & 1) {
      res = m ? (res * a % m) : (res * a);
    }
    a = m ? (a * a % m) : (a * a);
    b >>= 1;
  }
  return res;
}

bool isPrime(int n){
  if(n!=2 && !(n&1)) return false;
  for(int i=3;i*i<=n;i+=2){
    if(!(n%i)) return false;
  }
  return true;
}

signed main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0); cout.tie(0);

  vector<bool> a(32,0);
  for(int i=1;i<=31;i++){
    if(isPrime(binpow(2,i)-1)){
      a[i]=true;
    }
  }
  while(true){
    int n;
    cin>>n;
    if(!n) break;
    if(isPrime(n)){
      if(a[n]){
        cout<<"Perfect: "<<(binpow(2,n)-1)*(binpow(2,n-1))<<"!\n";
      }
      else{
        cout<<"Given number is prime. But, NO perfect number is available.\n";
      }
    }
    else{
      cout<<"Given number is NOT prime! NO perfect number is available.\n";
    }
  }

  return 0;
}
