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

  int n;
  cin >> n;

  vector<pair<int, string>> a(n), ans;
  for(int i = 0; i < n; i++) {
    cin >> a[i].second >> a[i].first;
  }

  sort(a.begin(), a.end());

  for(int i = 0; i < n; i++) {
    int pos = a[i].first;
    string name = a[i].second;

    if(pos > i) {
      cout << -1;
      return 0;
    }

    ans.insert(ans.begin() + pos, {n - i, name});
  }

  for(int i = 0; i < n; i++) {
    cout << ans[i].second << " " << ans[i].first << "\n";
  }

  return 0;
}
