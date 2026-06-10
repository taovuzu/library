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
    string s;
    cin >> s;

    int last, ans = s.size() - 1;
    for(int i = s.size() - 1; i >= 0; i--) {
      if(s[i] != '0') {
        last = i;
        break;
      }
    }

    for(int i = 0; i < last; i++) {
      if(s[i] == '0') ans--;
    }

    cout << ans << "\n";
  }

  return 0;
}
