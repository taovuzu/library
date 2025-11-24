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

int s,w,c,k,m;

int total = 0, time = 0, robots = 1;

signed main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0); cout.tie(0);

  while(cin>>s>>w>>c>>k>>m){
    while(true){
      time+=m;
      robots = time/k;

    }
  }

  return 0;
}

// 10 20 10 1 5
//
// 20 -> 40 -> 60
