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

double eps = 1e-9;
double p, q, x;
int n = 1179858;
vector<int> primes(1179858, 1), palind(1179858, 0);

bool isPalin(int num){
  int z = 0, y = num;
  while(num){
    z = (z * 10) + num % 10;
    num /= 10;
  }
  return (y == z);
}

void sieve(){
  primes[0] = primes[1] = 0;
  for(int i = 2; i * i <= n; i++){
    if(primes[i]){
      for(int j = i * i; j <= n; j += i){
        primes[j] = 0;
      }
    }
  }
  for(int i = 1; i <= n; i++){
    primes[i] += primes[i - 1];
    if(isPalin(i)){
      palind[i] = 1;
    }
    palind[i] += palind[i - 1];
  }
}

signed main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0); cout.tie(0);

  cin >> p >> q;
  x = p / q;

  sieve();

  int ans = 0;
  for(int i = 1; i <= n; i++){
    double temp = primes[i];
    double temp1 = palind[i] * x;
    if(temp1 >= temp) ans = i;
  }

  cout << ans << "\n";



  return 0;
}
