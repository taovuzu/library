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

  int n;
  cin >> n;
  
  vector<int> a(n);
  for(int i = 0; i < n; i++){
    cin >> a[i];
  }

  int ans = n, cnt = 0;
  for(int i = 1; i < n; i++){
    if(a[i] < a[i - 1]){
      ans = i;
      cnt++;
    }
  }

  ans = n - ans;
  if(cnt == 1){
    if(a[n - 1] > a[0]) cnt = 2;
  }
  cout << (cnt > 1 ? -1 : ans );

  return 0;
}
