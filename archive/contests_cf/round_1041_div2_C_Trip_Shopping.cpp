// नीरसतां परिश्रमं च आलिंगयन्तु, केवलं अदम्य-अनुशासनेन 
// एव निपुणता सच्चिदानन्दस्य ब्रह्माण्डस्य तालान् उद्घाटयति। 
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

void solve() {
  int n, k;
  cin >> n >> k;
  vector<array<int, 2>> a(n);
  vector<int> b(n + 1);
  for (int i = 0; i < n; i++) {
    cin >> a[i][0];
  }

  for (int i = 0; i < n; i++) {
    cin >> a[i][1];
    if(a[i][1] < a[i][0]) swap(a[i][0], a[i][1]);
  }

  sort(a.begin(), a.end());
  int ans = LLONG_MAX;
  for (int i = 1; i < n; i++) {
    vector<int> c{a[i][0], a[i][1], a[i - 1][0], a[i - 1][1]};
    sort(c.begin(), c.end());
    int org = abs(a[i][1] - a[i][0]) + abs(a[i - 1][1] - a[i - 1][0]);
    int sum = c[3] - c[0] + c[2] - c[1];
    if (sum - org< ans) {
      ans = max(sum - org, 0LL);
    }
  }

  for (int i =  0; i < n; i++) {
    ans += abs(a[i][0] - a[i][1]);
  }


  cout << ans << "\n";
}

int32_t main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0); cout.tie(0);

  int tt = 1; cin >> tt;
  for (int t_ = 1; t_ <= tt; t_++) {
    solve();
  }

  return 0;
}
