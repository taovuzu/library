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


vector<int> primes;

void sieve(){
  vector<bool> a(100100, 1);
  for (int i = 2; i * i <= 100000; i++) {
    if(a[i]){
      primes.push_back(i);
      for(int j = i * i; j <= 10000; j += i){
        a[j] = 0;
      }
    }
  }
}

bool isPrime(int n){
  for(int i = 2; i < n; i++){
    if(n % i == 0) return false;
  }
  return true;
}

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    int n;
    cin >> n;

    sieve();
    set<int> xt;

    vector<int> a(n + 1);
    iota(a.begin(), a.end(), 0);
    xt.insert(a.begin() + 1, a.end());
    
    int j = 0;
    for(int i = 0; i <= n; i++){
      if(j < primes.size()){
        a[i] = primes[j];
        xt.erase(xt.begin());
      }
      else{
        a[i] = *xt.begin();
        xt.erase(xt.begin());
      }
    }


    int primes = 0;

    for (int i = 1; i <= n; i++) {
      int sum = accumulate(a.begin(), a.begin() + i + 1, 0LL);
      int num = (sum + i - 1) / i;

      if (isPrime(num)) primes;
      if(primes < (i / 3) - 1){
        pr(i, primes);
      }
    }

    

    return 0;
}
