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

  int tt=1;  cin>>tt;
  while (tt--) {
    int n, k;
    string s;
    cin >> n >> k >> s;

    string s1 = s;
    sort(s1.begin(), s1.end());

    if(s1[0] == s1.back()){
      cout << "NO" << "\n";
      continue;
    }

    s1 = s;
    reverse(s1.begin(), s1.end());

    if(s < s1 || k > 0){
      cout << "YES" <<  "\n";
      continue;
    }
    else {
      cout << "NO" << "\n";
    }
  }

  return 0;
}
