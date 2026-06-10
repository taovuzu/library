// कर्मण्येवाधिकारस्ते मा फलेषु कदाचन ।
// मा कर्मफलहेतुर्भूर्मा ते सङ्गोऽस्त्वकर्मणि ॥
// नीरसतां परिश्रमं च आलिंगयन्तु, केवलं अदम्य-अनुशासनेन 
// एव निपुणता सच्चिदानन्दस्य ब्रह्माण्डस्य तालान् उद्घाटयति। || (iii-iv hr)
#include <bits/stdc++.h>

using namespace std;

#define int long long

#ifdef LOCAL
#include "pr.h"
#else
#define pr(...) {}
#define debarr(a, n) {}
#define debmat(mat, row, col) {}
#endif

void solve() {
  int n, m;
  cin >> n >> m;

  vector a(n, vector<int> (m));
  vector<int> pre(m);
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      cin >> a[i][j];
      pre[j] += a[i][j];
    }
  }

  int sum = accumulate(pre.begin(), pre.end(), 0LL);
  int l = sum / 2, i = 0, j = 0, curr = 0, tmp = 0;
  int ans = l * ((sum + 1) / 2);
  string s = "";

  while (j < m && curr + pre[j] <= l) {
    s += "R";
    curr += pre[j];
    j++;
  }
  if (j < m) {
    while (i < n && pre[j] + curr - tmp > l) {
      s += "D";
      tmp += a[i][j];
      i++;
    }

    s += "R";
    j++;
  }

  while (i < n) {
    s += "D";
    i++;
  }
  while (j < m) {
    s += "R";
    j++;
  }

  cout << ans << "\n" << s << "\n";
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
