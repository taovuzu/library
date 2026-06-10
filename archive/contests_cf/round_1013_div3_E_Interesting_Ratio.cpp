#pragma GCC optimize("O3,unroll-loops")

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

int sieve() { 
  const int n = 1e7 + 100;
  vector<bool> isPrime(n + 1, true);
  isPrime[0] = isPrime[1] = false; 

  for (int i = 2; i * i <= n; ++i) {
      if (isPrime[i]) {
          for (int j = i * i; j <= n; j += i)
              isPrime[j] = false;
      }
  }

  for (int i = 2; i <= n; ++i) {
      if (isPrime[i]) {
          primes.push_back(i);
      }
  }

  return primes.size();
}

signed main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0); cout.tie(0);

  sieve();
  int tt;
  cin >> tt;
  
  while (tt--) {
    int n;
    cin >> n;

    int ans = 0;
    int num = upper_bound(primes.begin(), primes.end(), n) - primes.begin();
    
    for (int i = 0; i < num; i++) {
      ans += n / primes[i];
    }
    
    cout << ans << "\n";
  }

  return 0;
}
