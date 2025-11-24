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

  int n, k;
  cin >> n >> k;
  vector<int> a(n);
  for(int i = 0; i <n; i++){
    cin >> a[i];
  }
  sort(a.rbegin(), a.rend());
  int count = 0, h = a[0] - 1;
  int i = 0, ans = 0;
  while(h >= a[n - 1] ){
    while(i < n && a[i] > h) i++;
    if(count + i > k){
      count =  0;
      ans++;
    }
    count += i;
    h--;
  }
  if(count) ans++;
  cout << ans << "\n";

  return 0;
}
