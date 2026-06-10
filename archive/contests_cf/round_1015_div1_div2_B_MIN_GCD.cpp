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

signed main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0); cout.tie(0);

  int tt=1;  cin>>tt;
  while (tt--) {
    int n;
    cin >> n;
    
    vector<int> a(n);
    for(int i = 0; i < n; i++) {
      cin >> a[i];
    }

    sort(a.begin(), a.end());

    int mini = a[0];
    vector<int> b;
    for(int i = 1; i < n; i++){
      int gcd = __gcd(a[i], mini);
      if((gcd % mini ) == 0) {
        b.push_back(a[i]);
      }
    }

    bool flag = false;
    int gcd = b.empty() ? -1 : b[0];
    for(int i = 1; i < b.size(); i++) {
      gcd = __gcd(b[i], gcd);
      if(gcd == mini) {
        flag = true;
        break;
      }
    }
    if(gcd == mini) {
      flag = true;
    }

    cout << (flag ? "Yes" : "No") << "\n";

  }

  return 0;
}
