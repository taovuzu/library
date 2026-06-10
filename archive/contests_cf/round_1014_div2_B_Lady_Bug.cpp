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
    int n;
    cin >> n;

    string a, b;
    cin >> a >> b;

    int even = 0, odd = 0, even1 = 0, odd1 = 0;
    for(int i = 0; i < n; i++){
      if(a[i] == '1' && (i & 1)) even++;
      if(b[i] == '0' && (i & 1)) even1++;
      if(a[i] == '1' && !(i & 1)) odd++;
      if(b[i] == '0' && !(i & 1)) odd1++;
    }

    // pr(odd, even, odd1, even1);
    if(odd <= even1 && even <= odd1){
      cout << "YES" << "\n";
    }
    else {
      cout << "NO" << "\n";
    }
  }

  return 0;
}
