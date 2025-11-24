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

const int MAXN = 100100;

void solve() {
  int n, sum = 0, ans = LLONG_MAX, idx = 0, idx2 = 0;
  cin >> n;

  vector<array<int, 2>> a(n);
  vector<int> b(205);
  for (int i = 0; i < n; i++) {
    cin >> a[i][0];
  }
  for (int i = 0; i < n; i++) {
    cin >> a[i][1];
    b[a[i][1]]++;
  }

  sort(a.rbegin(), a.rend());
  while (idx < n) {
    while (idx2 < n && a[idx][0] == a[idx2][0]) b[a[idx2][1]]--, idx2++;
    int p = (n - idx2) - (idx2 - idx - 1), i = 0, cost = sum;
    while (p > 0) {
      int x = min(p, b[i]);
      cost += x * i, p -= x, i++;
    }
    ans = min(ans, cost);
    while (idx < idx2) sum += a[idx][1], idx++;
  }
  cout << ans << "\n";
}

int32_t main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0); cout.tie(0);

  solve();

  return 0;
}
