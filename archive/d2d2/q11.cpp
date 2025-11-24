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

int n;
int nc4(int x) {
  return x * (x - 1) * (x - 2) * (x - 3) / 24;
}

void solve() {
  vector<int> a(n), b(10010), u(10010);
  for (int i = 0; i < n; i++) {
    cin >> a[i];
    b[a[i]]++;
  }
  int ans = 0, maxi = *max_element(a.begin(), a.end());
  for (int i = maxi; i > 1; i--) {
    int cnt = 0;
    for (int j = i; j <= maxi; j += i) cnt += b[j];
    u[i] += nc4(cnt);
    ans += u[i];
    for (int j = 2; j * j <= i; j++) {
      if (i % j) continue;
      u[j] -= u[i];
      if (j * j != i) u[i / j] -= u[i];
    }
  }
  cout << nc4(n) - ans << "\n";
}

int32_t main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0); cout.tie(0);

  while (cin >> n) {
    solve();
  }

  return 0;
}
