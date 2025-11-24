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

const int mod = 1e9+7;

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

signed main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0); cout.tie(0);

  int n;
  cin>>n;

  cout<<binpow(3,binpow(3,n,mod-1),mod);

  return 0;
}
