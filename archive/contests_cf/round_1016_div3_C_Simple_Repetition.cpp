/* Embrace boredom and hard work; only through relentless discipline does mastery unlock a universe of true pleasure. */
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

const int MAXN = 1e5;

vector<int> primes;
vector<bool> isPrime(MAXN + 5, true);

void sieve() { 
  isPrime[0] = isPrime[1] = false; 

  for (int i = 2; i * i <= MAXN; ++i) {
      if(isPrime[i]) {
        primes.push_back(i);
          for (int j = i * i; j <= MAXN; j += i)
              isPrime[j] = false;
      }
  }

  int last = primes.back() + 1;
  for(int i = last; i < MAXN; i++) {
    if(isPrime[i]) {
      primes.push_back(i);
    }
  }
}

signed main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0); cout.tie(0);

  int tt=1;  cin>>tt;
  sieve();
  while (tt--) {
    int n, k;
    cin >> n >> k;

    if(k != 1 && n != 1) {
      cout << "NO" << "\n";
      continue;
    }

    if(n == 1) {
      while(--k) {
        n *= 10;
        n++;
      }
    }

    bool flag = true;

    if(n < MAXN) {
      if(isPrime[n] == 0) {
        flag = false;
      }
    }
    else {
      for(int i = 0; i < primes.size(); i++) {
        if(n % primes[i] == 0) {
          flag = false;
          break;
        }
      }
    }
   
    if(flag) {
      cout << "YES" << "\n";
    }
    else {
      cout << "NO" << "\n";
    }
  }

  return 0;
}
