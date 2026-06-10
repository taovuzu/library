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

bool check(int mid, vector<int> &a, int n, int k) {
  int cnt = 0;
  int mex = 0;
  vector<bool> vis(n, false);
  for (int i = 0; i < n; i++) {
    if (a[i] < mid && !vis[a[i]]) {
      vis[a[i]] = true;
      mex++;
    }
    if(mex == mid) {
      mex = 0;
      fill(vis.begin(), vis.end(), false);
      cnt++;
    }
  }

  return cnt >= k;
}

signed main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0); cout.tie(0);

  int tt=1;  cin>>tt;
  while (tt--) {
    int n, k;
    cin >> n >> k;

    vector<int> a(n);
    for (int i = 0; i < n; i++) {
      cin >> a[i];
    }

    int lo = 0, hi = n, ans = 0;
    while (lo <= hi) {
      int mid = lo + (hi - lo) / 2;
      if (check(mid, a, n, k)) {
        ans = mid;
        lo = mid + 1;
      } else {
        hi = mid - 1;
      }
    }
    cout << ans << "\n";
  }

  return 0;
}
