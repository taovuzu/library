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

  string s;
  cin >> s;
  int lo = LLONG_MAX;
  for(int i = 0; i < s.size(); i++){
    int temp = s[i] - 'a';
    if(temp > lo){
      cout << "Ann" << "\n";
    }
    else {
      cout << "Mike" << "\n";
    }
    lo = min(lo, temp);
  }


  return 0;
}
