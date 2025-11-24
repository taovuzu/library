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

  int n, x;
  cin >> n >> x;
  vector<int> a(n);
  for(int i = 0; i < n; i++){
    cin >> a[i];
  }
  int mini = LLONG_MAX, miniIdx = -1, f_dis = 0;

  for(int i = 0; i < n; i++){
    if(a[i] <= mini ){
      mini = a[i];
      miniIdx = i;
    }
  }

  for(int i = x-1; i >=0; i--){
    if(a[i] == mini){
      miniIdx = i;
      break;
    }
  }
  for(int i = 0; i < n; i++){
    a[i] -= mini;
  }

  for(int i = (miniIdx + 1) % n; i != x % n ; i = (i + 1) % n){
    f_dis++;
    a[i]--;
  }
  
  a[miniIdx] = n * mini + f_dis;

  for(int i = 0; i < n; i++){
    cout << a[i] <<" \n"[i==n-1];
  }

  return 0;
}
