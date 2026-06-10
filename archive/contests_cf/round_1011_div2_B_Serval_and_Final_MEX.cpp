#include <bits/stdc++.h>

using namespace std;

#define int long long

#ifndef ONLINE_JUDGE
#include "pr.h"
#else
#define pr(...) \
  {             \
  }
#define debarr(a, n) \
  {                  \
  }
#define debmat(mat, row, col) \
  {                           \
  }
#endif

signed main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);

  int tt = 1;
  cin >> tt;
  while (tt--) {
    int n;
    cin >> n;

    vector<int> a(n);
    for (int i = 0; i < n; i++) {
      cin >> a[i];
    }

    vector<array<int, 2>> ans;
    if (count(a.begin() + 2, a.end(), 0)) {
      ans.push_back({3, n});
      n = 3;
    }

    if (count(a.begin(), a.begin() + 2, 0)) {
      ans.push_back({1, 2});
      n--;
    }

    ans.push_back({1, n});
    
    cout << ans.size() << "\n";
    for (int i = 0; i < ans.size(); i++) {
      cout << ans[i][0] << " " << ans[i][1] << "\n";
    }
  }

  return 0;
}
