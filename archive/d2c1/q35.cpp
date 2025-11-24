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

  cout<<fixed << setprecision(5);
  long double cows,cars,shows;
  while(cin>>cows>>cars>>shows){
    long double total = cows+cars;
    long double ans = ((cars/total)*((cars-1)/(total-shows-1)))+((cows/total)*((cars)/(total-shows-1)));
    cout<<ans<<"\n";
  }

  return 0;
}
